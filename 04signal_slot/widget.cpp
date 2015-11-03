#include "widget.h"
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //1
    QSize mySize;
    mySize.setHeight(50);
    mySize.setWidth(50);
    QPoint myPoint;
    myPoint.setX(80);
    myPoint.setY(80);

    //2
    QPoint my_left_top_Point(125,125);
    QPoint my_right_bottom_Point(150,150);

    QRect myrect_lab(myPoint,mySize);                                 //1
    QRect myrect_btn(my_left_top_Point,my_right_bottom_Point);        //2
    QRect myrect_widget(300,300,400,400);                             //3

    mylab = new QLabel(tr("mylab"),this);
    mybtn.setParent(this);

    this->setGeometry(myrect_widget);
    mybtn.setGeometry(myrect_btn);
    mylab->setGeometry(myrect_lab);

    connect(this,mysignal,this,myslots);                            //1

    mybtn.setObjectName(tr("click"));
    connect(&mybtn,SIGNAL(clicked()),this,SLOT(send()));            //2
}

Widget::~Widget()
{

}

void Widget::myslots(QString str)
{
    QMessageBox::information(this,tr("hello Qt"),tr("btn click"),tr("yes"));
}
