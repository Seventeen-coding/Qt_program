#include "widget.h"
#include <QDebug>
#include <QPushButton>
#include <QPalette>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setGeometry(100,100,100,100);
    mylabel.setText(tr("hello Qt"));
    mylabel.setParent(this);
    QPalette myPalette;
    myPalette.setColor(QPalette::Background,QColor(Qt::blue));
    mylabel.setAlignment(Qt::AlignHCenter);
    QPushButton *mybtn = new QPushButton("Qt btn",this);
     mybtn->setGeometry(50,50,50,50);
    // mybtn->setEnabled(true);
    // mylayout.addWidget(&mylabel);
    // mylayout.addWidget(mybtn);
    this->setLayout(&mylayout);
}

Widget::~Widget()
{

}
