#include "introdialog.h"
#include "ui_introdialog.h"
#include <QDesktopWidget>

IntroDialog::IntroDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IntroDialog)
{

    ui->setupUi(this);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
}

IntroDialog::~IntroDialog()
{
    delete ui;
}

void IntroDialog::on_pushButton_clicked()
{
    this->done(0);
}

void IntroDialog::on_pushButton_2_clicked()
{
    CreditsDialog creditsDialog;
    creditsDialog.exec();
}
