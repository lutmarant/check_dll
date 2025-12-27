TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += BUILD_TEST

INCLUDEPATH =+ $$PWD/../include/

SOURCES += \
        $$PWD/../include/myMath.c \
        main.c

HEADERS += \
        $$PWD/../include/myMath.h

DESTDIR = $$PWD/../bin
