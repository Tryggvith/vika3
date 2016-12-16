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

void AddScientistsDialog::on_button_add_Scientist_dialog_clicked()//Sækir input frá user sem er sent áfram í performerservice sem fer síðan í dataaccess
{
    ui->label_error->setText("");

    string name = ui->input_Scientist_Name->text().toStdString();
    string gender = ui->comboBox_gender->currentText().toStdString();
    string bYear = ui->input_Scientist_bYear->text().toStdString();
    string dYear = ui->input_Scientist_dYear->text().toStdString();
    string nation = ui->input_Scientist_Nation->text().toStdString();
    bool therewasanError = false;

    if(name.empty() ||  bYear.empty() || dYear.empty() || nation.empty())
    {
        ui->label_error->setText("<span style='color: red'>No fields can be empty!</span>");
        therewasanError = true;

        return;
    }

    int namelength = name.length();

    bool founderrorname = false;

    for(int i = 0 ; i < namelength; i++)
    {
        if(!(isalpha(name[i])) && name[i] != ' ')
        {
            founderrorname = true;
        }
    }
         if(checkInput(name))
         {
             founderrorname = true;
         }
         if(founderrorname)
         {
             ui->label_error_name->setText("<span style='color: red'>Invalid input!</span>");
             therewasanError = true;
         }
         else
         {
             ui->label_error_name->setText("<span style='color: red'></span>");
         }


    bool founderrorbyear = false;
    int bvalue = atoi(bYear.c_str());//streng breytt í int
    int bYearLength = bYear.length();

    for(int i = 0; i < bYearLength; i++)
    {
        if(!isdigit(bYear[i]))
        {
            bYearLength = bYear.length();
            founderrorbyear = true;
        }

    }
        if(bvalue < 0 || bvalue > 2016)
        {

            bvalue = atoi(bYear.c_str());//streng breytt í int
            founderrorbyear = true;
        }

        if(founderrorbyear)
        {
            ui->label_error_byear->setText("<span style='color: red'>Invalid input!</span>");
            therewasanError = true;
        }
        else
        {
            ui->label_error_byear->setText("<span style='color: red'></span>");
        }


    bool founderrordyear = false;
    int dvalue = atoi(dYear.c_str());//streng breytt í int
    int dYearLength = dYear.length();
    if(dYear != "--")
    {
        for(int i = 0; i < dYearLength; i++)
        {
            if(!isdigit(dYear[i]))
            {
                dYearLength = dYear.length();
                founderrordyear= true;
            }
        }
    }
        if(dvalue < 0 || dvalue > 2016)
        {
            dvalue = atoi(dYear.c_str());
            founderrordyear = true;
        }

        if(dvalue < bvalue && dYear != "--")
        {
             founderrordyear = true;
        }
        if(founderrordyear)
        {
            ui->label_error_dyear->setText("<span style='color: red'>Invalid input!</span>");
            therewasanError = true;
        }
        else
        {
            ui->label_error_dyear->setText("<span style='color: red'></span>");
        }

    bool founderrornation = false;
    int nationlength = nation.length();

    for(int i = 0 ; i < nationlength; i++)
    {
        if(!(isalpha(nation[i])) && nation[i] != ' ')
        {
            founderrornation = true;
        }
    }

    if(checkInput(nation))
    {
        founderrornation = true;
    }

       if(founderrornation)
      {
        ui->label_error_nation->setText("<span style='color: red'>Invalid input!</span>");
        therewasanError = true;
      }
       else
       {
           ui->label_error_nation->setText("<span style='color: red'></span>");
       }

    if(therewasanError)
    {
        return;
    }

    if(!therewasanError)
    {
        _service.addPerformer(name, gender, bYear, dYear, nation);
         this->done(0);
    }
}

bool AddScientistsDialog::checkInput(string input)//Athugar hvort input sé tómt.
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

