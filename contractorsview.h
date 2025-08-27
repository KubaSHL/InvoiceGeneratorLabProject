#ifndef CONTRACTORSVIEW_H
#define CONTRACTORSVIEW_H

#include <DialogAddContractor.h>
#include <QStandardItemModel>
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

    void ShowContractors();

private slots:
    void on_pushButton_del_clicked();
    void on_pushButton_update_clicked();
    void on_pushButton_add_clicked();

private:
    Ui::ContractorsView *ui;
    DialogAddContractor dialogAddContractor;
    QStandardItemModel *model;
};

#endif // CONTRACTORSVIEW_H
