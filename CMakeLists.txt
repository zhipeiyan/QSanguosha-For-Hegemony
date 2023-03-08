cmake_minimum_required(VERSION 3.23)
project(QSanguosha)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS widgets network REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#if (NOT EXISTS swig/sanguosha_wrap.cxx)
#    execute_process(COMMAND tools/swigwin-4.1.1/swig.exe -c++ -lua swig/sanguosha.i
#            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
#endif ()

set(SOURCES src/main.cpp
        src/client/aux-skills.cpp
        src/client/client.cpp
        src/client/clientplayer.cpp
        src/client/clientstruct.cpp
        src/core/banpair.cpp
        src/core/card.cpp
        src/core/engine.cpp
        src/core/general.cpp
        src/core/lua-wrapper.cpp
        src/core/player.cpp
        src/core/protocol.cpp
        src/core/record-analysis.cpp
        src/core/roomstate.cpp
        src/core/settings.cpp
        src/core/skill.cpp
        src/core/structs.cpp
        src/core/util.cpp
        src/core/wrappedcard.cpp
        src/core/version.cpp
        src/core/json.cpp
        src/dialog/aboutus.cpp
        src/dialog/cardeditor.cpp
        src/dialog/cardoverview.cpp
        src/dialog/configdialog.cpp
        src/dialog/connectiondialog.cpp
        src/dialog/customassigndialog.cpp
        src/dialog/distanceviewdialog.cpp
        src/dialog/freechoosedialog.cpp
        src/dialog/generaloverview.cpp
        src/dialog/mainwindow.cpp
        src/dialog/rule-summary.cpp
        src/dialog/updatechecker.cpp
        src/dialog/udpdetectordialog.cpp
        src/dialog/avatarmodel.cpp
        src/dialog/generalmodel.cpp
        src/dialog/serverdialog.cpp
        src/dialog/flatdialog.cpp
        src/dialog/banipdialog.cpp
        src/dialog/banlistdialog.cpp
        src/package/exppattern.cpp
        src/package/formation.cpp
        src/package/jiange-defense.cpp
        src/package/momentum.cpp
        src/package/standard.cpp
        src/package/standard-basics.cpp
        src/package/standard-equips.cpp
        src/package/standard-tricks.cpp
        src/package/standard-qun-generals.cpp
        src/package/standard-shu-generals.cpp
        src/package/standard-wu-generals.cpp
        src/package/standard-wei-generals.cpp
        src/package/standard-package.cpp
        src/package/strategic-advantage.cpp
        src/package/package.cpp
        src/scenario/miniscenarios.cpp
        src/scenario/scenario.cpp
        src/scenario/scenerule.cpp
        src/scenario/jiange-defense-scenario.cpp
        src/server/ai.cpp
        src/server/gamerule.cpp
        src/server/generalselector.cpp
        src/server/room.cpp
        src/server/roomthread.cpp
        src/server/server.cpp
        src/server/serverplayer.cpp
        src/ui/button.cpp
        src/ui/cardcontainer.cpp
        src/ui/carditem.cpp
        src/ui/chatwidget.cpp
        src/ui/choosegeneralbox.cpp
        src/ui/clientlogbox.cpp
        src/ui/dashboard.cpp
        src/ui/genericcardcontainerui.cpp
        src/ui/indicatoritem.cpp
        src/ui/magatamasitem.cpp
        src/ui/photo.cpp
        src/ui/pixmapanimation.cpp
        src/ui/qsanbutton.cpp
        src/ui/qsanselectableitem.cpp
        src/ui/rolecombobox.cpp
        src/ui/roomscene.cpp
        src/ui/skinbank.cpp
        src/ui/sprite.cpp
        src/ui/startscene.cpp
        src/ui/tablepile.cpp
        src/ui/timedprogressbar.cpp
        src/ui/uiutils.cpp
        src/ui/window.cpp
        src/ui/chooseoptionsbox.cpp
        src/ui/choosetriggerorderbox.cpp
        src/ui/graphicsbox.cpp
        src/ui/guanxingbox.cpp
        src/ui/title.cpp
        src/ui/bubblechatbox.cpp
        src/ui/stylehelper.cpp
        src/ui/playercardbox.cpp
        src/ui/graphicspixmaphoveritem.cpp
        src/ui/heroskincontainer.cpp
        src/ui/skinitem.cpp
        src/ui/tile.cpp
        src/ui/choosesuitbox.cpp
        src/util/detector.cpp
        src/util/nativesocket.cpp
        src/util/recorder.cpp
        swig/sanguosha_wrap.cxx
        src/ui/guhuobox.cpp
        src/ui/cardchoosebox.cpp
        src/package/transformation.cpp
        src/ui/lightboxanimation.cpp
        src/ui/pindianbox.cpp
        src/core/audio.cpp)

