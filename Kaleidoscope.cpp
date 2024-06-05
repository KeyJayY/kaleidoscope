#include "Kaleidoscope.h"
struct AxisIterator {
    class iterator {
        int _i = 0;
        double _phi = 0;
        double _dphi;

       public:
        iterator(int axis, int i = 0) : _dphi(180. / axis), _i(i) {}
        iterator& operator++() {
            _phi = _dphi * (++_i);
            return *this;
        }
        bool operator==(iterator other) const { return _i == other._i; }
        bool operator!=(iterator other) const { return !(*this == other); }
        double operator*() { return _phi; }
    };
    int _axis;
    AxisIterator(int axis) : _axis(axis) {}

   public:
    iterator begin() { return iterator(_axis, 0); }
    iterator end() { return iterator(_axis, _axis); }
};

wxImage RotateImageLinear(const wxImage& source, double angleDegrees) {
    const double angleRadians = wxDegToRad(angleDegrees);
    int width = source.GetWidth();
    int height = source.GetHeight();

    wxImage result(width, height);
    result.InitAlpha();

    unsigned char* srcData = source.GetData();
    unsigned char* dstData = result.GetData();

    int centerX = width / 2;
    int centerY = height / 2;

#pragma omp parallel for
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int srcX = int(cos(angleRadians) * (x - centerX) +
                           sin(angleRadians) * (y - centerY) + centerX);
            int srcY = int(-sin(angleRadians) * (x - centerX) +
                           cos(angleRadians) * (y - centerY) + centerY);
            if (srcX < 0) srcX = -srcX;
            if (srcY < 0) srcY = -srcY;
            if (srcX >= width) srcX = 2 * width - srcX - 1;
            if (srcY >= height) srcY = 2 * height - srcY - 1;

            int srcIndex = (srcY * width + srcX) * 3;
            int dstIndex = (y * width + x) * 3;

            dstData[dstIndex] = srcData[srcIndex];
            dstData[dstIndex + 1] = srcData[srcIndex + 1];
            dstData[dstIndex + 2] = srcData[srcIndex + 2];
        }
    }
    return result;
}

float cubicInterpolate(float p[4], float x) {
    return p[1] + 0.5 * x *
                      (p[2] - p[0] +
                       x * (2.0 * p[0] - 5.0 * p[1] + 4.0 * p[2] - p[3] +
                            x * (3.0 * (p[1] - p[2]) + p[3] - p[0])));
}

float bicubicInterpolate(float patch[4][4], float x, float y) {
    float arr[4];
    for (int i = 0; i < 4; i++) {
        arr[i] = cubicInterpolate(patch[i], x);
    }
    return cubicInterpolate(arr, y);
}

wxImage MirrorRightHalf(const wxImage& source) {
    const int width = source.GetWidth();
    const int height = source.GetHeight();
    wxImage result(source);

    unsigned char* srcData = source.GetData();
    unsigned char* resultData = result.GetData();

#pragma omp parallel for
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            int srcX = width - 1 - x;
            int srcPos = (y * width + srcX) * 3;
            int dstPos = (y * width + x) * 3;

            resultData[dstPos] = srcData[srcPos];
            resultData[dstPos + 1] = srcData[srcPos + 1];
            resultData[dstPos + 2] = srcData[srcPos + 2];
        }
    }
    return result;
}

wxImage RotateImageCubic(const wxImage& source, double angleDegrees) {
    const double angleRadians = -wxDegToRad(angleDegrees);
    int width = source.GetWidth();
    int height = source.GetHeight();

    wxImage result(width, width);
    result.InitAlpha();

    unsigned char* srcData = source.GetData();
    unsigned char* dstData = result.GetData();

#pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            double dx = (x - width / 2);
            double dy = (y - height / 2);
            double srcX =
                cos(angleRadians) * dx - sin(angleRadians) * dy + width / 2;
            double srcY =
                sin(angleRadians) * dx + cos(angleRadians) * dy + height / 2;

            int ix = (int)floor(srcX);
            int iy = (int)floor(srcY);
            float fx = srcX - ix;
            float fy = srcY - iy;

            if (ix < 1) ix = 1 - ix;
            if (ix >= width - 2) ix = 2 * (width - 2) - ix - 2;
            if (iy < 1) iy = 1 - iy;
            if (iy >= height - 2) iy = 2 * (height - 2) - iy - 2;

            float patch[3][4][4];
            for (int c = 0; c < 3; c++) {
                for (int j = -1; j <= 2; j++) {
                    for (int i = -1; i <= 2; i++) {
                        int pos = ((iy + j) * width + (ix + i)) * 3 + c;
                        patch[c][j + 1][i + 1] = srcData[pos];
                    }
                }
            }
            float red = bicubicInterpolate(patch[0], fx, fy);
            float green = bicubicInterpolate(patch[1], fx, fy);
            float blue = bicubicInterpolate(patch[2], fx, fy);

            int dstIndex = (y * width + x) * 3;
            dstData[dstIndex] = std::min(std::max(int(red), 0), 255);
            dstData[dstIndex + 1] = std::min(std::max(int(green), 0), 255);
            dstData[dstIndex + 2] = std::min(std::max(int(blue), 0), 255);
            result.SetAlpha(x, y, 255);
        }
    }
    return result;
}

