#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "ui_mainwidget.h"
#include <vector>
#include <string>

class MainWidget : public QWidget, private Ui::MainWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    void fillTable(QTableWidget &tableWidget, std::vector<std::vector<std::string>> data);
    void addTab();
};

#endif // MAINWIDGET_H
