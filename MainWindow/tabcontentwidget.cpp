#include "tabcontentwidget.h"

TabContentWidget::TabContentWidget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}


QTableWidget & TabContentWidget::getTable() {
    QTableWidget & table_ = *table;
    return table_;
}

QGraphicsView & TabContentWidget::getGraphArea() {
    QGraphicsView & graphArea_ = *graphArea;
    return graphArea_;
}