set(HEADERS src/client/aux-skills.h
        src/client/client.h
        src/client/clientplayer.h
        src/client/clientstruct.h
        src/core/audio.h
        src/core/banpair.h
        src/core/card.h
        src/core/compiler-specific.h
        src/core/engine.h
        src/core/general.h
        src/core/lua-wrapper.h
        src/core/namespace.h
        src/core/player.h
        src/core/protocol.h
        src/core/record-analysis.h
        src/core/roomstate.h
        src/core/settings.h
        src/core/skill.h
        src/core/structs.h
        src/core/util.h
        src/core/wrappedcard.h
        src/core/version.h
        src/core/json.h
        src/dialog/aboutus.h
        src/dialog/cardeditor.h
        src/dialog/cardoverview.h
        src/dialog/configdialog.h
        src/dialog/connectiondialog.h
        src/dialog/customassigndialog.h
        src/dialog/distanceviewdialog.h
        src/dialog/freechoosedialog.h
        src/dialog/generaloverview.h
        src/dialog/mainwindow.h
        src/dialog/rule-summary.h
        src/dialog/updatechecker.h
        src/dialog/udpdetectordialog.h
        src/dialog/avatarmodel.h
        src/dialog/generalmodel.h
        src/dialog/serverdialog.h
        src/dialog/flatdialog.h
        src/dialog/banipdialog.h
        src/dialog/banlistdialog.h
        src/package/exppattern.h
        src/package/formation.h
        src/package/jiange-defense.h
        src/package/momentum.h
        src/package/package.h
        src/package/standard.h
        src/package/standard-basics.h
        src/package/standard-equips.h
        src/package/standard-tricks.h
        src/package/standard-qun-generals.h
        src/package/standard-shu-generals.h
        src/package/standard-wu-generals.h
        src/package/standard-wei-generals.h
        src/package/strategic-advantage.h
        src/package/standard-package.h
        src/scenario/miniscenarios.h
        src/scenario/scenario.h
        src/scenario/scenerule.h
        src/scenario/jiange-defense-scenario.h
        src/server/ai.h
        src/server/gamerule.h
        src/server/generalselector.h
        src/server/room.h
        src/server/roomthread.h
        src/server/server.h
        src/server/serverplayer.h
        src/ui/button.h
        src/ui/cardcontainer.h
        src/ui/carditem.h
        src/ui/chatwidget.h
        src/ui/choosegeneralbox.h
        src/ui/clientlogbox.h
        src/ui/dashboard.h
        src/ui/genericcardcontainerui.h
        src/ui/indicatoritem.h
        src/ui/magatamasitem.h
        src/ui/photo.h
        src/ui/pixmapanimation.h
        src/ui/qsanbutton.h
        src/ui/qsanselectableitem.h
        src/ui/rolecombobox.h
        src/ui/roomscene.h
        src/ui/skinbank.h
        src/ui/sprite.h
        src/ui/startscene.h
        src/ui/tablepile.h
        src/ui/timedprogressbar.h
        src/ui/uiutils.h
        src/ui/window.h
        src/ui/chooseoptionsbox.h
        src/ui/choosetriggerorderbox.h
        src/ui/graphicsbox.h
        src/ui/guanxingbox.h
        src/ui/title.h
        src/ui/bubblechatbox.h
        src/ui/stylehelper.h
        src/ui/playercardbox.h
        src/ui/graphicspixmaphoveritem.h
        src/ui/heroskincontainer.h
        src/ui/skinitem.h
        src/ui/tile.h
        src/ui/choosesuitbox.h
        src/util/detector.h
        src/util/nativesocket.h
        src/util/recorder.h
        src/util/socket.h
        src/ui/guhuobox.h
        src/ui/cardchoosebox.h
        src/package/transformation.h
        src/ui/lightboxanimation.h
        src/ui/pindianbox.h)

set(FORMS src/dialog/cardoverview.ui
        src/dialog/configdialog.ui
        src/dialog/connectiondialog.ui
        src/dialog/generaloverview.ui)

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    list(APPEND FORMS src/dialog/mainwindow.ui)
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
    list(APPEND FORMS src/dialog/mainwindow.ui)
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    list(APPEND FORMS src/dialog/mainwindow_nonwin.ui)
endif ()

set(INCLUDEPATH
        src/client
        src/core
        src/dialog
        src/package
        src/scenario
        src/server
        src/ui
        src/util)

set(OTHER_FILES
        ui-script/animation.qml
        builds/sanguosha.ts)

add_compile_definitions(AUDIO_SUPPORT GPP)

add_subdirectory(3rd-party/freetype-2.9)
add_subdirectory(3rd-party/lua-5.4.4)
if (CMAKE_BUILD_TYPE MATCHES "Debug")
    set(FMNAME "fmodexL")
else()
    set(FMNAME "fmodex")
endif ()
if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(LIBOS "win")
    if (MINGW)
        set(LIBARCH "MinGW")
    elseif(CMAKE_VS_PLATFORM_NAME MATCHES "Win32")
        set(LIBARCH "x86")
    else()
        set(LIBARCH "x64")
    endif()
    set(LIBNAME "${FMNAME}.lib")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(LIBOS "linux")
    set(LIBARCH "x64")
    set(LIBNAME "lib${FMNAME}.so")
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(LIBOS "mac")
    set(LIBARCH "lib")
    set(LIBNAME "lib${FMNAME}.dylib")
endif()
add_library(fmodex STATIC IMPORTED)
set_target_properties(fmodex PROPERTIES
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/3rd-party/fmodex/lib/${LIBOS}/${LIBARCH}/${LIBNAME}
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/3rd-party/fmodex/include)

add_executable(QSanguosha ${SOURCES} ${HEADERS} ${FORMS} ${OTHER_FILES})
target_include_directories(QSanguosha PRIVATE ${INCLUDEPATH} ${CMAKE_SOURCE_DIR}/3rd-party/freetype-2.9/include)
target_link_libraries(QSanguosha Qt5::Widgets Qt5::Network lua freetype fmodex)
add_dependencies(QSanguosha lua freetype fmodex)