cmake_minimum_required(VERSION 3.30)
project(sakarya C)

add_library(sakarya)

set_target_properties(sakarya PROPERTIES
    C_STANDARD 23
    C_STANDARD_REQUIRED on
    C_EXTENSIONS on
    INTERPROCEDURAL_OPTIMIZATION on
)

target_compile_options(sakarya PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

set(BUILD_SHARED_LIBS off)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    target_sources(sakarya PRIVATE
        sources/windows.c
    )
    target_compile_definitions(sakarya PRIVATE
        _CRT_SECURE_NO_WARNINGS
        UNICODE
        VS_EXTRALEAN
        WIN32_LEAN_AND_MEAN
        NOGDICAPMASKS
        NOVIRTUALKEYCODES
        NOWINMESSAGES
        NOWINSTYLES
        NOSYSMETRICS
        NOMENUS
        NOICONS
        NOKEYSTATES
        NOSYSCOMMANDS
        NORASTEROPS
        NOSHOWWINDOW
        OEMRESOURCE
        NOATOM
        NOCLIPBOARD
        NOCOLOR
        NOCTLMGR
        NODRAWTEXT
        NOGDI
        NOKERNEL
        NOUSER
        NONLS
        NOMB
        NOMEMMGR
        NOMETAFILE
        NOMINMAX
        NOMSG
        NOOPENFILE
        NOSCROLL
        NOSERVICE
        NOSOUND
        NOTEXTMETRIC
        NOWH
        NOWINOFFSETS
        NOCOMM
        NOKANJI
        NOHELP
        NOPROFILER
        NODEFERWINDOWPOS
        NOMCX
    )
else()
    message(FATAL_ERROR "Unsupported platform " ${CMAKE_SYSTEM_NAME})
endif()
