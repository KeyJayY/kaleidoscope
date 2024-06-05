#pragma once
#include <wx/dcbuffer.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/wx.h>

#include <chrono>
#include <map>
struct Kaleidoscope {
    enum InterpolationMethod { LINEAR, CUBIC };

   private:
    /// it describes the first step that should be repeated
    enum CacheState {
        NO_IMAGE,
        RESIZE,
        TRANSLATE,
        GENERATE,  // rotation and axis
        BITMAP,
        FULL
    } cache_state;
    int side = 500;
    /// -1..1
    double translate_x = 0;
    /// -1..1
    double translate_y = 0;
    bool draw_axis = true;
    int axis = 0;
    double angle = 0;
    InterpolationMethod interpolation = LINEAR;
    wxImage original_image;
    wxImage resized_image;
    wxImage translated_image;
    wxImage generated_image;
    wxBitmap generated_bitmap;
    void syncResize();
    void syncTranslate();
    void syncGenerate();
    void syncAxis();
    void setCacheState(CacheState state);
    void updateCache(bool onlyImage = false);
    double lastUpdateTimeMillis;

   public:
    void resetParameters();
    void setSide(double n_side);
    void setTranslateX(double n_translate_x);
    void setTranslateY(double n_translate_y);
    void setDrawAxis(bool n_draw_axis);
    void setAxis(int n_axis);
    void setAngle(double n_angle);
    void setInterpolation(InterpolationMethod n_interpolation);
    void setImage(const wxImage img);

    bool isImageLoaded();
    const wxImage& getImage();
    const wxBitmap& getBitmap();
    double getLastUpdateMillis();
};
