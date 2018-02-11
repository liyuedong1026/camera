# camera

sudo ./configure -static -fontconfig -release -sql-sqlite -qt-zlib -qt-libpng -qt-libjpeg -nomake tests -qt-xcb -nomake examples -skip qtwebkit -skip wayland -prefix /usr/local/Qt-5.8.0

sudo make
sudo make install