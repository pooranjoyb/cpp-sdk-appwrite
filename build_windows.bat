@echo off
echo AppwriteSDK Windows Build (Fixed)
echo =================================

:: Ensure MinGW is in PATH
where gcc >nul 2>&1
if %errorlevel% neq 0 (
    echo Error: GCC not found. Ensure MinGW is in your PATH.
    pause
    exit /b 1
)

:: Clean build directory
if exist "build" rmdir /s /q "build"
mkdir build
cd build

:: Install dependencies with explicit output folder
echo Installing dependencies with Conan...
conan install .. --output-folder=. --build=missing -s build_type=Release

:: Verify toolchain file was created
if exist "conan_toolchain.cmake" (
    echo ✅ Found conan_toolchain.cmake
    set "TOOLCHAIN_FILE=conan_toolchain.cmake"
) else (
    echo ❌ conan_toolchain.cmake not found, listing build contents:
    dir /b
    echo Trying without toolchain file...
    set "TOOLCHAIN_FILE="
)

:: Configure with CMake
echo Configuring with CMake...
if defined TOOLCHAIN_FILE (
    cmake .. -G "MinGW Makefiles" -DCMAKE_TOOLCHAIN_FILE=%TOOLCHAIN_FILE% -DCMAKE_BUILD_TYPE=Release
) else (
    cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
)

if %errorlevel% neq 0 (
    echo ❌ CMake configuration failed
    pause
    exit /b 1
)

:: Build
echo Building...
cmake --build . --config Release

if %errorlevel% equ 0 (
    echo ✅ Build successful!
    cd ..
    call install_windows.bat
) else (
    echo ❌ Build failed
    pause
)
