#include "widget.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QFileInfo>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("in.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug() << "Open file failed.";
        return -1;
    }else{
        while(!file.atEnd()){
            qDebug() << file.readLine();
        }
    }

    QFileInfo info(file);       //文件信息
    qDebug() << info.isDir();
    qDebug() << info.isExecutable();
    qDebug() << info.baseName();
    qDebug() << info.completeBaseName();
    qDebug() << info.suffix();
    qDebug() << info.completeSuffix();

    return a.exec();
}
