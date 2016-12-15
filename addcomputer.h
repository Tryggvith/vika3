#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H


#include <QDialog>
#include "performerservice.h"
#include "mainwindow.h"

namespace Ui {
class AddComputer;
}

class AddComputer : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputer(QWidget *parent = 0);
    ~AddComputer();

private slots:
    void on_Button_Cancel_Add_clicked();

    void on_Button_Add_Computer_clicked();

    void on_comboBox_constr_currentTextChanged(bool checked);

private:
    Ui::AddComputer *ui;
    PerformerService _service;
};

#endif // ADDSCIENTISTDIALOG_H
