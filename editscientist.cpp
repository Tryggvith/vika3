#include "editscientist.h"
#include "ui_editscientist.h"
#include <sstream>

editScientist::editScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editScientist)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Female");
    ui->comboBox->addItem("Male");
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
            /*QString gender = currentScientist.getGender();
            QString byear = currentScientist.getbYear();
            QString dyear = currentScientist.getdYear();
            QString nationality = currentScientist.getNation();*/

            ui->table_update_scientist->setItem(row, 0, new QTableWidgetItem(name));
            /*ui->table_Students->setItem(row, 1, new QTableWidgetItem(gender));
            ui->table_Students->setItem(row, 2, new QTableWidgetItem(byear));
            ui->table_Students->setItem(row, 3, new QTableWidgetItem(dyear));
            ui->table_Students->setItem(row, 4, new QTableWidgetItem(nationality));*/
        }
        currentlyDisplayedScientists = pf;
    }

}

void editScientist::on_table_update_scientist_clicked(const QModelIndex &index)
{
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
    ui->input_Scientist_bYear->setText("");
    ui->input_Scientist_bYear->setText(QbYear);
    ui->input_Scientist_dYear->setText("");
    ui->input_Scientist_dYear->setText(QdYear);
    ui->input_Scientist_Nation->setText("");
    ui->input_Scientist_Nation->setText(Qnation);
}

void editScientist::on_button_edit_scientist_dialog_clicked()
{
    string name = ui->input_Scientist_Name->text().toStdString();
    string gender = ui->comboBox->currentText().toStdString();
    string bYear = ui->input_Scientist_bYear->text().toStdString();
    string dYear = ui->input_Scientist_dYear->text().toStdString();
    string nation = ui->input_Scientist_Nation->text().toStdString();
    int currentlySelectedScientistIndex = ui->table_update_scientist->currentIndex().row();
    Performer currentlySelectedScientist = currentlyDisplayedScientists[currentlySelectedScientistIndex];
    int id = currentlySelectedScientist.getId();
    string sId = to_string(id);

    if(name.empty() ||  bYear.empty() || dYear.empty() || nation.empty())
    {
        ui->label_test->setText("<span style='color: red'>No fields can be empty!</span>");

        return;
    }

    bool therewasanError = false;

    int namelength = name.length();

    for(int i = 0 ; i < namelength; i++)
    {

        if(!(isalpha(name[i])) && name[i] != ' ')
        {
            ui->label_empty_error->setText("<span style='color: red'>Invalid input sfafasfa!</span>");

            therewasanError = true;
        }

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
             ui->label_empty_error_3->setText("<span style='color: red'>Death year can not be less than birth year!</span>");
             therewasanError = true;
        }

    int nationlength = nation.length();

    for(int i = 0 ; i < nationlength; i++)
    {
        if(!(isalpha(nation[i])))
        {
            ui->label_empty_error_4->setText("<span style='color: red'>Invalid input!</span>");

            therewasanError = true;
        }
    }

    if(therewasanError)
    {
        return;
    }

    _service.updateScientist(name, gender, bYear, dYear, nation, sId);
    this->done(0);
}

void editScientist::on_button_cancel_clicked()
{
    this->done(0);
}
