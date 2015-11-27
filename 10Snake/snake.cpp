#include "snake.h"
#include <QPainter>
#include <QDebug>

Snake::Snake(QObject *parent)
{
    controller = (GameController *)parent;
    growing = 1;
    tickCounter = 1;
    speed = 3;
    moveDirection = NoMove;
}

Snake::~Snake()
{

}
//范围
QRectF Snake::boundingRect()const
{
    qreal minX = head.x();
    qreal minY = head.y();
    qreal maxX = head.x();
    qreal maxY = head.y();
    foreach (QPointF p, tail) {
        maxX = p.x() > maxX ? p.x() : maxX;
        maxY = p.y() > maxY ? p.y() : maxY;
        minX = p.x() < minX ? p.x() : minX;
        minY = p.y() < minY ? p.y() : minY;
    }
    QPointF tl = mapFromScene(QPointF(minX, minY));
    QPointF br = mapFromScene(QPointF(maxX, maxY));
    QRectF bound = QRectF(tl.x(), // x
                          tl.y(), // y
                          br.x() - tl.x() + SNAKE_SIZE, // width
                          br.y() - tl.y() + SNAKE_SIZE //height
                          );
    return bound;
}
void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::red);
    painter->restore();
}
//形状
QPainterPath Snake::shape()const
{
    QPainterPath path;
    path.addRect(QRect(0,0,TILE_SIZE,TILE_SIZE));
    foreach (QPointF p, tail) {
        QPointF itemp = mapFromScene(p);
        path.addRect(QRectF(itemp.x(), itemp.y(), SNAKE_SIZE, SNAKE_SIZE));
    }
    return path;
}

void Snake::moveLeft()
{
    //qDebug() << "Left";
    head.rx() -= SNAKE_SIZE;
    if(head.rx() < -SCENE_SIZE/2)
    {
        head.rx()  = SCENE_SIZE/2-SNAKE_SIZE;
    }

}
void Snake::moveRight()
{
   // qDebug() << "Right";
    head.rx() += SNAKE_SIZE;
    if(head.rx() > SCENE_SIZE/2-SNAKE_SIZE)
    {
        head.rx()  = -SCENE_SIZE/2;
    }
}
void Snake::moveUp()
{
    //qDebug() << "Up";
    head.ry() -= SNAKE_SIZE;
    if(head.ry() < -SCENE_SIZE/2)
    {
        head.ry()  = SCENE_SIZE/2-SNAKE_SIZE;
    }
}
void Snake::moveDown()
{
   // qDebug() << "Down";
    head.ry() += SNAKE_SIZE;
    if(head.ry() > SCENE_SIZE/2-SNAKE_SIZE)
    {
        head.ry()  = -SCENE_SIZE/2;
    }
}

void Snake::advance(int step)
{

    if(!step){
        return ;
    }
    if(tickCounter++ % speed != 0)
    {
        return;
    }
    tickCounter = 1;

    if(moveDirection == NoMove){
        return;
    }


    if (growing > 0) {
        QPointF tailPoint = head;
        tail << tailPoint;
        growing -= 1;
    } else {
        tail.takeFirst();
        tail << head;
    }

    switch (moveDirection) {
    case MoveLeft:
        moveLeft();
        break;
    case MoveRight:
        moveRight();
        break;
    case MoveUp:
        moveUp();
        break;
    case MoveDown:
        moveDown();
        break;
    }
    setPos(head);
    handleCollisions();
    qDebug() << head.rx()  << head.ry();
}

//碰撞事件
void Snake::handleCollisions()
{

    QList <QGraphicsItem *>collisions = collidingItems();

    foreach(QGraphicsItem *collidingItem, collisions){
        qDebug() << "-------------data----------" <<collidingItem->data(GD_Type) ;
        if(collidingItem->data(GD_Type) == GO_Food){
            controller->snakeAteFood(this, (Food *)collidingItem);
            growing += 1;
        }
    }

    if(tail.contains(head)){
        controller->snakeAteItself(this);
    }

}

void Snake::setMoveDirection(int moveDirection)
{
    this->moveDirection = moveDirection;
    //qDebug() << moveDirection;
}
