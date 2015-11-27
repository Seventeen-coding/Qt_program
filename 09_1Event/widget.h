#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QEvent>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    bool eventFilter(QObject *watched, QEvent *event);
protected:
    void mousePressEvent(QMouseEvent *)
    {
        qDebug() << "mousePressEvent";
    }
    bool event(QEvent *e)
    {
        if (e->type() == QEvent::MouseButtonPress) {
            qDebug() << "event";
        }
        if (e->type() == QEvent::MouseButtonDblClick) {
            qDebug() << "event";
        }
       // return true;                //这句加了也不往下传
        return QWidget::event(e);   //这句不加就不往下传
    }
};

#endif // WIDGET_H
