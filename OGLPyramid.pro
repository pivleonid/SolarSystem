TEMPLATE     = app
QT          += widgets opengl
HEADERS      = OGLPyramid.h
SOURCES	     = OGLPyramid.cpp \
               main.cpp
windows:TARGET = ../OGLPyramid

LIBS += -lglu32 -lopengl32
