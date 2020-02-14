#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "iostream"
#include "Graph/csv.h"
#include "tabcontentwidget.h"
#include "Graph/graph.h"
#include "QtDebug"

using namespace std;
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    tabs->removeTab(1);
    tabs->setTabText(0, "Fichier sans nom");
}

void MainWidget::fillTable(QTableWidget &tableWidget, vector<vector<string>> data) {

    for (int i = 0; i < (int)data.size(); i++) {
        for (int j = 0; j < (int)data[i].size(); j++) {
            tableWidget.setItem(i, j, new QTableWidgetItem(QString::fromStdString(data.at(i).at(j))));
        }
    }
}

void MainWidget::addDataSet(vector<vector<string>> data, const QString &filePath, Graph * graph) {

    /* Création du TabContentWidget */

    TabContentWidget * newTabContentWidget = new TabContentWidget(this);
    newTabContentWidget->setFileName(filePath);

    if (filePath == "nullptr" || filePath == nullptr)
        tabs->addTab(newTabContentWidget, "Fichier sans nom");
    else {
        std::string name = getNameFromPath(filePath);
        cout << name;
        tabs->addTab(newTabContentWidget, QString::fromStdString(name));

    }
    /* Remplissage de la table */

    newTabContentWidget->setTableSize(maxColCount(data), data.size());
    fillTable(newTabContentWidget->getTable(), data);

    /* Création du graph */

    if (graph == nullptr)
        graph = new Graph(data);
    newTabContentWidget->getGraphArea().setScene(new QGraphicsScene);
    graph->printGraph();
    graph->addToScene(newTabContentWidget->getGraphArea().scene());
    newTabContentWidget->update();

    /* Focus sur le nouvel onglet */

    tabs->setCurrentIndex(tabCounter+1);
    /* Ajout du TabContentWidget au vector */

    newTabContentWidget->setGraph(graph);
    tabContents.push_back(newTabContentWidget); //A DEBUG

    qDebug() << "nb tabs :" << tabCounter;

    /* Destruction de la page 1 si on ouvre un premier fichier */

    if (tabCounter == -1) {
        tabs->removeTab(0);
    }
    tabCounter++;
}



int MainWidget::maxColCount(vector<vector<string>> data) {
    int max = 0;
    for (vector<string> v : data) {
        if ((int)v.size() > max)
            max = v.size();
    }
    return max;
}

TabContentWidget * MainWidget::getCurrentTabContent(){
    if (tabCounter == -1)
        return nullptr;
    return tabContents[tabs->currentIndex()];
}


std::string MainWidget::getNameFromPath(const QString path) {

    std::string path_ = path.toStdString();
    std::string result = "";
    while (path_.back() != '/') {
        result.insert(0, &path_.back());
        path_.pop_back();
    }
    return result;
}

void MainWidget::renameCurrentTab(const QString name) {
    tabs->setTabText(tabs->currentIndex(), name);
}
