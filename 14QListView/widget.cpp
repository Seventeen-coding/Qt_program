#include "widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    QStringList data;
    data << "Letter A" << "Letter B" << "Letter C";
    model = new QStringListModel(this);
    model->setStringList(data);

    listView = new QListView(this);
    listView->setModel(model);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    QPushButton *insertBtn = new QPushButton(tr("insert"),this);
    connect(insertBtn,SIGNAL(clicked()),this,SLOT(insertData()));
    QPushButton *delBtn = new QPushButton(tr("Delete"), this);
    connect(delBtn, SIGNAL(clicked()), this, SLOT(deleteData()));
    QPushButton *showBtn = new QPushButton(tr("Show"), this);
    connect(showBtn, SIGNAL(clicked()), this, SLOT(showData()));
    btnLayout->addWidget(insertBtn);
    btnLayout->addWidget(delBtn);
    btnLayout->addWidget(showBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(listView);
    mainLayout->addLayout(btnLayout);
    setLayout(mainLayout);
}

Widget::~Widget()
{

}

void Widget::insertData()
{
    bool isOK;
    QString text = QInputDialog::getText(this, "Insert","please input new data:" , QLineEdit::Normal, \
                                         "You are inserting new data.",&isOK);
    if(isOK){
        //先加行再插入  类似 new一个空间出来再赋值
        int row = listView->currentIndex().row();
        model->insertRows(row,1);
        QModelIndex index = model->index(row);
        model->setData(index,text);
        listView->setCurrentIndex(index);
        listView->edit(index);
    }
}

void Widget::deleteData()
{
    if(model->rowCount() > 1){
        int row = listView->currentIndex().row();
        model->removeRow(row);
    }

}

void Widget::showData()
{
    QStringList data = model->stringList();
    QString str;
    foreach(QString s, data) {
        str += s + "\n";
    }
    QMessageBox::information(this, "Data", str);
}
