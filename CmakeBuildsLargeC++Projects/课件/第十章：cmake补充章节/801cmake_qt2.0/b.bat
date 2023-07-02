rd /S/Q x64
cmake -S . -B x64 -A x64 -DQT5=J:/Qt/Qt5.14.2/5.14.2/msvc2017_64 -DCMAKE_INSTALL_PREFIX=out 
cmake --build x64 --config Release
cmake --install x64 --config Release

rd /S/Q Win32
cmake -S . -B Win32 -A Win32 -DQT5=J:/Qt/Qt5.14.2/5.14.2/msvc2017 -DCMAKE_INSTALL_PREFIX=out 
cmake --build Win32 --config Release
cmake --install Win32 --config Release