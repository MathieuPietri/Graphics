#include "tabcontentwidget.h"
#include "mainwidget.h"

using namespace std;
#include <iostream>


TabContentWidget::TabContentWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
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

Graph* TabContentWidget::getGraph(){
    if (this->graph == nullptr)
        cout << "error no graph in tabcontentwidget" << endl;
    else {
        cout << "graph imported correctly from tabcontentwidget" << endl;
    }
    return graph;
}

void TabContentWidget::undoLast(){
    if(_undoList.size() > 0){
        _undoList.back()->undo();
        _redoList.push_back(_undoList.back());
        _undoList.pop_back();
        graphArea->update();
    }
}
void TabContentWidget::redoLast(){
    if(_redoList.size() > 0){
        _redoList.back()->redo();
        _undoList.push_back(_redoList.back());
        _redoList.pop_back();
        graphArea->update();
    }
}
void TabContentWidget::addGraphAction(GraphAction* action){
    _undoList.push_back(action);
    for(auto act:_redoList){
        delete act;
        act = nullptr;
    }
    _redoList.clear();
}
