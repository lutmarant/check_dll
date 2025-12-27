TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

# Путь к папке с DLL
DLL_DIR = $$PWD/../bin

# Добавляем путь к библиотекам для линковщика
LIBS += $$DLL_DIR/mymathlib.dll  # прямой путь к DLL

DESTDIR = $$PWD/../bin

INCLUDEPATH =+ $$PWD/../include/

HEADERS += \
        $$PWD/../include/myMath.h

SOURCES += \
        main.c

