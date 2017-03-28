// ======================================================================
//  OGLPyramid.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.3 Professional programming with C++"
// ======================================================================
//  Copyright (c) 2014 by Max Schlee
//
//  Email : Max.Schlee@neonway.com
//  Blog  : http://www.maxschlee.com
//
//  Social Networks
//  ---------------
//  FaceBook : http://www.facebook.com/mschlee
//  Twitter  : http://twitter.com/Max_Schlee
//  2Look.me : http://2look.me/NW100003
//  Xing     : http://www.xing.com/profile/Max_Schlee
//  vk.com   : https://vk.com/max.schlee
// ======================================================================

#include <QtGui>
#include "OGLPyramid.h"

// ----------------------------------------------------------------------
OGLPyramid::OGLPyramid(QWidget* pwgt/*= 0*/) : QGLWidget(pwgt) 
                                             , m_xRotate(0)
                                             , m_yRotate(0)
{
}

// ----------------------------------------------------------------------
/*virtual*/void OGLPyramid::initializeGL()
{
    qglClearColor(Qt::black); //очистка буфера
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT); // выключаем режим сглаживания цветов
    m_nPyramid = createPyramid(1.2f);
}

// ----------------------------------------------------------------------
/*virtual*/void OGLPyramid::resizeGL(int nWidth, int nHeight)
{
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //пирамида видимости
    glFrustum(-1.2, 1.2, -1.2, 1.2, 1.0, 10.0);
}

// при перерисовке. напимкр после resizeGl
/*virtual*/void OGLPyramid::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0);//сдвиг начала систем координат на 3 единицы по оси Z

    glRotatef(m_xRotate, 1.0, 0.0, 0.0); //поворот относительно X Y
    glRotatef(m_yRotate, 0.0, 1.0, 0.0); //По Z - это будет приближение и отдаление

    glCallList(m_nPyramid); //вызов дисплейного списка
}

// ----------------------------------------------------------------------
/*virtual*/void OGLPyramid::mousePressEvent(QMouseEvent* pe)
{
    m_ptPosition = pe->pos();
}

// ----------------------------------------------------------------------
/*virtual*/void OGLPyramid::mouseMoveEvent(QMouseEvent* pe)
{
    m_xRotate += 180 * (GLfloat)(pe->y() - m_ptPosition.y()) / height();
    m_yRotate += 180 * (GLfloat)(pe->x() - m_ptPosition.x()) / width();
    updateGL();

    m_ptPosition = pe->pos();
}

// ----------------------------------------------------------------------
//Создание дисплейного списка с возвратом номера'
GLuint OGLPyramid::createPyramid(GLfloat fSize/*=1.0f*/)
{
    GLuint n = glGenLists(1);

    glNewList(n, GL_COMPILE);
//        glBegin(GL_TRIANGLE_FAN);
//            qglColor(Qt::green);
//            glVertex3f(0.0, fSize, 0.0);//вершина треугольника
//            glVertex3f(-fSize, -fSize, fSize);
//            glVertex3f(fSize, -fSize, fSize);
//            qglColor(Qt::yellow);
//            glVertex3f(fSize, -fSize, -fSize);
//            qglColor(Qt::blue);
//            glVertex3f(-fSize, -fSize, -fSize);
//            qglColor(Qt::white);
//            glVertex3f(-fSize, -fSize, fSize);
//        glEnd();
    
//        glBegin(GL_QUADS);
//            qglColor(Qt::red);
//            glVertex3f(-fSize, -fSize, fSize);
//            glVertex3f(fSize, -fSize, fSize);
//            glVertex3f(fSize, -fSize, -fSize);
//            glVertex3f(-fSize, -fSize, -fSize);
//        glEnd();

glColor3f(1.0f, 0.0f,0.0f); // Задаем цвет создаваемого примитива

glBegin(GL_POLYGON); // Задаем сам примитив

glVertex3f( 1.0f, 1.0f, 0.0f);

glVertex3f(-1.0f, 1.0f, 0.0f);

glVertex3f(-1.0f, -1.0f, 0.0f);

glVertex3f( 1.0f, -1.0f, 0.0f);

glEnd();

    return n;
}