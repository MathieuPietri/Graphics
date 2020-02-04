#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "iostream"
#include "Graph/csv.h"
#include "tabcontentwidget.h"

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

void MainWidget::addDataSet(vector<vector<string> > data, const QString &name) {
    if (tabCounter == 1) {
        fillFirstTable(data);
        tabCounter++;
        return;
    }
    TabContentWidget *newTabContentWidget = new TabContentWidget(this);
    tabs->addTab(newTabContentWidget, name);
    fillTable(newTabContentWidget->getTable(), data);
}

void MainWidget::fillFirstTable(vector<vector<string>> data) {

    fillTable(tabContentWidget_1->getTable(), data);
    //fillTab(data2, &tableWidget_2)
}
