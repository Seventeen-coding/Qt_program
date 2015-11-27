#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QLibrary>
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

typedef void (*Fun)(QString str); //定义函数指针，以备调用

void Widget::on_pushButton_clicked()
{
    QLibrary mylib("helloworld.dll");   //声明所用到的dll文件
    int result;
    QString sresult;
    if (mylib.load())              //判断是否正确加载
    {
        Fun open=(Fun)mylib.resolve("print_str");    //援引 add() 函数
        if (open)                  //是否成功连接上 add() 函数
        {
             open(QString("hello world"));
        }
    }
    else
    {
        QMessageBox::information(NULL,"NO","DLL is not loaded!");
    }

}


typedef QDialog *(*Funs)(); //定义函数指针，以备调用
void Widget::on_pushButton_2_clicked()
{
   //加载插件
   QLibrary mylib("helloworld.dll");   //声明所用到的dll文件
   if (mylib.load())              //判断是否正确加载
   {
       Funs open=(Funs)mylib.resolve("showDialog");    //援引 add() 函数
       if (open)                  //是否成功连接上 add() 函数
       {
           QDialog *form1= open();
           form1->show();
        }
    }
}
