QT += charts

HEADERS += \
chart.h \
chartview.h \
      mainwindowfindposcomplex.h \
      mainwindowfindprj.h \
      mainwindowfuncangle1to2.h \
      mainwindowfunccoordx.h \
      mainwindowfunccoordy.h \
      mainwindowfuncdist1to2.h \
      mainwindowfuncfindtime.h \
      mainwindowfuncgrad.h \
      mainwindowfuncpriv2pi.h \
      mainwindowfuncprivpi.h \
      mainwindowfuncrad.h \
      mainwindowsignfunc.h \
      mainwindowsqrfunc.h \
      mainwindowverifyparams.h

SOURCES += \
chart.cpp \
chartview.cpp \
      mainwindowfindposcomplex.cpp \
      mainwindowfindprj.cpp \
      mainwindowfuncangle1to2.cpp \
      mainwindowfunccoordx.cpp \
      mainwindowfunccoordy.cpp \
      mainwindowfuncdist1to2.cpp \
      mainwindowfuncfindtime.cpp \
      mainwindowfuncgrad.cpp \
      mainwindowfuncpriv2pi.cpp \
      mainwindowfuncprivpi.cpp \
      mainwindowfuncrad.cpp \
      mainwindowsignfunc.cpp \
      mainwindowsqrfunc.cpp \
      mainwindowverifyparams.cpp

DESTDIR = $$PWD/../bin


#PATH_WYKOBI = "C:/wykobi-master"
#INCLUDEPATH += $${PATH_WYKOBI}

INCLUDEPATH +=  $$PWD/../include/

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
mainwindow.h \
ui_view.h \
ui_scene.h \
$$PWD/../include/myMath.h
importedMath.h \

SOURCES += \
main.cpp \
mainwindow.cpp \
		ui_view.cpp \
		ui_scene.cpp \
		importedMath.cpp

FORMS += \
		mainwindow.ui \
		mainwindowfindposcomplex.ui \
		mainwindowfindprj.ui \
		mainwindowfuncangle1to2.ui \
		mainwindowfunccoordx.ui \
		mainwindowfunccoordy.ui \
		mainwindowfuncdist1to2.ui \
		mainwindowfuncfindtime.ui \
		mainwindowfuncgrad.ui \
		mainwindowfuncpriv2pi.ui \
		mainwindowfuncprivpi.ui \
		mainwindowfuncrad.ui \
		mainwindowsignfunc.ui \
		mainwindowsqrfunc.ui \
		mainwindowverifyparams.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
