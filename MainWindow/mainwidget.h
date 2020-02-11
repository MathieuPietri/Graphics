#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "ui_mainwidget.h"
#include "Graph/csv.h"
#include <vector>
#include <string>

class MainWidget : public QWidget, private Ui::MainWidget
{
    Q_OBJECT

public:
    int tabCounter = -1;
    explicit MainWidget(QWidget *parent = nullptr);
    void fillTable(QTableWidget &tableWidget, std::vector<std::vector<std::string>> data);
    void addDataSet(vector<vector<string>> data, const QString &name);
    TabContentWidget * getCurrentTabContent();

private:
    static int maxColCount(vector<vector<string>> data);
    // ----------- vector<TabContentWidget> tabContents;

};
#endif // MAINWIDGET_H
