
#include <QApplication>
#include <QString>
#include <QDebug>

void fun_operation(QString str)
{
    qDebug() << str;
}

int main(int argc, char *argv[])
{
    QString str0();
    QChar c = 'Q';
    QByteArray byay("hello Qt",10);
    QString str1(c);
    QString str2(byay);


    fun_operation(str1);

    fun_operation(str2);

    QString str3 = QString("%1,%2")
            .arg("hello").arg("QString");

     fun_operation(str3);


    return 0;
}
