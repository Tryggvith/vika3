#ifndef ADDSCIENTISTSDIALOG_H
#define ADDSCIENTISTSDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "performerservice.h"

namespace Ui {
class AddScientistsDialog;
}

class AddScientistsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddScientistsDialog(QWidget *parent = 0);
    ~AddScientistsDialog();

private slots:

    void on_button_cancel_Scientist_dialog_clicked();

    void on_button_add_Scientist_dialog_clicked();

private:
    Ui::AddScientistsDialog *ui;
    PerformerService _service;
};

#endif // ADDSCIENTISTSDIALOG_H
