#include "widget.h"
#include <QApplication>
#include <QFile>
#include <QDataStream>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << QString("the answer is");
    out << (qint32)42;
    file.close(); // 如果不想关闭文件，可以使用 file.flush()


    return a.exec();
}
