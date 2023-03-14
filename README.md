Open Source Sanguosha
==========

| Homepage:      | http://qsanguosha.org (dead)                            |
|----------------|---------------------------------------------------------|
| API reference: | http://gaodayihao.github.com/QSanguosha/api             |
| Documentation: | https://github.com/gaodayihao/QSanguosha/wiki (Chinese) |

Third party evaluations of development process
---------
[![Code Climate](https://codeclimate.com/github/QSanguosha-Rara/QSanguosha-For-Hegemony.png)](https://codeclimate.com/github/QSanguosha-Rara/QSanguosha-For-Hegemony) 

[![Issue Stats](http://issuestats.com/github/QSanguosha/QSanguosha-For-Hegemony/badge/pr?style=flat)](http://issuestats.com/github/QSanguosha/QSanguosha-For-Hegemony)

[![Issue Stats](http://issuestats.com/github/QSanguosha/QSanguosha-For-Hegemony/badge/issue?style=flat)](http://issuestats.com/github/QSanguosha/QSanguosha-For-Hegemony)

License
------------
### Code
This game is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 3.0
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

See the LICENSE file for more details.

### Material
Our Materials are under the terms of the Creative Commons
Attribution-NonCommercial-NoDerivatives 4.0 International (CC
BY-NC-ND 4.0)

**You are free to:**

Share — copy and redistribute the material in any medium or format

**Under the following terms:**

Attribution — You must give appropriate credit, provide a link to
the license, and indicate if changes were made. You may do so in
any reasonable manner, but not in any way that suggests the licensor
endorses you or your use.

NonCommercial — You may not use the material for commercial purposes.

NoDerivatives — If you remix, transform, or build upon the material,
you may not distribute the modified material.

See the CC BY-NC-ND 4.0 file for more details.

Introduction
----------

Sanguosha is both a popular board game and online game,
this project try to clone the Sanguosha online version.
The whole project is written in C++,
using Qt's graphics view framework as the game engine.
I've tried many other open source game engines,
such as SDL, HGE, Clanlib and others,
but many of them lack some important features.
Although Qt is an application framework instead of a game engine,
its graphics view framework is suitable for my game developing. By Moligaloo

Features
----------

1. Framework
    * Open source with Qt graphics view framework
    * Use FMOD as sound engine
    * Use Freetype in Font Rendering
    * Use Lua as AI and extension script

2. Operation experience
    * Full package (include all yoka extension package)
    * Keyboard shortcut
    * Double-click to use cards
    * Cards sorting (by card type and card suit)
    * Multilayer display when cards are more than an upper-limit

3. Extensible
    * Some MODs are available based on this game
    * Lua Packages are supported in this game

HOW TO BUILD
=========
This repo is forked by Zhipei Yan and the mod is now managed by CMake rather than QMake.

Windows/Linux/Mac are supported. Temporarily removed support for iOS/android/WinRT

Dependency
----------
The source code will need `Qt5`, `lua`, `freetype`, `fmod`, `vld` libs.
1. Install your toolchain: 
   * Debian: `apt install build-essential gdb` 
   * Mac: install Xcode and Xcode commandline tools
   * Windows: install MSVC or MinGW
2. Install your dev environment:
   * CLion (recommended), VSCode, Visual Studio, Xcode, or etc.
   * If your IDE does not have CMake integrated, install CMake
3. Install Qt5 (qtcreator is not required):
   * Debian: `apt install qtbase5-dev qtchooser qttools5-dev-tools`
   * Windows/Mac: https://www.qt.io/download-qt-installer
4. Install other dependencies, binaries of `fmod` are included in the repo
   * Debian: `apt install liblua5.4-dev libfreetype-dev`
   * Mac: `brew install lua freetype`
   * Windows: libs included in the repo

Build
-----
1. Use your IDE or cmake to open `CMakeLists.txt` and configure the project
2. [Windows only] Change the path of Qt in `CMakeLists.txt` to your installation path
3. Change "Working Directory" to the root folder of the repo in your IDE
4. [Windows only] Copy runtime libs, [?] is the debug suffix:
   * Copy `Qt5Core[d].dll, Qt5Gui[d].dll, Qt5Network[d].dll, Qt5Widgets[d].dll` from your Qt installation to the root folder of the repo
   * Copy `fmod[L].dll, freetype.dll and vlx_x64.dll` from the 3rd-party to the root folder of the repo
   * Copy `qwindows[d].dll` from `${QT_DIR}/plugins/platforms` to **${path_to_your_built_qsanguosha.exe}/platforms/qwindows[d].dll**
5. Build and run the game.

Release
-------
//TODO