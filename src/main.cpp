/********************************************************************
    Copyright (c) 2013-2015 - Mogara

    This file is part of QSanguosha-Hegemony.

    This game is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 3.0
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    See the LICENSE file for more details.

    Mogara
    *********************************************************************/

#if defined(USE_VLD)
#include <vld.h>
#endif

#include <QFile>
#include <QApplication>
#include <QCommandLineParser>
#include <QTranslator>
#include <QDateTime>
#include <QSplashScreen>

#include "server.h"
#include "settings.h"
#include "engine.h"
#include "mainwindow.h"
#include "audio.h"
#include "stylehelper.h"

#ifndef WINDOWS
#include <QDir>
#endif

#ifdef USE_BREAKPAD
#include <client/windows/handler/exception_handler.h>
#include <QProcess>

using namespace google_breakpad;

static bool callback(const wchar_t *, const wchar_t *id, void *, EXCEPTION_POINTERS *, MDRawAssertionInfo *, bool succeeded)
{
    if (succeeded && QFile::exists("QSanSMTPClient.exe")) {
        char ID[16000];
        memset(ID, 0, sizeof(ID));
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4996)
#endif
        wcstombs(ID, id, wcslen(id));
#ifdef _MSC_VER
#pragma warning(pop)
#endif
        QProcess *process = new QProcess(qApp);
        QStringList args;
        args << QString(ID) + ".dmp";
        process->start("QSanSMTPClient", args);
    }
    return succeeded;
}
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName("QSanguosha");

    QCommandLineParser parser;
    parser.setApplicationDescription("Helper");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOptions({
        // A boolean option with multiple names (-s, --server)
        {{"s", "server"},QApplication::translate("main", "Server mode.")},
        // An option with a value
        {{"c", "connect"},
         QApplication::translate("main", "Connect to server <host-address>."),
         QApplication::translate("main", "host-address")},
    });
    parser.process(app);

    bool serverMode = parser.isSet("server");

    QSplashScreen *splash = nullptr;
    if (!serverMode) {
        QPixmap raraLogo("image/system/developers/logo.png");
        splash = new QSplashScreen(raraLogo);
        splash->show();
        QApplication::processEvents();
    }
    auto showSplashMessage = [serverMode, splash](const QString &message) {
        if (!serverMode) {
            splash->showMessage(message, Qt::AlignBottom | Qt::AlignHCenter, Qt::cyan);
            QApplication::processEvents();
        } else {
            qInfo() << message.toUtf8().constData();
        }
    };

#ifdef USE_BREAKPAD
    showSplashMessage(QSplashScreen::tr("Loading BreakPad..."));
    ExceptionHandler eh(L"./dmp", NULL, callback, NULL, ExceptionHandler::HANDLER_ALL);
#endif

#if defined(Q_OS_MAC) && defined(QT_NO_DEBUG)
    showSplashMessage(QSplashScreen::tr("Setting game path..."));
    QDir::setCurrent(qApp->applicationDirPath());
#endif

#ifdef Q_OS_LINUX
    showSplashMessage(QSplashScreen::tr("Checking game path..."));
    QDir dir(QString("lua"));
    if (dir.exists() && (dir.exists(QString("config.lua")))) {
        // things look good and use current dir
    } else {
        showSplashMessage(QSplashScreen::tr("Setting game path..."));
#ifndef Q_OS_ANDROID
        QDir::setCurrent(qApp->applicationFilePath().replace("games", "share"));
#else
        bool found = false;
        QDir storageDir("/storage");
        QStringList sdcards = storageDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        foreach (const QString &sdcard, sdcards) {
            QDir root(QString("/storage/%1/Android/data/org.qsgsrara.qsanguosha").arg(sdcard));
            if (root.exists("lua/config.lua")) {
                QDir::setCurrent(root.absolutePath());
                found = true;
                break;
            }
        }
        if (!found) {
            QDir root("/sdcard/Android/data/org.qsgsrara.qsanguosha");
            if (root.exists("lua/config.lua")) {
                QDir::setCurrent(root.absolutePath());
                found = true;
            }
        }


        if (!found) {
            QString m = QObject::tr("Game data not found, please download QSanguosha-For-Hegemony PC version, and put the files and folders into /sdcard/Android/data/org.qsgsrara.qsanguosha");
            if (!noGui)
                QMessageBox::critical(NULL, QObject::tr("Error"), m);
            else
                puts(m.toLatin1().constData());

            return -2;
        }
#endif
    }
#endif

    // load the main translation file first for we need to translate messages of splash.
    QTranslator translator;
    translator.load("sanguosha.qm");
    QApplication::installTranslator(&translator);

    showSplashMessage(QSplashScreen::tr("Loading translation..."));
    QTranslator qt_translator;
    qt_translator.load("qt_zh_CN.qm");
    QApplication::installTranslator(&qt_translator);

    showSplashMessage(QSplashScreen::tr("Initializing game engine..."));
    new Settings;
    Sanguosha = new Engine;

    showSplashMessage(QSplashScreen::tr("Loading user's configurations..."));
    Config.init();
    if (!serverMode) {
        QFont f = Config.AppFont;
#ifdef Q_OS_ANDROID
        f.setPointSize(12);
#endif
        QApplication::setFont(f);
    }

    if (serverMode) {
        Server server(&app);
        qInfo() << "Server is starting on port " << Config.ServerPort;

        if (server.listen())
            qInfo() << "Starting successfully";
        else
            qInfo() << "Starting failed!";

        return QApplication::exec();
    }
    else
    {
        showSplashMessage(QSplashScreen::tr("Loading style sheet..."));
        QFile file("style-sheet/sanguosha.qss");
        QString styleSheet;
        if (file.open(QIODevice::ReadOnly)) {
            QTextStream stream(&file);
            styleSheet = stream.readAll();
        }

#ifdef Q_OS_WIN
        QFile winFile("style-sheet/windows-extra.qss");
        if (winFile.open(QIODevice::ReadOnly)) {
            QTextStream winStream(&winFile);
            styleSheet += winStream.readAll();
        }
#endif

        app.setStyleSheet(styleSheet + StyleHelper::styleSheetOfTooltip());

#ifdef AUDIO_SUPPORT
        showSplashMessage(QSplashScreen::tr("Initializing audio module..."));
        Audio::init();
#else
        QMessageBox::warning(NULL, QMessageBox::tr("Warning"), QMessageBox::tr("Audio support is disabled when compiled"));
#endif

        showSplashMessage(QSplashScreen::tr("Loading main window..."));
        MainWindow main_window;
        Sanguosha->setParent(&main_window);
        main_window.show();
        splash->finish(&main_window);
        delete splash;

        if (parser.isSet("connect"))
        {
            Config.HostAddress = parser.value("connect");
            Config.setValue("HostAddress", parser.value("connect"));
        }

        return QApplication::exec();
    }
}
