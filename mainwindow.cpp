#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGLWidget>
#include <QtOpenGL>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new MainScene(this);
    model = new VoxelModel(0);
    scene->setVoxelModel(model);
    scene->setRotateParam(45, 45, -45, -13);
    ui->horizontalLayout->addWidget(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    scene->setClipPos((float)position / 100);
}

void MainWindow::on_pushButton_clicked()
{
    QMainWindow *window=new QMainWindow(this);

    MainScene * new_scene = new MainScene(this);
    new_scene->setVoxelModel(model);
    new_scene->setRotateParam(45, 0, -44, 0.0);
    new_scene->setClipPos(scene->getClipPos());
    window->setWindowTitle("Срез");
    window->setCentralWidget(new_scene);
    window->resize(600, 600);
    window->show();
    new_scene->update();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    grid_size = arg1;
}

void MainWindow::on_pushButton_2_clicked()
{
    model->setGridSize(grid_size);
    scene->setVoxelModel(model);
    scene->update();
}

