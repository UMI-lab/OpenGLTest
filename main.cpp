
#include <QApplication>
#include "mainwindow.h"
#include "mainscene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainScene scene;

    MainWindow scene;

    scene.resize(750, 600);
    scene.show();
    
    return a.exec();
}


