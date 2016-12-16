#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    displayIntro();
    ui->setupUi(this);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
    ui->combobox_filter_students->addItem("Filter by name");
    ui->combobox_filter_students->addItem("Filter by gender");
    ui->combobox_filter_students->addItem("Filter by birth year");
    ui->combobox_filter_students->addItem("Filter by death year");
    ui->combobox_filter_students->addItem("Filter by nationality");
    ui->comboBox_2->addItem("ASC");
    ui->comboBox_2->addItem("DESC");

    ui->comboBox_filte_Computers->addItem("Filter by computer name");
    ui->comboBox_filte_Computers->addItem("Filter by year computer was built");
    ui->comboBox_filte_Computers->addItem("Filter by type of computer");
    ui->comboBox_filte_Computers->addItem("Filter by if computer was ever built");
    ui->comboBox_3->addItem("ASC");
    ui->comboBox_3->addItem("DESC");

    _service.openFiles();
    string id = "";
    displayScientistsJoin(id);
    displayComputersJoin(id);
    displayAllJoin();
    displayStudents();
    displayComputers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayStudents() // tökum input frá user og hendum því í fall sem er í Performerservice og fáum til baka vektor sem við setjum svo í töflu.
{
    string input = ui->combobox_filter_students->currentText().toStdString();
    if (input == "Filter by birth year")
    {
        input = "bYear";
    }
    else if (input == "Filter by nationality")
    {
        input = "nation";
    }
    else if (input == "Filter by death year")
    {
        input = "dYear";
    }
    else if (input == "Filter by name")
    {
        input = "name";
    }
    else if (input == "Filter by gender")
    {
        input = "gender";
    }
    string input2 = ui->comboBox_2->currentText().toStdString();
    string input3 = ui->input_scientist_search->text().toStdString();
    vector<Performer> pf = _service.sortScientists(input, input2, input3);
    ui->table_Students->clearContents();
    ui->table_Students->setRowCount(pf.size());
    for(unsigned int row = 0; row < pf.size(); row++)
    {
        Performer currentScientist = pf[row];

        QString name = currentScientist.getName();
        QString gender = currentScientist.getGender();
        QString byear = currentScientist.getbYear();
        QString dyear = currentScientist.getdYear();
        QString nationality = currentScientist.getNation();

        ui->table_Students->setItem(row, 0, new QTableWidgetItem(name));
        ui->table_Students->setItem(row, 1, new QTableWidgetItem(gender));
        ui->table_Students->setItem(row, 2, new QTableWidgetItem(byear));
        ui->table_Students->setItem(row, 3, new QTableWidgetItem(dyear));
        ui->table_Students->setItem(row, 4, new QTableWidgetItem(nationality));
    }
    currentlyDisplayedScientists = pf;
}

void MainWindow::displayComputers() //tökum input frá user og hendum því í fall sem er í PerformerService og fáum til baka vektor sem við setjum svo í töflu.
{
    string input = ui->comboBox_filte_Computers->currentText().toStdString();

    if (input == "Filter by type of computer")
    {
        input = "Type";
    }
    else if (input == "Filter by computer name")
    {
        input = "Name";
    }
    else if (input == "Filter by year computer was built")
    {
        input = "BuildY";
    }
    else if (input == "Filter by if computer was ever built")
    {
        input = "Constr";
    }
    string input2 = ui->comboBox_3->currentText().toStdString();
    string input3 = ui->line_input_Computer_name->text().toStdString();
    vector<computers> pf = _service.sortComputers(input, input2, input3);
    ui->table_computers->clearContents();
    ui->table_computers->setRowCount(pf.size());
    for(unsigned int row = 0; row < pf.size(); row++)
    {
        computers currentComp = pf[row];

        QString name = currentComp.getName();
        QString byear = currentComp.getBuildy();
        QString brand = currentComp.getBrand();
        QString constr = currentComp.getConstr();

        ui->table_computers->setItem(row, 0, new QTableWidgetItem(name));
        ui->table_computers->setItem(row, 1, new QTableWidgetItem(byear));
        ui->table_computers->setItem(row, 2, new QTableWidgetItem(brand));
        ui->table_computers->setItem(row, 3, new QTableWidgetItem(constr));

    }
    currentlyDisplayedComputers = pf;
}

void MainWindow::on_combobox_filter_students_activated() //þegar skipt er um filter þá er displayFallið kallað.
{
    displayStudents();
}

void MainWindow::on_comboBox_2_activated(const QString &arg1) // Sama er gert með þetta combobox og gert var í fallinu að ofan.
{
    QVariant a = arg1;
    displayStudents();
}

