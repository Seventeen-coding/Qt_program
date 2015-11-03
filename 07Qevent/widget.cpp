#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setMouseTracking(true);           //鼠标跟踪 默认为false

}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "mouse move";
//    this->setWindowTitle(QString("<center><h1>Move: (%1, %2)</h1></center>")\
//                       .arg(QString::number(event->x()),QString::number(event->y())));
}

void Widget::mousePressEvent(QMouseEvent *event)
{
     qDebug() << "mouse click";
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
     qDebug() << "mouse release";
}

