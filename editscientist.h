#ifndef EDITSCIENTIST_H
#define EDITSCIENTIST_H

#include <QDialog>
#include "performerservice.h"

using namespace std;

namespace Ui {
class editScientist;
}

class editScientist : public QDialog
{
    Q_OBJECT

public:
    explicit editScientist(QWidget *parent = 0);
    ~editScientist();
    bool checkInput(string input);
private slots:
    void displayUpdateTable();

    void on_table_update_scientist_clicked(const QModelIndex &index);

    void on_button_edit_scientist_dialog_clicked();

    void on_button_cancel_clicked();

private:
    Ui::editScientist *ui;
    PerformerService _service;
    vector<Performer> currentlyDisplayedScientists;
};

#endif // EDITSCIENTIST_H
