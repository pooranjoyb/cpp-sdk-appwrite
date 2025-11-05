@echo off
echo Installing AppwriteSDK to MinGW directories...

:: Find MinGW installation
for /f "tokens=*" %%i in ('where gcc') do set "GCC_PATH=%%i"
for %%i in ("%GCC_PATH%") do set "MINGW_BIN=%%~dpi"
set "MINGW_ROOT=%MINGW_BIN:~0,-5%"

echo MinGW Root: %MINGW_ROOT%

:: Install headers
set "INCLUDE_DIR=%MINGW_ROOT%\include\AppwriteSDK"
if not exist "%INCLUDE_DIR%" mkdir "%INCLUDE_DIR%"
xcopy /E /I /Y "include\*" "%INCLUDE_DIR%\"

:: Install libraries
copy /Y "build\*.a" "%MINGW_ROOT%\lib\" 2>nul

echo Installation complete!
echo Headers installed to: %INCLUDE_DIR%
echo Libraries installed to: %MINGW_ROOT%\lib\
echo.
echo Test compilation: g++ -o test.exe test.cpp -lAppwriteSDK
pause
