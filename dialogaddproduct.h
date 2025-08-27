#ifndef DIALOGADDPRODUCT_H
#define DIALOGADDPRODUCT_H

#include <QDialog>

#include <Model/productmodel.h>

namespace Ui {
class DialogAddProduct;
}

class DialogAddProduct : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddProduct(QWidget *parent = nullptr);
    ~DialogAddProduct();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogAddProduct *ui;
    ProductModel *newPm;
};

#endif // DIALOGADDPRODUCT_H
