#include "toolbar.h"
#include "main_window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Main_window w;

    ToolBar t;
    t.show();
   // w.show();

    return a.exec();
}
