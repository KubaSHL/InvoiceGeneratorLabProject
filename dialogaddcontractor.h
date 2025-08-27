#ifndef DIALOGADDCONTRACTOR_H
#define DIALOGADDCONTRACTOR_H

#include <QDialog>

#include <Model/contractormodel.h>

namespace Ui {
class DialogAddContractor;
}

class DialogAddContractor : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddContractor(QWidget *parent = nullptr);
    ~DialogAddContractor();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogAddContractor *ui;
    ContractorModel *newCt;
};

#endif // DIALOGADDCONTRACTOR_H
