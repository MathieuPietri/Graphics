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
    if (tabCounter == -1) {
        tabs->removeTab(0);
    }
    TabContentWidget * newTabContentWidget = new TabContentWidget(this);
    tabCounter = tabs->addTab(newTabContentWidget, name);
    newTabContentWidget->setTableSize(maxColCount(data), data.size());
    fillTable(newTabContentWidget->getTable(), data);
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

// -------------------- TabContentWidget * MainWidget::getCurrentTabContent() {
//    TabContentWidget * ptr = &tabContents.at(tabs->currentIndex());
//    return ptr;
//}
