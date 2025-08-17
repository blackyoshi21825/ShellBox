@echo off
echo Building Shell Box...
make shellbox
if %errorlevel% neq 0 (
    echo Build failed!
    pause
    exit /b 1
)
echo.
echo Starting Shell Box Terminal...
echo.
make shellbox