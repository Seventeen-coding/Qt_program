#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //定时更新图片 触发paintEvent
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
    //设置标题
    setWindowTitle(tr("Analog Clock"));
    //设置大小
    resize(200, 200);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    //设置 时针位置
    static const QPoint hourHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -40)
    };

    //设置 分针位置
    static const QPoint minuteHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70)
    };

    //指针颜色
    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);

    //qMin-> width 比较大小 height 返回最小值
    int side = qMin(width(), height());             //为了保持缩放时候图像是圆的
    QTime time = QTime::currentTime();


    //具体用法查阅帮助QPainter
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); //反锯齿 Render Hint 呈现 提示
    painter.translate(width() / 2, height() / 2);  //?
    painter.scale(side / 200.0, side / 200.0);     //按比例放大缩小
    painter.setPen(Qt::NoPen);                     //不用笔画边框
    painter.setBrush(hourColor);                   //刷子填充


    painter.save();                                 //因为下一次分针做准备
    painter.rotate(30.0 * (time.hour() + time.minute() /60.0 + time.second() /3600.0));
    painter.drawConvexPolygon(hourHand, 3);       //Convex Polygon 多边形
    painter.restore();

    painter.setPen(hourColor);                     //设置颜色

    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);             //画线
        painter.rotate(30.0);                       //旋转
    }




    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);

    /*
        QPainter是一个状态机。那么，有时我想保存下当前的状态:当我临时绘制某些图像时，
        就可能想这么做。当然，我们有最原始的办法:将可能改变的状态，比如画笔颜色、粗细等，
        在临时绘制结束之后再全部恢复。对此，QPainter提供了内置的函数:save()和restore()。
        save()就是保存下当前状态;restore()则恢复上一次保存的结果。这两个函数必须成对出现:
        QPainter使用栈来保存数据，每一次save()，将当前状态压入栈顶，
        restore()则弹出栈顶进行恢复
     */
    painter.save();                                 //因为下一次分针做准备
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);       //Convex Polygon 多边形
    painter.restore();

    painter.setPen(minuteColor);

    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }

    painter.save();                                 //因为下一次分针做准备
    painter.rotate(6.0 *  time.second());
    qDebug() << 6.0 *  time.second();
   // painter.drawLine(QPoint(0,7),QPoint(0,-70));
    painter.drawLine(QPoint(0,7),QPoint(0,-70));

    painter.restore();


}