void Kaleidoscope::syncResize() {
    resized_image = original_image.Copy();
    resized_image.Rescale(side, side, wxIMAGE_QUALITY_HIGH);
}

void Kaleidoscope::syncTranslate() {
    // first translate, then crop, then rescale?
    int tx = side * translate_x;
    int ty = side * translate_y;

    translated_image = wxImage(resized_image.GetSize(), false);
    unsigned char* original = resized_image.GetData();
    unsigned char* transformed = translated_image.GetData();

#pragma omp parallel for
    for (int yo = 0; yo < side; yo++) {
        for (int xo = 0; xo < side; xo++) {
            int x = xo + tx, y = yo + ty;

            if (0 > x || x >= side)
                if (tx >= 0)
                    x = 2 * side - x - 1;
                else
                    x = -x - 1;

            if (0 > y || y >= side)
                if (ty >= 0)
                    y = 2 * side - y - 1;
                else
                    y = -y - 1;

            int i = yo * side + xo, j = y * side + x;
            for (int k = 0; k < 3; ++k)
                transformed[i * 3 + k] = original[j * 3 + k];
        }
    }
}

std::map<Kaleidoscope::InterpolationMethod,
         std::function<wxImage(const wxImage&, double)>>
    rotateFuncs = {{Kaleidoscope::LINEAR, RotateImageLinear},
                   {Kaleidoscope::CUBIC, RotateImageCubic}};

void Kaleidoscope::syncGenerate() {
    auto rotateFunc = rotateFuncs[interpolation];
    generated_image = translated_image.Copy();
    generated_image = rotateFunc(generated_image, angle);
    for (auto phi : AxisIterator(axis)) {
        generated_image = rotateFunc(generated_image, phi);
        MirrorRightHalf(generated_image);
        generated_image = rotateFunc(generated_image, -phi);
    }
    generated_image = rotateFunc(generated_image, -angle);
}

void Kaleidoscope::syncAxis() {
    wxMemoryDC dc(generated_bitmap);
    dc.SetPen(*wxBLACK_PEN);
    for (auto phi : AxisIterator(axis)) {
        phi = -phi - angle;
        dc.DrawLine(cos(wxDegToRad(phi + 90)) * side + side / 2.0,
                    sin(wxDegToRad(phi + 90)) * side + side / 2.0,
                    cos(wxDegToRad(phi - 90)) * side + side / 2.0,
                    sin(wxDegToRad(phi - 90)) * side + side / 2.0);
    }
    generated_image = generated_bitmap.ConvertToImage();
}

void Kaleidoscope::setCacheState(Kaleidoscope::CacheState state) {
    if (state < cache_state) cache_state = state;
}

void Kaleidoscope::updateCache(bool onlyImage) {
    auto t0 = std::chrono::high_resolution_clock::now();

    switch (cache_state) {
        case NO_IMAGE:
            return;
        case RESIZE:
            syncResize();
        case TRANSLATE:
            syncTranslate();
        case GENERATE:
            syncGenerate();
            cache_state = BITMAP;
        case BITMAP:
            if (onlyImage && !draw_axis) break;
            generated_bitmap = wxBitmap(generated_image);
            if (draw_axis) syncAxis();
            cache_state = FULL;
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    lastUpdateTimeMillis =
        std::chrono::duration<double, std::milli>(t1 - t0).count();
}

void Kaleidoscope::resetParameters() {
    translate_x = translate_y = axis = angle = 0;
    setCacheState(RESIZE);
}

void Kaleidoscope::setSide(double n_side) {
    if (side == n_side) return;
    side = n_side;
    setCacheState(RESIZE);
}

void Kaleidoscope::setTranslateX(double n_translate_x) {
    if (translate_x == n_translate_x) return;
    translate_x = n_translate_x;
    setCacheState(TRANSLATE);
}

void Kaleidoscope::setTranslateY(double n_translate_y) {
    if (translate_y == n_translate_y) return;
    translate_y = n_translate_y;
    setCacheState(TRANSLATE);
}

void Kaleidoscope::setDrawAxis(bool n_draw_axis) {
    if (draw_axis == n_draw_axis) return;
    draw_axis = n_draw_axis;
    setCacheState(GENERATE);
}

void Kaleidoscope::setAxis(int n_axis) {
    if (axis == n_axis) return;
    axis = n_axis;
    setCacheState(GENERATE);
}

void Kaleidoscope::setAngle(double n_angle) {
    if (angle == n_angle) return;
    angle = n_angle;
    setCacheState(GENERATE);
}

void Kaleidoscope::setInterpolation(
    Kaleidoscope::InterpolationMethod n_interpolation) {
    if (interpolation == n_interpolation) return;
    interpolation = n_interpolation;
    setCacheState(GENERATE);
}

void Kaleidoscope::setImage(const wxImage img) {
    original_image = img;
    cache_state = RESIZE;
}

bool Kaleidoscope::isImageLoaded() { return original_image.IsOk(); }
const wxImage& Kaleidoscope::getImage() {
    updateCache(true);
    return generated_image;
}

const wxBitmap& Kaleidoscope::getBitmap() {
    updateCache(false);
    return generated_bitmap;
}

double Kaleidoscope::getLastUpdateMillis() { return lastUpdateTimeMillis; }
