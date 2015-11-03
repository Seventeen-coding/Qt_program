#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QColorDialog>
#include <QPrintDialog>
#include <QInputDialog>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->plainTextEdit->clear();
}
void Widget::on_pushButton_2_clicked()
{
    //    QFileDialog a;
    //    a.show();
    //    a.exec();
    //qDebug() << QFileDialog::getOpenFileUrl().toString();
    ui->plainTextEdit->appendPlainText(QFileDialog::getExistingDirectory());
}



void Widget::on_pushButton_3_clicked()
{
    //    QColorDialog a;
    //    a.show();
    //    a.exec();
    ui->plainTextEdit->appendPlainText(QColorDialog::getColor().name());
}


void Widget::on_pushButton_4_clicked()
{
    //    QPrintDialog a;
    //    a.show();
    //    a.exec();
    //ui->plainTextEdit->appendPlainText(QPrintDialog::);        //没用过
}

void Widget::on_pushButton_1_clicked()
{
    ui->plainTextEdit->appendPlainText(QInputDialog::getText(this,tr("Inputdialog"),tr("Input_lab")));
}

