#include "mainwindow.h"
#include <QApplication>
#include <QMouseEvent>
#include <QEvent>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //QCoreApplication::notify() 所有事件发布在此
    //static bool QCoreApplication::sendEvent(QObject *receiver,QEvent *event);
    //event 对象并不会被销毁。通常我们会在栈上创建 event 对象


    //static void QCoreApplication::postEvent(QObject *receiver,
    //QEvent *event)
    //事件会根据 post 的顺序进行处理。如果你想要改变事件的处理顺序，可以考虑为其指
    //定一个优先级。默认的优先级是 Qt::NormalEventPriority 。
    // post 的时候将其 delete 掉，因此，我们必须在堆上创建 event 对象


    //static void QCoreApplication::sendPostedEvents(QObject *receiver,
    //int event_type);

    w.show();


    return a.exec();
}
