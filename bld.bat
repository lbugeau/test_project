@REM @echo off

rmdir /s /q build
mkdir build
cd build

call "C:\Program Files (x86)\Intel\oneAPI\setvars.bat"

set BUILD_CONFIG=Release

cmake .. -G Ninja ^
    -DCMAKE_INSTALL_PREFIX="." ^
    -DCMAKE_CXX_COMPILER=icx ^
    -DCMAKE_MAKE_PROGRAM=ninja ^
    -DCMAKE_CXX_FLAGS="/Wall /O3 /DNDEBUG /EHsc"

if errorlevel 1 exit 1

cmake --build . --config %BUILD_CONFIG%
if errorlevel 1 exit 1

cd ..
