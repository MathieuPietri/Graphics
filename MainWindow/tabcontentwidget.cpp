#include "tabcontentwidget.h"
using namespace std;
#include <iostream>


TabContentWidget::TabContentWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}


QTableWidget & TabContentWidget::getTable() {
    QTableWidget & table_ = *table;
    return table_;
}

QGraphicsView & TabContentWidget::getGraphArea() {
    QGraphicsView & graphArea_ = *graphArea;
    return graphArea_;
}

void TabContentWidget::setTableSize(int cols, int rows) {
    table->setColumnCount(cols);
    table->setRowCount(rows);
}

QString TabContentWidget::getFileName() {
    return this->fileName;
}

void TabContentWidget::setFileName(QString fileName) {
    this->fileName = fileName;
}

void TabContentWidget::setGraph(Graph *graph){
    this->graph = graph;
}

TabContentWidget::~TabContentWidget(){
    if(this->graph != nullptr) delete(graph);
}

Graph TabContentWidget::getGraph(){
    if (this->graph == nullptr)
        cout << "error no graph in tabcontentwidget" << endl;
    else {
        cout << "graph imported correctly from tabcontentwidget" << endl;
    }
    return *graph;
}
