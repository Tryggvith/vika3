#ifndef INTRODIALOG_H
#define INTRODIALOG_H

#include <QDialog>
#include "creditsdialog.h"

namespace Ui {
class IntroDialog;
}

class IntroDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IntroDialog(QWidget *parent = 0);

    ~IntroDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::IntroDialog *ui;
};

#endif // INTRODIALOG_H
