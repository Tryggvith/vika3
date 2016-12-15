#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "performerservice.h"
#include "dataaccess.h"
#include "addscientistsdialog.h"
#include <QtSql>
#include "addcomputer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void displayStudents();
    void displayComputers();

    void on_combobox_filter_students_activated();

    void on_comboBox_2_activated(const QString &arg1);

    void on_input_scientist_search_textChanged(const QString &arg1);

    void on_line_input_Computer_name_textChanged(const QString &arg1);

    void on_comboBox_filte_Computers_activated(const QString &arg1);

    void on_comboBox_3_activated(const QString &arg1);

    void on_button_Add_Scientists_clicked();

    void on_table_Students_clicked(const QModelIndex &index);

    void on_button_remove_scientist_clicked();

    void on_button_View_All_Connections_clicked();

    void displayAllJoin();

    void on_table_computers_clicked(const QModelIndex &index);

    void on_button_delete_computer_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    PerformerService _service;
    vector<Performer> currentlyDisplayedScientists;
    vector<computers> currentlyDisplayedComputers;
};

#endif // MAINWINDOW_H
