#include "addscientistsdialog.h"
#include "ui_addscientistsdialog.h"


AddScientistsDialog::AddScientistsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistsDialog)
{
    ui->setupUi(this);
}

AddScientistsDialog::~AddScientistsDialog()
{
    delete ui;
}
void AddScientistsDialog::on_button_cancel_Scientist_dialog_clicked()
{
    this->done(0);
}

void AddScientistsDialog::on_button_add_Scientist_dialog_clicked()
{
    ui->label_error_name->setText("");
    ui->label_error_gender->setText("");
    ui->label_error_byear->setText("");
    ui->label_error_dyear->setText("");
    ui->label_error_nation->setText("");

    string name = ui->input_Scientist_Name->text().toStdString();
    string gender = ui->input_scientist_Gender->text().toStdString();
    string bYear = ui->input_Scientist_bYear->text().toStdString();
    string dYear = ui->input_Scientist_dYear->text().toStdString();
    string nation = ui->input_Scientist_Nation->text().toStdString();

    if(name.empty())
    {
        ui->label_error_name->setText("<span style='color: red'>This can not be empty</span>");

        return;
    }
    if(gender.empty())
    {
        ui->label_error_gender->setText("<span style='color: red'>This can not be empty</span>");

        return;
    }
    if(bYear.empty())
    {
        ui->label_error_byear->setText("<span style='color: red'>This can not be empty</span>");

        return;
    }
    if(dYear.empty())
    {
        ui->label_error_dyear->setText("<span style='color: red'>This can not be empty</span>");

        return;
    }
    if(nation.empty())
    {
        ui->label_error_nation->setText("<span style='color: red'>This can not be empty</span>");

        return;
    }

    _service.addPerformer(name, gender, bYear, dYear, nation);

    this->done(0);
}
