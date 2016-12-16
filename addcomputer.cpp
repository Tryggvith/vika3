#include "addcomputer.h"
#include "ui_addcomputer.h"

AddComputer::AddComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputer)
{
    ui->setupUi(this);

    ui->comboBox_constr->addItem("Yes");
    ui->comboBox_constr->addItem("No");

    ui->comboBox_type->addItem("Mechanical");
    ui->comboBox_type->addItem("Electronic");
    ui->comboBox_type->addItem("Electromechanical");
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
    string name = ui->Input_Computer_Name->text().toStdString();
    string type = ui->comboBox_type->currentText().toStdString();
    string constr = ui->comboBox_constr->currentText().toStdString();
    string buildy = ui->Input_Computer_Year->text().toStdString();


    bool therewasanError = false;

    if(name.empty() || buildy.empty())
    {
        ui->label_error->setText("<span style='color: red'>No fields can be empty!</span>");

        return;
    }

    int bvalue = atoi(buildy.c_str());
    int bYearLength = buildy.length();

    if(constr == "Yes")
    {
        for(int i = 0; i < bYearLength; i++)
        {
            if(!isdigit(buildy[i]))
            {
                ui->label_error_buildy->setText("<span style='color: red'>Invalid input!</span>");
                bYearLength = buildy.length();
                therewasanError = true;
            }
        }
        if((bvalue < 0 || bvalue > 2016))
        {
            ui->label_error_buildy->setText("<span style='color: red'>Invalid input!</span>");

            bvalue = atoi(buildy.c_str());
            therewasanError = true;
        }
    }

        if(therewasanError)
        {
            return;
        }

    _service.addComputer(name, buildy, type, constr);
    this->done(0);
}

void AddComputer::on_comboBox_constr_activated(const QString &arg1)
{
    QVariant a = arg1;
    string constr = ui->comboBox_constr->currentText().toStdString();
    if(constr == "Yes")
    {
        ui->Input_Computer_Year->setEnabled(true);
        ui->Input_Computer_Year->setText("");
    }
    else
    {
        ui->Input_Computer_Year->setEnabled(false);
        ui->Input_Computer_Year->setText("--");
    }
}
