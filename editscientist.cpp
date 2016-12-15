#include "editscientist.h"
#include "ui_editscientist.h"

editScientist::editScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editScientist)
{
    ui->setupUi(this);
}

editScientist::~editScientist()
{
    delete ui;
}
