#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTextEdit>
//对于事件的具体实现可以参考The Event System
/*
 * paintEvent()     更新部件
 * resizeEvent()    调整大小
 * mousePressEvent()    鼠标按下
 * mouseReleaseEvent()  鼠标释放
 * mouseDoubleClickEvent()  鼠标双击
 * keyPressEvent()  键盘按下
 * focusInEvent()   键盘焦点事件
 * focusOutEvent()  焦点丢失
 * mouseMoveEvent() 鼠标移动
 * keyReleaseEvent()    键盘释放
 * wheelEvent()     鼠标滚轮
 * enterEvent()     进入窗口事件
 * leaveEvent()     离开窗口事件
 * moveEvent()      鼠标移动
 * closeEvent()     窗口关闭事件
*/

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    QTextEdit *textEdit;
    ~Widget();
protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void focusInEvent(QFocusEvent *event);
    void focusOutEvent(QFocusEvent *event);
    void closeEvent(QCloseEvent *event);
    void leaveEvent(QEvent *event);
    void enterEvent(QEvent *event);
    bool event(QEvent *event);      //接收所有事件响应
    void timerEvent(QTimerEvent *event);
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
