@echo off

cmake^
    "-DCMAKE_BUILD_TYPE:STRING=Release"^
    "-DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE"^
    "-DCMAKE_C_COMPILER:FILEPATH=clang"^
    -S %~dp0^
    -B "%~dp0build"^
    -G "Ninja"^
