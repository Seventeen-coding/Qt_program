#include "mainwindow.h"
#include "define.h"

Mainwindow::Mainwindow(QWidget *parent):
    QMainWindow(parent)
{

    Scene = new QGraphicsScene(this);       //相当于场景
    View = new QGraphicsView(Scene,this);   //相当于视角
    game = new GameController(Scene,this);  //控制类

    //setCentralWidget(View);
    resize(SCENE_SIZE, SCENE_SIZE);

    Scene->setSceneRect(-(this->width()/2),-(this->height()/2), SCENE_SIZE, SCENE_SIZE);

    QPixmap bg(TILE_SIZE, TILE_SIZE);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);
    View->setBackgroundBrush(QBrush(bg));
    View->adjustSize();
}



