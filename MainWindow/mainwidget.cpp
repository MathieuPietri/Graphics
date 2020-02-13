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
}

void MainWidget::fillTable(QTableWidget &tableWidget, vector<vector<string>> data) {

    for (int i = 0; i < (int)data.size(); i++) {
        for (int j = 0; j < (int)data[i].size(); j++) {
            tableWidget.setItem(i, j, new QTableWidgetItem(QString::fromStdString(data.at(i).at(j))));
        }
    }
}

void MainWidget::addDataSet(vector<vector<string> > data, const QString &filePath) {

    /* Destruction de la page 1 si on ouvre un premier fichier */

    if (tabCounter == -1) {
        tabs->removeTab(0);
    }

    /* Création du TabContentWidget */

    TabContentWidget * newTabContentWidget = new TabContentWidget(this);
    newTabContentWidget->setFileName(filePath);  //TODO si le nom est null, l'onglet doit s'appeler "nouvel onglet" mais on doit quand même mettre nullptr dans setFileName()

    if (filePath == "nullptr" || filePath == nullptr)
        tabCounter = tabs->addTab(newTabContentWidget, "Fichier sans nom");
    else {
        std::string name = getNameFromPath(filePath);
        cout << name;
        tabCounter = tabs->addTab(newTabContentWidget, QString::fromStdString(name));

    }
    /* Remplissage de la table */

    cout << "colonne count de data: " << maxColCount(data) << endl;
    cout << "size de data: " << data.size() << endl;
    cout << "size de data[1] " << data[1].size() << endl;
    newTabContentWidget->setTableSize(maxColCount(data), data.size());
    fillTable(newTabContentWidget->getTable(), data);

    /* Création du graph */

    /* SA BUG ISSI */                                                                   Graph* graph = new Graph(data);
    newTabContentWidget->getGraphArea().setScene(new QGraphicsScene);
    graph->addToScene(newTabContentWidget->getGraphArea().scene());
    newTabContentWidget->update();

    /* Focus sur le nouvel onglet */

    tabs->setCurrentIndex(tabCounter);
    /* Ajout du TabContentWidget au vector */

    newTabContentWidget->setGraph(graph);
    tabContents.push_back(newTabContentWidget); //A DEBUG

    qDebug() << "nb tabs :" << tabCounter;
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