void MainWindow::on_input_scientist_search_textChanged(const QString &arg1) // þegar notandinn slær inn input þá er kallað á fallið.
{
    QVariant a = arg1;
    displayStudents();
}

void MainWindow::on_line_input_Computer_name_textChanged(const QString &arg1) // sama er gert með þetta og gert er í fallinu að ofan.
{
    QVariant a = arg1;
    displayComputers();
}

void MainWindow::on_comboBox_filte_Computers_activated(const QString &arg1) // þetta er það sama og gert er í Scientists.
{
    QVariant a = arg1;
    displayComputers();
}

void MainWindow::on_comboBox_3_activated(const QString &arg1) // þetta er það sama og gert er í Scientists.
{
    QVariant a = arg1;
    displayComputers();
}

void MainWindow::on_button_Add_Scientists_clicked() // Þegar ýtt er á takkann button_add_scientists lætur fallið opna nýjan UI glugga, þegar glugginn er hættur að keyra disablear hann takka og displayar nýja vísindamanninn sem var bætt við.
{
    AddScientistsDialog addScientistsDialog;
    addScientistsDialog.exec();
    ui->button_remove_scientist->setEnabled(false);
    displayStudents();
}

void MainWindow::on_table_Students_clicked(const QModelIndex &index) // þegar ýtt er á nafn í töflunni enablear forritið takka.
{
    QVariant a = index;
    ui->button_remove_scientist->setEnabled(true);
}

void MainWindow::on_button_remove_scientist_clicked() // þegar ýtt er á takkann remove Scientists spyr forritið hvort að notandinn vilji eyða og tekur það input sem notandinn velur ef það er yes þá eyðir forritið þeim vísindamanni sem er selected.
{
    int reply = QMessageBox::question(this, "Warning", "Are you sure you want to delete the selected scientist?");

    if(reply == QMessageBox::Yes)
    {
        int currentlySelectedScientistIndex = ui->table_Students->currentIndex().row();


        Performer currentlySelectedScientist = currentlyDisplayedScientists[currentlySelectedScientistIndex];


        string name = currentlySelectedScientist.getName().toStdString();
        ui->label_test->setText(currentlySelectedScientist.getName()+ " was deleted!");
        _service.removeScientist(name);
        ui->button_remove_scientist->setEnabled(false);
        displayStudents();
    }
    else
    {
        ui->button_remove_scientist->setEnabled(false);
    }
}

void MainWindow::displayAllJoin() // þetta fall sækir í fall í performerService og skilar vector, síðan er sýnt vectorinn i töflu.
{
    vector<RelationsID> pf = _service.viewJoin();
    ui->table_View_join_Connections->clearContents();
    ui->table_View_join_Connections->setRowCount(pf.size());
    for(unsigned int row = 0; row < pf.size(); row++)
    {
        RelationsID currentJoin = pf[row];
        QString id = QString::number(currentJoin.get_id());
        QString cName = currentJoin.get_cName();
        QString sName = currentJoin.get_SName();

        ui->table_View_join_Connections->setItem(row, 0, new QTableWidgetItem(id));
        ui->table_View_join_Connections->setItem(row, 1, new QTableWidgetItem(sName));
        ui->table_View_join_Connections->setItem(row, 2, new QTableWidgetItem(cName));
    }
    currentlyDisplayedConnections = pf;
}

void MainWindow::on_table_computers_clicked(const QModelIndex &index) // þegar ýtt er á nafn í töflunni enablear forritið takka
{
     QVariant a = index;
     ui->button_delete_computer->setEnabled(true);
}

void MainWindow::on_button_delete_computer_clicked() // þegar ýtt er á takkann remove Computer spyr forritið hvort að notandinn vilji eyða og tekur það input sem notandinn velur ef það er yes þá eyðir forritið þeirri tölvu sem er selected
{
    int reply = QMessageBox::question(this, "Warning", "Are you sure you want to delete the selected computer?");

    if(reply == QMessageBox::Yes)
    {
        int currentlySelectedComputerIndex = ui->table_computers->currentIndex().row();

        computers currentlySelectedComputer = currentlyDisplayedComputers[currentlySelectedComputerIndex];

        string name = currentlySelectedComputer.getName().toStdString();
        ui->label_test->setText(currentlySelectedComputer.getName()+ " was deleted!");
        _service.removeComputer(name);
        displayComputers();
    }
    else
    {
        ui->button_remove_scientist->setEnabled(false);
    }
}

