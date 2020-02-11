#ifndef TABCONTENTWIDGET_H
#define TABCONTENTWIDGET_H

#include "ui_tabcontentwidget.h"
#include <QGraphicsView>

class TabContentWidget : public QWidget, private Ui::TabContentWidget
{
    Q_OBJECT

public:
    explicit TabContentWidget(QWidget *parent = nullptr);
    QTableWidget & getTable();
    QGraphicsView & getGraphArea();
    void setTableSize(int x, int y);
    QString getFileName();
    void setFileName(QString fileName);

private:
    QString fileName;
};

#endif // TABCONTENTWIDGET_H
