#include "editscientist.h"
#include "ui_editscientist.h"
#include <sstream>

editScientist::editScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editScientist)
{
    ui->setupUi(this);
    ui->comboBox_gender->addItem("Female");
    ui->comboBox_gender->addItem("Male");
    displayUpdateTable();
}

editScientist::~editScientist()
{
    delete ui;
}
void editScientist::displayUpdateTable()
{
    {
        vector<Performer> pf = _service.updateTableScientist();
        ui->table_update_scientist->clearContents();
        ui->table_update_scientist->setRowCount(pf.size());
        for(unsigned int row = 0; row < pf.size(); row++)
        {
            Performer currentScientist = pf[row];

            QString name = currentScientist.getName();

            ui->table_update_scientist->setItem(row, 0, new QTableWidgetItem(name));
        }
        currentlyDisplayedScientists = pf;
    }

}

void editScientist::on_table_update_scientist_clicked(const QModelIndex &index)
{
    QVariant a = index;
    int currentlySelectedScientistIndex = ui->table_update_scientist->currentIndex().row();
    Performer currentlySelectedScientist = currentlyDisplayedScientists[currentlySelectedScientistIndex];


    string name = currentlySelectedScientist.getName().toStdString();
    string gender = currentlySelectedScientist.getGender().toStdString();
    string bYear = currentlySelectedScientist.getbYear().toStdString();
    string dYear = currentlySelectedScientist.getdYear().toStdString();
    string nation = currentlySelectedScientist.getNation().toStdString();

    QString Qname = QString::fromStdString(name);
    QString Qgender = QString::fromStdString(gender);
    QString QbYear = QString::fromStdString(bYear);
    QString QdYear = QString::fromStdString(dYear);
    QString Qnation = QString::fromStdString(nation);

    ui->input_Scientist_Name->setText("");
    ui->input_Scientist_Name->setText(Qname);
    ui->comboBox_gender->currentText();
    ui->input_Scientist_bYear->setText("");
    ui->input_Scientist_bYear->setText(QbYear);
    ui->input_Scientist_dYear->setText("");
    ui->input_Scientist_dYear->setText(QdYear);
    ui->input_Scientist_Nation->setText("");
    ui->input_Scientist_Nation->setText(Qnation);

    ui->input_Scientist_bYear->setEnabled(true);
    ui->comboBox_gender->setEnabled(true);
    ui->input_Scientist_dYear->setEnabled(true);
    ui->input_Scientist_Name->setEnabled(true);
    ui->input_Scientist_Nation->setEnabled(true);
    ui->button_edit_scientist_dialog->setEnabled(true);
}

void editScientist::on_button_edit_scientist_dialog_clicked()
{
    string name = ui->input_Scientist_Name->text().toStdString();
    string gender = ui->comboBox_gender->currentText().toStdString();
    string bYear = ui->input_Scientist_bYear->text().toStdString();
    string dYear = ui->input_Scientist_dYear->text().toStdString();
    string nation = ui->input_Scientist_Nation->text().toStdString();
    int currentlySelectedScientistIndex = ui->table_update_scientist->currentIndex().row();
    Performer currentlySelectedScientist = currentlyDisplayedScientists[currentlySelectedScientistIndex];
    int id = currentlySelectedScientist.getId();
    string sId = to_string(id);

    bool therewasanError = false;

    if(name.empty() ||  bYear.empty() || dYear.empty() || nation.empty())
    {
        ui->label_test->setText("<span style='color: red'>No fields can be empty!</span>");
        therewasanError = true;

        return;
    }

    int namelength = name.length();

    for(int i = 0 ; i < namelength; i++)
    {
         if(!(isalpha(name[i])) && name[i] != ' ')
        {
            ui->label_empty_error->setText("<span style='color: red'>Invalid input!</span>");

            therewasanError = true;
        }
         else
         {
             ui->label_empty_error->setText("<span style='color: red'></span>");
         }
    }

         if(checkInput(name))
         {
             ui->label_empty_error->setText("<span style='color: red'>Invalid input!</span>");
             therewasanError = true;
         }
         else
         {
             ui->label_empty_error->setText("<span style='color: red'></span>");
         }


    int bvalue = atoi(bYear.c_str());
    int bYearLength = bYear.length();

    for(int i = 0; i < bYearLength; i++)
    {
        if(!isdigit(bYear[i]))
        {
            ui->label_empty_error_2->setText("<span style='color: red'>Invalid input!</span>");
            bYearLength = bYear.length();
            therewasanError = true;
        }

    }
        if(bvalue < 0 || bvalue > 2016)
        {
            ui->label_empty_error_2->setText("<span style='color: red'>Invalid input!</span>");
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
                ui->label_empty_error_3->setText("<span style='color: red'>Invalid input!</span>");
                dYearLength = dYear.length();
                therewasanError = true;
            }
        }
    }

        if(dvalue < 0 || dvalue > 2016)
        {
            ui->label_empty_error_3->setText("<span style='color: red'>Invalid input!</span>");

            dvalue = atoi(dYear.c_str());
            therewasanError = true;
        }

        if(dvalue < bvalue && dYear != "--") {
             ui->label_empty_error_3->setText("<span style='color: red'>Invalid input!</span>");
             therewasanError = true;
        }

    int nationlength = nation.length();

    for(int i = 0 ; i < nationlength; i++)
    {
        if(!(isalpha(nation[i])) && nation[i] != ' ')
        {
            ui->label_empty_error_4->setText("<span style='color: red'>Invalid input!</span>");
            therewasanError = true;
        }
        else
        {
            ui->label_empty_error_4->setText("<span style='color: red'></span>");
        }
    }

   if(checkInput(nation))
    {
        ui->label_empty_error_4->setText("<span style='color: red'>Invalid input!</span>");
        therewasanError = true;
    }
    else
    {
        ui->label_empty_error_4->setText("<span style='color: red'></span>");

    }

    if(therewasanError)
    {
        return;
    }

    if(!therewasanError)
    {
        _service.updateScientist(name, gender, bYear, dYear, nation, sId);
         this->done(0);
    }
}

void editScientist::on_button_cancel_clicked()
{
    this->done(0);
}

bool editScientist::checkInput(string input)
{
    bool allTrue = true;
    bool allFalse = true;
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == ' ')
        {
            allFalse = false;
        }
        else
        {
            allTrue = false;
        }
    }
    return allTrue;
}
