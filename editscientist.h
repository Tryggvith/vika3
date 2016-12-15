#ifndef EDITSCIENTIST_H
#define EDITSCIENTIST_H

#include <QDialog>

namespace Ui {
class editScientist;
}

class editScientist : public QDialog
{
    Q_OBJECT

public:
    explicit editScientist(QWidget *parent = 0);
    ~editScientist();

private:
    Ui::editScientist *ui;
};

#endif // EDITSCIENTIST_H
