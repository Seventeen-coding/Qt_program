#include "helloworld.h"


Helloworld::Helloworld()
{
}

void print_str(QString str)
{
    qDebug() << str;
}

QDialog *showDialog()
{
    Dialog *ss=new Dialog;
    return ss;
}