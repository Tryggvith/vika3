#include "addconnectiondialog.h"
#include "ui_addconnectiondialog.h"
#include <QDesktopWidget>

AddConnectionDialog::AddConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddConnectionDialog)
{
    ui->setupUi(this);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
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
    vector<RelationsTable2> pf = _service.viewScientist(1);
    vector<RelationsTable2> cp = _service.viewScientist(2);
    QString sId = ui->input_Scientists_id->text();
    QString cId = ui->Input_Computers_id->text();
    if(!checkID(pf,sId) && !checkID(cp, cId))
    {
        ui->label_error->setText("<span style='color: red'>Scientist ID and Computer ID not valid!</span>");
    }
    else if(!checkID(pf, sId))
    {
        ui->label_error->setText("<span style='color: red'>Scientist ID not valid!</span>");
    }
    else if(!checkID(cp, cId))
    {
        ui->label_error->setText("<span style='color: red'>Computer ID not valid!</span>");
    }
    else{
    _service.addRelations(sId, cId);
    this->done(0);
    }
}

bool AddConnectionDialog::checkID(vector<RelationsTable2> info, QString ID)
{
    bool found2 = false;
    string choice = ID.toStdString();
    int value;


        value = atoi(choice.c_str());
        for(size_t i = 0; i < info.size(); i++){

            if(info[i].getSId()== value)
            {
                found2 = true;
            }
        }
    return found2;
}
