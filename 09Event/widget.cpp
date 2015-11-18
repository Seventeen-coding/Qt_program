#include "widget.h"
#include "ui_widget.h"
#include <QPaintEvent>
#include <QResizeEvent>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //this->startTimer(1000);
    //QTimer::singleShot(10000, this, SLOT(close()));
    textEdit = new QTextEdit(this);

    textEdit->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == textEdit) {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            qDebug() << "Ate key press" << keyEvent->key();
            return true;
        } else {
            return false;
        }
    } else {
        // pass the event on to the parent class
        return Widget::eventFilter(obj, event);
    }
}

//enum QEvent::Type
//需要更新图片 可以用update触发
void Widget::paintEvent(QPaintEvent *event)
{
    // qDebug() << "paintEvent:" << event->type();
}
//大小发生变化
void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << "resizeEvent:" << event->type();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mousePressEven:" << event->type();
}

void Widget::wheelEvent(QWheelEvent *event)
{
    qDebug() << "wheelEvent:" << event->type();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "keyPressEvent:" << event->type();
}

void Widget::focusInEvent(QFocusEvent *event)
{
    qDebug() << "focusInEvent:" << event->type();
}

void Widget::focusOutEvent(QFocusEvent *event)
{
    qDebug() << "focusOutEvent:" << event->type();
}

void Widget::closeEvent(QCloseEvent *event)
{
    qDebug() << "closeEvent:" << event->type();
}

void Widget::leaveEvent(QEvent *event)
{
    qDebug() << "leaveEvent" << event->type();
}

void Widget::enterEvent(QEvent *event)
{
    qDebug() <<"enterEvent" << event->type();
}
// event() 是一个集中处理不同类型的事件的地方
/*
event() 函数会有两个问题：
1.  event() 函数是一个 protected 的函数，这意味着我们要想重写 event() ，必须继承一个
已有的类。试想，我的程序根本不想要鼠标事件，程序中所有组件都不允许处理鼠标
事件，是不是我得继承所有组件，一一重写其 event() 函数？protected 函数带来的另外
一个问题是，如果我基于第三方库进行开发，而对方没有提供源代码，只有一个链接
库，其它都是封装好的。我怎么去继承这种库中的组件呢？
2.  event() 函数的确有一定的控制，不过有时候我的需求更严格一些：我希望那些组件根
本看不到这种事件。 event() 函数虽然可以拦截，但其实也是接收到了 QMouseEvent
对象。我连让它收都收不到。这样做的好处是，模拟一种系统根本没有那个事件的效
果，所以其它组件根本不会收到这个事件，也就无需修改自己的事件处理函数。这种
需求怎么办呢？
事实上，Qt 事件的调用最终都会追溯到
QCoreApplication::notify() 函数
*/
bool Widget::event(QEvent *event)
{
    qDebug() << "event"  << event->type();

    //这里可以根据type处理响应的事件
    switch (event->type()) {
    case QEvent::Timer:
        timerEvent((QTimerEvent*)event);
        break;
    case QEvent::ChildAdded:
    case QEvent::ChildPolished:
    case QEvent::ChildRemoved:
        childEvent((QChildEvent*)event);
        break;
    case QEvent::Enter:
        enterEvent(event);
    case QEvent::Leave:
        leaveEvent(event);
    default:
        if (event->type() >= QEvent::User) {
            customEvent(event);     //这里是自定义的事件
            break;
        }
        return false;
    }
    return true;
}

void Widget::timerEvent(QTimerEvent *event)
{
    qDebug() << "timerEvent" << event->type();
}

