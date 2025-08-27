#ifndef CONTRACTORSVIEW_H
#define CONTRACTORSVIEW_H

#include <DialogAddContractor.h>
#include <QWidget>

namespace Ui {
class ContractorsView;
}

class ContractorsView : public QWidget
{
    Q_OBJECT

public:
    explicit ContractorsView(QWidget *parent = nullptr);
    ~ContractorsView();

private slots:
    void on_pushButton_add_clicked();

private:
    Ui::ContractorsView *ui;
    DialogAddContractor dialogAddContractor;
};

#endif // CONTRACTORSVIEW_H
