#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QEvent>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //static int QEvent::registerEventType ( int hint = -1 );
    //自定义自己的事件 需要注册 返回的范围  QEvent::User 和 QEvent::MaxUser之间
    myevent_type = 2000;    //注册了这类型的事件 的值为2000
    qDebug() << QEvent::registerEventType(myevent_type);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::customEvent(QEvent *event)
{
    qDebug() << event->type();
    // if(event->type() == QEvent::User+20)
}

bool MainWindow::event(QEvent *event)
{
    qDebug() << event->type();
    if (event->type() == myevent_type) {

        // processing...
        return true;
    }
    return QWidget::event(event);
}
void MainWindow::on_pushButton_clicked()
{
    QCoreApplication::sendPostedEvents(this,2000);
}