void MainWindow::on_button_add_computer_clicked() // þegar ýtt er á takkann add Computer þá keyrir forritið glugga, þegar forritið er hætt að keyra mun keyra disablear hann takka og displayar nýju tölvuna sem var bætt við
{
    AddComputer addcomputer;
    addcomputer.exec();
    ui->button_delete_computer->setEnabled(false);
    displayComputers();
}

void MainWindow::on_button_edit_scientist_clicked() // þetta fall keyrir glugga og enablear takka og displayar table þegar keyrslu er hætt.
{
    editScientist EditScientist;
    EditScientist.exec();
    ui->button_remove_scientist->setEnabled(false);
    displayStudents();
}

void MainWindow::on_button_edit_computer_clicked() // þetta fall keyrir glugga og enablear takka og displayar table þegar keyrslu er hætt.
{
    editcomputer EditComputer;
    EditComputer.exec();
    ui->button_delete_computer->setEnabled(false);
    displayComputers();
}

void MainWindow::displayScientistsJoin(string id) // þetta fall skilar id og CS og fær til baka vector, sem svo sýnir vectorinn á töflu.
{
    string CS = "s.name";
    vector<Relations> pf = _service.startJoin(CS, id);
    ui->table_Scientists_Computer->clearContents();
    ui->table_Scientists_Computer->setRowCount(pf.size());
    for(unsigned int row = 0; row < pf.size(); row++)
    {
        Relations currentJoin = pf[row];
        QString cName = currentJoin.getCName();
        QString sName = currentJoin.getSName();

        ui->table_Scientists_Computer->setItem(row, 0, new QTableWidgetItem(sName));
        ui->table_Scientists_Computer->setItem(row, 1, new QTableWidgetItem(cName));
    }
}

void MainWindow::on_Input_Computer_id_textChanged(const QString &arg1) // þegar texta er breytt mun hann taka þann streng og setja í annað fall og lætur það fall keyra.
{
    QVariant a = arg1;
    string id = ui->Input_Computer_id->text().toStdString();
    displayComputersJoin(id);
}

void MainWindow::on_input_Scientists_id_textChanged(const QString &arg1) // þegar texta er breytt mun hann taka þann streng og setja í annað fall og lætur það fall keyra.
{
    QVariant a = arg1;
    string id = ui->input_Scientists_id->text().toStdString();
    displayScientistsJoin(id);
}

void MainWindow::displayComputersJoin(string id) // þetta fall skilar id og CS og fær til baka vector, sem svo sýnir vectorinn á töflu.
{
    string CS = "C.name";
    vector<Relations> pf = _service.startJoin(CS, id);
    ui->table_Computer_Scientists->clearContents();
    ui->table_Computer_Scientists->setRowCount(pf.size());
    for(unsigned int row = 0; row < pf.size(); row++)
    {
        Relations currentJoin = pf[row];
        QString cName = currentJoin.getCName();
        QString sName = currentJoin.getSName();

        ui->table_Computer_Scientists->setItem(row, 1, new QTableWidgetItem(sName));
        ui->table_Computer_Scientists->setItem(row, 0, new QTableWidgetItem(cName));
    }
}

void MainWindow::on_table_View_join_Connections_clicked(const QModelIndex &index) // þegar ýtt er á tengingu í töflu þá virkjast takki.
{
    QVariant a = index;
    ui->button_remove_connection->setEnabled(true);
}

void MainWindow::on_button_remove_connection_clicked() // þegar ýtt er á remove Connection er spurt notendann hvort að hann vilji eyða eða ekki og ef það er yes þá mun hann eyða tengingunni.
{
    int reply = QMessageBox::question(this, "Warning", "Are you sure you want to delete the selected relations?");

    if(reply == QMessageBox::Yes)
    {
    int currentlySelectedConnectionIndex = ui->table_View_join_Connections->currentIndex().row();

    RelationsID currentlySelectedConnection = currentlyDisplayedConnections[currentlySelectedConnectionIndex];

    int id = currentlySelectedConnection.get_id();
    _service.removeJoin(id);
    displayAllJoin();
    }
    else
    {
        ui->button_remove_connection->setEnabled(false);
    }
}

void MainWindow::on_button_add_connection_clicked() // þetta fall lætur keyra glugga og svo disablear það takka og keyrir fall sem sýnir töflu.
{
    AddConnectionDialog addConnectionDialog;
    addConnectionDialog.exec();
    ui->button_remove_connection->setEnabled(false);
    displayAllJoin();
}

void MainWindow::displayIntro() // þetta fall er keyrt áður en MainWindow er keyrt, notað sem intro!
{
    IntroDialog introDialog;
    introDialog.exec();
}

void MainWindow::on_pushButton_clicked() // fall sem endar forittið þegar ýtt er á þennan takka!
{
    this->close();
}
