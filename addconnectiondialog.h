#ifndef ADDCONNECTIONDIALOG_H
#define ADDCONNECTIONDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "performerservice.h"

namespace Ui {
class AddConnectionDialog;
}

class AddConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddConnectionDialog(QWidget *parent = 0);
    ~AddConnectionDialog();

private slots:
    void on_pushButton_2_clicked();

    void displayTable();

    void on_pushButton_clicked();

private:
    Ui::AddConnectionDialog *ui;
    PerformerService _service;
};

#endif // ADDCONNECTIONDIALOG_H
