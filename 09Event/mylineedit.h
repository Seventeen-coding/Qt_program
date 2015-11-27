#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>
class mylineEdit : public QLineEdit
{
    Q_OBJECT
public:

    bool eventFilter(QObject *obj, QEvent *event)
    {
        qDebug() << obj << obj->objectName()  << event->type() ;
        //        if (obj == mylineEdit){
        //            if (event->type() == QEvent::KeyPress) {
        //                QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        //                qDebug() << "Ate key press" << keyEvent->key();
        //                return true;
        //            } else {
        //                return false;
        //            }
        //        } else {
        //            // pass the event on to the parent class
        //            return QWidget::eventFilter(obj, event);
        //        }
    }
};

#endif // MYLINEEDIT_H

