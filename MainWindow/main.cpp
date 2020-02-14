#include "toolbar.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Main_window w;

    QTranslator translator;
    translator.load("WIDGETS_TOOLBAR_en");
    a.installTranslator(&translator);
    a.setWindowIcon(QIcon(":/ImagesAide/graphET_icon2.png"));

    ToolBar t;
    t.setWindowState(Qt::WindowMaximized);
    t.setWindowTitle("GraphET");
    t.show();


    //t.showFullScreen();
    // w.show();

    return a.exec();
}

