@echo off
echo AppwriteSDK Windows Build
echo ========================

:: Create build directory
if not exist "build" mkdir build
cd build

:: Install dependencies
echo Installing dependencies with Conan...
conan install .. --build=missing -s build_type=Release

:: Configure using Conan toolchain
echo Configuring with CMake using Conan toolchain...
cmake .. -G "MinGW Makefiles" ^
    -DCMAKE_TOOLCHAIN_FILE=generators/conan_toolchain.cmake ^
    -DCMAKE_BUILD_TYPE=Release

if %errorlevel% neq 0 (
    echo Configuration failed. Check the error messages above.
    pause
    exit /b 1
)

echo Building...
cmake --build . --config Release

if %errorlevel% equ 0 (
    echo Build successful!
    echo Proceeding with installation...
    cd ..
    call install_windows.bat
) else (
    echo Build failed. Check the error messages above.
    pause
)
