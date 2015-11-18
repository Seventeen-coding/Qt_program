#include "mainwindow.h"
#include <QApplication>
#include <QTextStream>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile data("file.txt");
    if (data.open(QFile::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&data);
        out << "The answer is " << 42;
    }

    return a.exec();
}
