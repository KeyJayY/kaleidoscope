set -x
mkdir build
cd build
cmake ..
make
curl 'https://images.pexels.com/photos/3125171/pexels-photo-3125171.jpeg?cs=srgb&dl=pexels-sanaan-3125171.jpg&fm=jpg&h=3000&w=3000&fit=crop' -o test.jpg
# ./Kaleidoscope
{ set +x; } 2>/dev/null
