#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "iostream"
#include "Graph/csv.h"
#include "tabcontentwidget.h"
#include "Graph/graph.h"

using namespace std;
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    tabs->removeTab(1);
}

void MainWidget::fillTable(QTableWidget &tableWidget, vector<vector<string>> data) {

    for (int i = 0; i < (int)data.size(); i++) {
        for (int j = 0; j < (int)data[i].size(); j++) {
            tableWidget.setItem(i, j, new QTableWidgetItem(QString::fromStdString(data.at(i).at(j))));
        }
    }
}

void MainWidget::addDataSet(vector<vector<string> > data, const QString &filePath) {
    if (tabCounter == -1) {
        tabs->removeTab(0);
    }
    TabContentWidget * newTabContentWidget = new TabContentWidget(this);
    tabCounter = tabs->addTab(newTabContentWidget, filePath);//QString::fromStdString(getNameFromPath(filePath)));
    newTabContentWidget->setTableSize(maxColCount(data), data.size());

    //TODO si le nom est null, l'onglet doit s'appeler "nouvel onglet" mais on doit quand même mettre nullptr dans setFileName()
    newTabContentWidget->setFileName(filePath);
    fillTable(newTabContentWidget->getTable(), data);

    //Graph(data) graph;
    //graph.addToScene(newTabContentWidget->getGraphArea().scene());

    Graph* graph = new Graph(data);
    newTabContentWidget->getGraphArea().setScene(new QGraphicsScene);
    graph->addToScene(newTabContentWidget->getGraphArea().scene());
    newTabContentWidget->update();

    tabs->setCurrentIndex(tabCounter);
    TabContentWidget & newTabContentWidgetRef = *newTabContentWidget;
    //tabContents.push_back(newTabContentWidgetRef);
}



int MainWidget::maxColCount(vector<vector<string>> data) {
    int max = 0;
    for (vector<string> v : data) {
        if ((int)v.size() > max)
            max = v.size();
    }
    return max;
}

TabContentWidget * MainWidget::getCurrentTabContent() {
    //TabContentWidget * ptr = &tabContents.at(tabs->currentIndex());
    return nullptr;
}



std::string MainWidget::getNameFromPath(const QString path) {

    std::string path_ = path.toStdString();
    std::string result = "";
    while (path.back() != '/') {
        result.insert(0, &path_.back());
        path_.pop_back();
    }
    return result;
}
