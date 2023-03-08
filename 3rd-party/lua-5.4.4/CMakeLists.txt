# A simple CMakeLists.txt for lua 5.4.4
# Zhipei Yan
# 03/07/2023

cmake_minimum_required(VERSION 3.23)
project(lua)

set(CMAKE_CXX_STANDARD 11)

set(VERSION_MAJOR "5")
set(VERSION_MINOR "4")
set(VERSION_PATCH "4")
set(PROJECT_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(SHARED_LIBRARY_VERSION ${VERSION_MAJOR}.${VERSION_MINOR})

set(SOURCES src/lzio.c
        src/lvm.c
        src/lutf8lib.c
        src/lundump.c
        src/luac.c
        src/lua.c
        src/ltm.c
        src/ltablib.c
        src/ltable.c
        src/lstrlib.c
        src/lstring.c
        src/lstate.c
        src/lparser.c
        src/loslib.c
        src/lopcodes.c
        src/lobject.c
        src/loadlib.c
        src/lmem.c
        src/lmathlib.c
        src/llex.c
        src/liolib.c
        src/linit.c
        src/lgc.c
        src/lfunc.c
        src/ldump.c
        src/ldo.c
        src/ldebug.c
        src/ldblib.c
        src/lctype.c
        src/lcorolib.c
        src/lcode.c
        src/lbaselib.c
        src/lauxlib.c
        src/lapi.c)

set(HEADERS src/lzio.h
        src/lvm.h
        src/lundump.h
        src/lualib.h
        src/luaconf.h
        src/lua.hpp
        src/lua.h
        src/ltm.h
        src/ltable.h
        src/lstring.h
        src/lstate.h
        src/lprefix.h
        src/lparser.h
        src/lopnames.h
        src/lopcodes.h
        src/lobject.h
        src/lmem.h
        src/llimits.h
        src/llex.h
        src/ljumptab.h
        src/lgc.h
        src/lfunc.h
        src/ldo.h
        src/ldebug.h
        src/lctype.h
        src/lcode.h
        src/lauxlib.h
        src/lapi.h)

if (NOT DISABLE_FORCE_DEBUG_POSTFIX)
    set(CMAKE_DEBUG_POSTFIX d)
endif()

add_library(lua ${SOURCES} ${HEADERS})
target_include_directories(lua PUBLIC src)