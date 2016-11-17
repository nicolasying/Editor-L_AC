#-------------------------------------------------
#
# Project created by QtCreator 2016-10-15T22:58:25
#
#-------------------------------------------------

QT       += core gui quick qml network svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Editor-L_AC
TEMPLATE = app

SOURCES += main.cpp \
    syntax.cpp \
    documenthandler.cpp \
    universalfunc.cpp \
    networkgetlangfile.cpp \
    highlighterhandler.cpp

HEADERS  += \
    syntax.h \
    documenthandler.h \
    universalheader.h \
    networkgetlangfile.h \
    highlighterhandler.h

DISTFILES += \
    README.TXT \
    main.qml \
    qtquickcontrols2.conf \
    icons/edit.svg \
    icons/help.svg \
    icons/settings.svg \
    icons/welcome.svg \
    FunctionalityButton.qml \
    CodeTab.qml \
    lac_language.json \
    Info.plist \
    WelcomeDialog.qml \
    welcomePic.png \
    Editor_L-AC.ico \
    Editor_L-AC.icns \
    ico.rc

RC_FILE = ico.rc

ICON = Editor_L-AC.icns

QMAKE_INFO_PLIST += Info.plist

RESOURCES += \
    qtquickstyle.qrc
