#include "addconnectiondialog.h"
#include "ui_addconnectiondialog.h"

AddConnectionDialog::AddConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddConnectionDialog)
{
    ui->setupUi(this);
    displayTable();
}

AddConnectionDialog::~AddConnectionDialog()
{
    delete ui;
}

void AddConnectionDialog::on_pushButton_2_clicked()
{
    this->done(0);
}

void AddConnectionDialog::displayTable()
{
    vector<RelationsTable> pf = _service.readData();
    ui->table_Computers->clearContents();
    ui->table_Computers->setRowCount(pf.size());
    for(unsigned int row = 0; row < pf.size(); row++)
    {
        RelationsTable currentJoin = pf[row];
        QString sId = QString::number(currentJoin.getSId());
        QString sName = currentJoin.getSName();
        QString cId = QString::number(currentJoin.getCId());
        QString cName = currentJoin.getCName();

        ui->table_Computers->setItem(row, 0, new QTableWidgetItem(sId));
        ui->table_Computers->setItem(row, 1, new QTableWidgetItem(sName));
        ui->table_Computers->setItem(row, 2, new QTableWidgetItem(cId));
        ui->table_Computers->setItem(row, 3, new QTableWidgetItem(cName));
    }
}

void AddConnectionDialog::on_pushButton_clicked()
{
    QString sId = ui->input_Scientists_id->text();
    QString cId = ui->Input_Computers_id->text();
    _service.addRelations(sId, cId);
    this->done(0);
}
