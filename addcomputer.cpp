#include "addcomputer.h"
#include "ui_addcomputer.h"

AddComputer::AddComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputer)
{
    ui->setupUi(this);
}

AddComputer::~AddComputer()
{
    delete ui;
}

void AddComputer::on_Button_Cancel_Add_clicked()
{
    this->done(0);
}

void AddComputer::on_Button_Add_Computer_clicked()
{
    string name = ui->Input_Computer_Type->text().toStdString();
    string buildy = ui->Input_Computer_Year->text().toStdString();
    string brand = ui->Input_Computer_Model->text().toStdString();
    string constr = ui->Input_Computer_Yes->text().toStdString();

    if(name.empty() || buildy.empty() || brand.empty() || constr.empty())
    {
        ui->label_error->setText("<span style='color: red'>No fields can be empty!</span>");

        return;
    }

    _service.addComputer(name, buildy, brand, constr);
    this->done(0);
}


void AddComputer::on_Input_Computer_Yes_toggled(bool checked)
{
   ui->Input_Computer_Year->setEnabled(true);
}
