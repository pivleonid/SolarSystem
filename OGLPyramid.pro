TEMPLATE     = app
QT          += widgets opengl
HEADERS      = OGLPyramid.h
SOURCES	     = OGLPyramid.cpp \
               main.cpp
windows:TARGET = ../OGLPyramid

LIBS += -lglu32 -lopengl32

#INCLUDEPATH C:\Qt\Qt5.8.0\5.8\mingw53_32\include\QtOpenGL
