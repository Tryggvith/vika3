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

void AddComputer::on_Button_Cancel_Add_clicked()//Fall sem að tengist beint takka sem búin var til í UI, notaður til að hætta við að setja inn nýjan tölvunarfræðing
{
    this->done(0);
}

void AddComputer::on_Button_Add_Computer_clicked()//Fall sem að tengist beint takka sem búin var til í UI, sækir upplýsingar um tölvu og uppfærir á lista
{
    string name = ui->Input_Computer_Name->text().toStdString();
    string type = ui->comboBox_type->currentText().toStdString();
    string constr = ui->comboBox_constr->currentText().toStdString();
    string buildy = ui->Input_Computer_Year->text().toStdString();


    bool therewasanError = false;

    if(name.empty() || buildy.empty())
    {
        ui->label_error->setText("<span style='color: red'>No fields can be empty!</span>");
        therewasanError = true;
        return;
    }

    bool founderrorname = false;

    if(checkInput(name))
    {
        founderrorname = true;
    }
    if(founderrorname)
    {
         ui->name_error->setText("<span style='color: red'>Invalid input!</span>");
         therewasanError = true;
    }
    else
    {
         ui->name_error->setText("<span style='color: red'></span>");
    }

    bool founderrorbyear = false;
    int bvalue = atoi(buildy.c_str());
    int bYearLength = buildy.length();

    if(constr == "Yes")
    {
        for(int i = 0; i < bYearLength; i++)
        {
            if(!isdigit(buildy[i]))
            {
                bYearLength = buildy.length();
                founderrorbyear = true;
            }
        }
    }

    if(bvalue < 0 || bvalue > 2016)
    {
          bvalue = atoi(buildy.c_str());
          founderrorbyear = true;
     }
    if(founderrorbyear)
    {
        ui->label_error_buildy->setText("<span style='color: red'>Invalid input!</span>");
        therewasanError = true;
    }
    else
    {
        ui->label_error_buildy->setText("<span style='color: red'></span>");
    }

     if(therewasanError)
     {
        return;
     }

     if(!therewasanError)
      {
         _service.addComputer(name, buildy, type, constr);
         this->done(0);
      }
}

bool AddComputer::checkInput(string input)//Fall sem passar að strengur geti ekki verið tómur (Villutékk)
{
    bool allTrue = true;

    for(unsigned int i = 0; i < input.length(); i++)
    {
        if(input[i] == ' ')
        {
            allTrue = false;
        }
        else
        {
            allTrue = false;
        }
    }

    return allTrue;
}

void AddComputer::on_comboBox_constr_activated(const QString &arg1)//Fall sem að tengist beint UI takka sem búin var til, gerir notanda kleyft að velja á milli strengja og skila þeim út
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
