@echo off

set CC=clang
set BIN=binaries
set SRC=sources

rmdir /s /q %BIN%
mkdir %BIN%

%CC% -O3 -o %BIN%/windows.o -c %SRC%/windows.c
