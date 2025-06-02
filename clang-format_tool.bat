@echo off
setlocal enabledelayedexpansion

REM 指定 clang-format 的路径
set CLANG_FORMAT_PATH=D:\\application\\MSYS2\\mingw64\\bin\\clang-format.exe

REM 指定需要格式化的文件类型
set FILE_TYPES=*.cpp *.h *.cc *.hpp

REM 指定根目录，默认为当前目录
set DIRECTORY=%CD%

REM 检查 clang-format 是否存在
if not exist "%CLANG_FORMAT_PATH%" (
    echo 无法找到 clang-format，请检查路径是否正确。
    goto :EOF
)

REM 遍历目录及其子目录中的所有指定类型的文件
for /r "%DIRECTORY%" %%f in (%FILE_TYPES%) do (
    call :format_file "%%f"
)

:end
echo all files has been formated with clang-format
pause
exit /b

:format_file
%CLANG_FORMAT_PATH% -i "%~1" -style=Google
@REM echo 已格式化文件：%~1
echo file has been formated :%~1
exit /b