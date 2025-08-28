#ifndef DIALOGNEWINVOICEADDPRODUCT_H
#define DIALOGNEWINVOICEADDPRODUCT_H

#include "Model/productmodel.h"
#include <QDialog>
#include <qstandarditemmodel.h>

namespace Ui {
class DialogNewInvoiceAddProduct;
}

class DialogNewInvoiceAddProduct : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewInvoiceAddProduct(QWidget *parent = nullptr);
    ~DialogNewInvoiceAddProduct();

    void ShowProducts();
    ProductModel GetProductModel();
    void SetAlreadyPickedProducts(QList<ProductModel> pickedList);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogNewInvoiceAddProduct *ui;
    QStandardItemModel *model;
    ProductModel *outProduct;
    QList<int> restricted;
};

#endif // DIALOGNEWINVOICEADDPRODUCT_H
