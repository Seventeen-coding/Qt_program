#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QPushButton mybtn;  //各种widget需要指定父亲窗口才能添加到另一个widget
    QLabel *mylab;



signals:
    void mysignal(QString);
public slots:           //只写slots报错，槽函数有私有公有之分
     void myslots(QString);
     void send()
     {
         emit mysignal(mybtn.objectName());
     }
};

#endif // WIDGET_H
