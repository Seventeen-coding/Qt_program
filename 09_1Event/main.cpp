#include "widget.h"
#include <QApplication>
#include "eventfilter.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget label;
    app.installEventFilter(new EventFilter(&label, &label));
    label.show();
    return app.exec();
}
