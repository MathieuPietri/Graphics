#include "toolbar.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToolBar w;
    w.show();

    return a.exec();
}
