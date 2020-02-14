#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include "ui_aboutdialog.h"

class aboutdialog : public QWidget, private Ui::aboutdialog
{
    Q_OBJECT

public:
    explicit aboutdialog(QWidget *parent = nullptr);
};

#endif // ABOUTDIALOG_H
