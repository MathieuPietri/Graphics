#ifndef TABCONTENTWIDGET_H
#define TABCONTENTWIDGET_H

#include "ui_tabcontentwidget.h"
#include <QGraphicsView>
#include "Graph/graph.h"


class TabContentWidget : public QWidget, private Ui::TabContentWidget
{
    Q_OBJECT

public:
    explicit TabContentWidget(QWidget *parent = nullptr);
    QTableWidget & getTable();
    QGraphicsView & getGraphArea();
    void setTableSize(int x, int y);
    QString getFileName();
    void setFileName(QString fileName);
    Graph getGraph();
    void setGraph(Graph *graph);
    ~TabContentWidget();

private:
    QString fileName;
    Graph *graph = nullptr;

};



#endif // TABCONTENTWIDGET_H
