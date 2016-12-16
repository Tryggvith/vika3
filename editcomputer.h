#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H


#include <QDialog>
#include "performerservice.h"

using namespace std;

namespace Ui {
class editcomputer;
}

class editcomputer : public QDialog
{
    Q_OBJECT

public:
    explicit editcomputer(QWidget *parent = 0);
    ~editcomputer();
    bool checkInput(string input);

private slots:
    void displayUpdateTable();

    void on_table_update_computer_clicked(const QModelIndex &index);

    void on_button_edit_computer_dialog_clicked();

    void on_button_cancel_clicked();

    void on_comboBox_constr_activated(const QString &arg1);


private:
    Ui::editcomputer *ui;
    PerformerService _service;
    vector<computers> currentlyDisplayedComputers;
};

#endif // EDITCOMPUTER_H
