#include "addscientistsdialog.h"
#include "ui_addscientistsdialog.h"


AddScientistsDialog::AddScientistsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistsDialog)
{
    ui->setupUi(this);

    ui->comboBox_gender->addItem("Male");
    ui->comboBox_gender->addItem("Female");
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
    ui->label_error->setText("");

    string name = ui->input_Scientist_Name->text().toStdString();
    string gender = ui->comboBox_gender->currentText().toStdString();
    string bYear = ui->input_Scientist_bYear->text().toStdString();
    string dYear = ui->input_Scientist_dYear->text().toStdString();
    string nation = ui->input_Scientist_Nation->text().toStdString();

    if(name.empty() ||  bYear.empty() || dYear.empty() || nation.empty())
    {
        ui->label_error->setText("<span style='color: red'>No fields can be empty!</span>");

        return;
    }

    bool therewasanError = false;

    int namelength = name.length();

    for(int i = 0 ; i < namelength; i++)
    {
        if(!(isalpha(name[i])))
        {
            ui->label_error_name->setText("<span style='color: red'>Invalid input!</span>");

            therewasanError = true;
        }

    }

    int bvalue = atoi(bYear.c_str());
    int bYearLength = bYear.length();

    for(int i = 0; i < bYearLength; i++)
    {
        if(!isdigit(bYear[i]))
        {
            ui->label_error_byear->setText("<span style='color: red'>Invalid input!</span>");
            bYearLength = bYear.length();
            therewasanError = true;
        }
    }
        if(bvalue < 0 || bvalue > 2016)
        {
            ui->label_error_byear->setText("<span style='color: red'>Invalid input!</span>");

            bvalue = atoi(bYear.c_str());
            therewasanError = true;
        }


    int dvalue = atoi(dYear.c_str());
    int dYearLength = dYear.length();
    if(dYear != "--")
    {
        for(int i = 0; i < dYearLength; i++)
        {
            if(!isdigit(dYear[i]))
            {
                ui->label_error_dyear->setText("<span style='color: red'>Invalid input!</span>");
                dYearLength = dYear.length();
                therewasanError = true;
            }
        }
    }

        if(dvalue < 0 || dvalue > 2016)
        {
            ui->label_error_dyear->setText("<span style='color: red'>Invalid input!</span>");

            dvalue = atoi(dYear.c_str());
            therewasanError = true;
        }

        if(dvalue < bvalue && dYear != "--") {
             ui->label_error_dyear->setText("<span style='color: red'>Death year can not be less than birth year!</span>");
             therewasanError = true;
        }

    int nationlength = nation.length();

    for(int i = 0 ; i < nationlength; i++)
    {
        if(!(isalpha(nation[i])))
        {
            ui->label_error_nation->setText("<span style='color: red'>Invalid input!</span>");

            therewasanError = true;
        }
    }

    if(therewasanError)
    {
        return;
    }

    _service.addPerformer(name, gender, bYear, dYear, nation);

    this->done(0);
}
