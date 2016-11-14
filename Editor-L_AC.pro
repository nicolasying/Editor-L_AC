#-------------------------------------------------
#
# Project created by QtCreator 2016-10-15T22:58:25
#
#-------------------------------------------------

QT       += core gui quickcontrols2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Editor-L_AC
TEMPLATE = app


SOURCES += main.cpp \
    syntax.cpp \
    documenthandler.cpp

HEADERS  += \
    syntax.h \
    documenthandler.h \
    universalheader.h \
    networkgetlangfile.h

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
    lac_language.json

RESOURCES += \
    qtquickstyle.qrc
