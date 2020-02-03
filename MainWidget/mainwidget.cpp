#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "iostream"

using namespace std;
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    vector<vector<string>> data = {{"1", "3"}, {"1", "2"}};

    fillTable(*tableur_1, data);
    //fillTab(data2, &tableWidget_2)
}

void MainWidget::fillTable(QTableWidget &tableWidget, vector<vector<string>> data) {

    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[0].size(); j++) {
            tableWidget.setItem(i, j, new QTableWidgetItem(QString::fromStdString(data.at(i).at(j))));
        }
    }
}

void MainWidget::addTab() {

}
