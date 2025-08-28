#ifndef DIALOGNEWINVOICE_H
#define DIALOGNEWINVOICE_H

#include <QDialog>
#include <QTableWidgetItem>

#include <Model/positionmodel.h>


class ProductModel;
namespace Ui {
class DialogNewInvoice;
}

class DialogNewInvoice : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewInvoice(QDialog *parent = nullptr);
    ~DialogNewInvoice();

    void ShowPositions();
    void ShowContractor(int contractorId);
    void OnContractorChanged(int index);
    void on_tableWidget_newpositions_cellChanged(int row, int column);
private slots:
    void on_pushButton_AddProduct_clicked();

    void on_tableWidget_newpositions_itemChanged(QTableWidgetItem *item);

    void on_buttonBox_accepted();

    void on_pushButton_delPos_clicked();

private:
    Ui::DialogNewInvoice *ui;
    QList<ProductModel> products;
    QMap<int, float> quantities;
    int lp;
};

#endif // DIALOGNEWINVOICE_H
