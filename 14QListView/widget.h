#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStringListModel>
#include <QListView>
#include <QLayout>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QStringListModel *model;
    QListView *listView;
private slots:
    void insertData();
    void deleteData();
    void showData();

};

#endif // WIDGET_H
