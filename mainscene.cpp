#include <QtGui>
#include "mainscene.h"
#include <math.h>
#include <QDebug>

MainScene::MainScene(QWidget *parent):QGLWidget(parent)
{

}

MainScene::~MainScene()
{

}

float MainScene::getClipPos()
{
    return (float)clip_position_;
}

void MainScene::setClipPos(float pos)
{
    clip_position_ = (GLfloat)pos;
    update();
}

void MainScene::setVoxelModel(VoxelModel *new_model)
{
    model = new_model;
}

void MainScene::setRotateParam(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
    r_x = x;
    r_y = y;
    r_z = z;
    r_a = a;
}

void MainScene::initializeGL()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
}

void MainScene::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, 0.0, 1.0);
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}

void MainScene::paintGL()
{
        // Очищаем буферы
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Устанавливаем цвет для рисования
        glEnableClientState(GL_VERTEX_ARRAY);

        // Настраиваем проекционную матрицу
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glScaled(zoomScale, zoomScale, zoomScale);

        // Разворачиваем
        glRotatef(r_x, r_y, r_z, r_a);

        // Рисуем оси
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, axis_veticies.data());
        glColorPointer(3, GL_FLOAT, 0, axis_color.data());
        glDrawElements(GL_LINES, axis_indecies.size(), GL_UNSIGNED_INT, axis_indecies.data());

        // Реализуем плоскость сечения
        GLdouble eqn1[4] = {-1.0, 0.0, -1.0, clip_position_};
        glClipPlane(GL_CLIP_PLANE0, eqn1);
        glEnable(GL_CLIP_PLANE0);

        // Рисуем воксели
        glVertexPointer(3, GL_FLOAT, 0, model->getVertices());
        glColorPointer(3, GL_FLOAT, 0, model->getColor());
        glDrawElements(GL_TRIANGLES, model->getIndicesSize(), GL_UNSIGNED_INT, model->getIndices());
        glDisableClientState(GL_VERTEX_ARRAY);

        glDisable(GL_CLIP_PLANE0);
        glFlush();

}

void MainScene::wheelEvent(QWheelEvent *event)
{
    // Зум
    QPoint numDegrees = event->angleDelta();
    if (numDegrees.y() < 0)  zoomScale = zoomScale/1.1;
    if (numDegrees.y() > 0)  zoomScale = zoomScale*1.1;

     update();
}

