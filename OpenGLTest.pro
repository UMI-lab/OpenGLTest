QT       += core gui widgets
QT       += opengl

TARGET = OpenGLTest
TEMPLATE = app

win32{
        LIBS += -lopengl32
}

SOURCES += main.cpp \
        mainwindow.cpp \
    mainscene.cpp \
    voxelmodel.cpp

HEADERS  += mainwindow.h \
    mainscene.h \
    voxelmodel.h

FORMS    += mainwindow.ui


