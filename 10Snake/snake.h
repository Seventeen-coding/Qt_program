#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QGraphicsItem>
#include "gamecontroller.h"
#include "define.h"
class GameController;

class Snake : public QGraphicsItem
{
public:
    Snake(QObject *parent);
    ~Snake();

    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QPainterPath shape()const;

    GameController *controller;

    QPointF head;
    QList<QPointF> tail;

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    int moveDirection;
    int growing;
    int tickCounter;
    int fresh;
    int speed;

    void setMoveDirection(int moveDirection);
    void handleCollisions();//碰撞事件
public slots:
    void advance(int step);

};

#endif // SNAKE_H
