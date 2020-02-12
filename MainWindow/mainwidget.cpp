#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "iostream"
#include "Graph/csv.h"
#include "tabcontentwidget.h"
#include "Graph/graphrenderer.h"

using namespace std;
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    tabs->removeTab(1);
}

void MainWidget::fillTable(QTableWidget &tableWidget, vector<vector<string>> data) {

    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[0].size(); j++) {
            tableWidget.setItem(i, j, new QTableWidgetItem(QString::fromStdString(data.at(i).at(j))));
        }
    }
}

void MainWidget::addDataSet(vector<vector<string> > data, const QString &filePath) {
    if (tabCounter == -1) {
        tabs->removeTab(0);
    }
    TabContentWidget * newTabContentWidget = new TabContentWidget(this);
    tabCounter = tabs->addTab(newTabContentWidget, QString::fromStdString(getNameFromPath(filePath)));
    newTabContentWidget->setTableSize(maxColCount(data), data.size());

    //TODO si le nom est null, l'onglet doit s'appeler "nouvel onglet" mais on doit quand même mettre nullptr dans setFileName()
    newTabContentWidget->setFileName(filePath);
    fillTable(newTabContentWidget->getTable(), data);

    GraphRenderer * renderer = new GraphRenderer(data, &newTabContentWidget->getGraphArea());
    //Graph(data) graph;
    //graph.addToScene(newTabContentWidget->getGraphArea().scene());
    tabs->setCurrentIndex(tabCounter);
    TabContentWidget & newTabContentWidgetRef = *newTabContentWidget;
    // ----------- tabContents.push_back(newTabContentWidgetRef);
}



int MainWidget::maxColCount(vector<vector<string>> data) {
    int max = 0;
    for (vector<string> v : data) {
        if (v.size() > max)
            max = v.size();
    }
    return max;
}

TabContentWidget * MainWidget::getCurrentTabContent() {
    //TabContentWidget * ptr = &tabContents.at(tabs->currentIndex());
    return nullptr; //TODO
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
