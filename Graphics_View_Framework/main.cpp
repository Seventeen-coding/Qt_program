
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene my_scene;
    //my_scene.setSceneRect(0, 0, 300, 300);
    my_scene.addLine(0, 0, 150, 150);
    QGraphicsView view(&my_scene);
    view.setWindowTitle("Graphics View");
    view.resize(500, 500);
    view.show();

    return a.exec();
}
