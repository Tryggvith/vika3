#include "editcomputer.h"
#include "ui_editcomputer.h"
#include <sstream>

editcomputer::editcomputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcomputer)
{
    ui->setupUi(this);
    ui->comboBox_constr->addItem("Yes");
    ui->comboBox_constr->addItem("No");
    displayUpdateTable();
}

editcomputer::~editcomputer()
{
    delete ui;
}
void editcomputer::displayUpdateTable()
{
    {
        vector<computers> pf = _service.updateTableComputer();
        ui->table_update_computer->clearContents();
        ui->table_update_computer->setRowCount(pf.size());
        for(unsigned int row = 0; row < pf.size(); row++)
        {
            computers currentComputer = pf[row];

            QString name = currentComputer.getName();


            ui->table_update_computer->setItem(row, 0, new QTableWidgetItem(name));

        }
        currentlyDisplayedComputers = pf;
    }

}

void editcomputer::on_table_update_computer_clicked(const QModelIndex &index)
{
    int currentlySelectedComputerIndex = ui->table_update_computer->currentIndex().row();
    computers currentlySelectedComputer = currentlyDisplayedComputers[currentlySelectedComputerIndex];


    string name = currentlySelectedComputer.getName().toStdString();
    string buildy = currentlySelectedComputer.getBuildy().toStdString();
    string brand = currentlySelectedComputer.getBrand().toStdString();
    string constr = currentlySelectedComputer.getConstr().toStdString();

    QString Qname = QString::fromStdString(name);
    QString Qbuildy = QString::fromStdString(buildy);
    QString Qbrand = QString::fromStdString(brand);
    QString Qconstr = QString::fromStdString(constr);

    ui->input_Computer_Name->setText("");
    ui->input_Computer_Name->setText(Qname);
    ui->input_Computer_buildy->setText("");
    ui->input_Computer_buildy->setText(Qbuildy);
    ui->input_Computer_Model->setText("");
    ui->input_Computer_Model->setText(Qbrand);
    ui->comboBox_constr->currentText();
    ui->comboBox_constr->setCurrentText(Qconstr);

}

void editcomputer::on_button_edit_computer_dialog_clicked()
{
    string name = ui->input_Computer_Name->text().toStdString();
    string constr = ui->comboBox_constr->currentText().toStdString();
    string buildy = ui->input_Computer_buildy->text().toStdString();
    string brand = ui->input_Computer_Model->text().toStdString();

    bool therewasanError = false;
    int currentlySelectedComputerIndex = ui->table_update_computer->currentIndex().row();
    computers currentlySelectedComputer = currentlyDisplayedComputers[currentlySelectedComputerIndex];
    int id = currentlySelectedComputer.getId();
    string cId = to_string(id);

        if(name.empty() || buildy.empty())
        {
            ui->label_error_name->setText("<span style='color: red'>No fields can be empty!</span>");
            therewasanError = true;
            return;
        }
        if(checkInput(name))
            {
                ui->label_error_name->setText("<span style='color: red'>Invalid input!</span>");
                therewasanError = true;
            }
            else {
                  ui->label_error_name->setText("<span style='color: red'></span>");
            }

            int bvalue = atoi(buildy.c_str());
            int bYearLength = buildy.length();

            if(constr == "Yes")
            {
                for(int i = 0; i < bYearLength; i++)
                {
                    if(!isdigit(buildy[i]))
                    {
                        ui->label_error_buildYear->setText("<span style='color: red'>Invalid input!</span>");
                        bYearLength = buildy.length();
                        therewasanError = true;
                    }
                }
            }

            if(bvalue < 0 || bvalue > 2016)
            {
                 ui->label_error_buildYear->setText("<span style='color: red'>Invalid input!</span>");

                  bvalue = atoi(buildy.c_str());
                  therewasanError = true;
             }

             if(therewasanError)
             {
                return;
             }

             if(!therewasanError)
              {
                 _service.updateComputer(name, buildy, brand, constr, cId);
                 this->done(0);
              }
        }

/*    _service.updateComputer(name, buildy, brand, constr, sId);
    this->done(0);*/


void editcomputer::on_button_cancel_clicked()
{
    this->done(0);
}

void editcomputer::on_comboBox_constr_activated(const QString &arg1)
{
    QVariant a = arg1;
    string constr = ui->comboBox_constr->currentText().toStdString();
    if(constr == "Yes")
    {
        ui->input_Computer_buildy->setEnabled(true);
        ui->input_Computer_buildy->setText("");
    }
    else
    {
        ui->input_Computer_buildy->setEnabled(false);
        ui->input_Computer_buildy->setText("--");
    }
}

bool editcomputer::checkInput(string input)
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
