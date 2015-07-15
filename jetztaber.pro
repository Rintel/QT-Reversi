#-------------------------------------------------
#
# Project created by QtCreator 2015-03-10T16:01:26
#
#-------------------------------------------------

QT       += core gui opengl declarative widgets xml multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jetztaber
TEMPLATE = app

unix|win32: LIBS += -lGLU
#unix|win32: LIBS += -lGLEW
unix: LIBS += -lGL
#unix|win32: LIBS += -lglut
#unix|win32: LIBS += -lglfw3
#unix|win32: LIBS += -lm
#unix|win32: LIBS += -lXrandr
#unix|win32: LIBS += -lXi
#unix|win32: LIBS += -lX11
#unix|win32: LIBS += -lXxf86vm

SOURCES += main.cpp\
        mainwindow.cpp \
    hauptmenue.cpp \
    credits.cpp \
    newgame.cpp \
    spielladen.cpp \
    openglgame.cpp \
    glwidget.cpp \
    feld.cpp \
    spieler.cpp \
    spielzug.cpp \
    spielbrett.cpp \
    reversi.cpp \
    spielzugliste.cpp \
    gewinner.cpp

HEADERS  += mainwindow.h \
    hauptmenue.h \
    credits.h \
    newgame.h \
    spielladen.h \
    openglgame.h \
    glwidget.h \
    DEFINE.h \
    feld.h \
    spieler.h \
    spielzug.h \
    spielbrett.h \
    reversi.h \
    spielzugliste.h \
    gewinner.h

FORMS    += mainwindow.ui \
    hauptmenue.ui \
    credits.ui \
    newgame.ui \
    spielladen.ui \
    openglgame.ui \
    gewinner.ui
