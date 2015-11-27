#include "food.h"
#include "define.h"
#include <QPainter>
#include <QPainterPath>
Food::Food(qreal x, qreal y)
{
    setPos(x,y);
    setData(GD_Type,GO_Food);
}

Food::~Food()
{

}

QRectF Food::boundingRect() const
{
    return QRectF(-TILE_SIZE, -TILE_SIZE, TILE_SIZE * 2, TILE_SIZE * 2 );
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::yellow);
    painter->restore();
}

//轮廓
QPainterPath Food::shape() const
{
    QPainterPath p;
    p.addEllipse(QPointF(TILE_SIZE / 2, TILE_SIZE / 2), FOOD_RADIUS,FOOD_RADIUS);
    return p;
}

