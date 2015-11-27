#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    installEventFilter(this);
}

Widget::~Widget()
{

}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == this) {
        if (event->type() == QEvent::MouseButtonPress) {
            qDebug() << "eventFilter";
           // return true;      加了这个事件就不会往下传输
        }
    }
    return false;
}