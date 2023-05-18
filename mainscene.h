#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QTimer>
#include <QGLWidget>
#include <QPoint>
#include <QDebug>
#include <QMouseEvent>

#include <vector>

#include "voxelmodel.h"

class MainScene : public QGLWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = 0);
    ~MainScene();
    void setClipPos(float pos);
    float getClipPos();
    void setVoxelModel(VoxelModel * new_model);
    void setRotateParam(GLfloat x, GLfloat y, GLfloat z, GLfloat a);

protected:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();

    void wheelEvent(QWheelEvent *event);

private:
    GLfloat zoomScale = 1.0;
    GLfloat clip_position_ = 1.0;
    VoxelModel * model;
    std::vector<GLfloat> axis_veticies = {0.0, 0.0, 0.0,
                                          1.0, 0.0, 0.0,
                                          0.0, 1.0, 0.0,
                                          0.0, 0.0, 1.0};
    std::vector<GLint> axis_indecies = {0, 1, 0, 2, 0, 3};

    std::vector<GLfloat> axis_color = {0.0, 0.0, 0.0,
                                       0.0, 0.0, 0.0,
                                       0.0, 0.0, 0.0,
                                       0.0, 0.0, 0.0};
    GLfloat r_x, r_y, r_z, r_a;

};

#endif // MAINSCENE_H
