#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <gamecontroller.h>
//class QGraphicsScene;
//class QGraphicsView;
class GameController;     //操作类

class Mainwindow :public QMainWindow
{
    Q_OBJECT
public:
    Mainwindow(QWidget *parent = 0);

    QGraphicsView *View;
    QGraphicsScene *Scene;
    GameController *game;
};

#endif // MAINWINDOW_H
