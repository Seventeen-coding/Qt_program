#ifndef EVENTFILTER
#define EVENTFILTER

#include <QObject>
#include <QEvent>
class EventFilter : public QObject
{
public:
    EventFilter(QObject *watched, QObject *parent = 0) :
        QObject(parent),
        m_watched(watched)
    {
    }
    bool eventFilter(QObject *watched, QEvent *event)
    {
        if (watched == m_watched) {
            if (event->type() == QEvent::MouseButtonPress) {
                qDebug() << "QApplication::eventFilter";
            }
            //return true;      这里加了这行还是往下发送事件
        }
        return false;
    }
private:
    QObject *m_watched;
};


#endif // EVENTFILTER

