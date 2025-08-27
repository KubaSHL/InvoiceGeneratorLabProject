#include "dialogaddproduct.h"
#include "Service/productservice.h"
#include "ui_dialogaddproduct.h"

#include <Model/productmodel.h>

#include <QMessageBox>

DialogAddProduct::DialogAddProduct(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAddProduct)
{
    ui->setupUi(this);
}

DialogAddProduct::~DialogAddProduct()
{
    delete ui;
}

void DialogAddProduct::on_buttonBox_accepted()
{
    ProductModel newPm;
    newPm.setName(ui->lineEdit_name->text().toStdString());
    newPm.setEan(ui->lineEdit_ean->text().toStdString());
    newPm.setManofacturer(ui->lineEdit_manofacturer->text().toStdString());
    newPm.setPriceNet(ui->doubleSpinBox_pricenet->value());
    newPm.setVAT(ui->spinBox_vat->value());
    newPm.setPriceGross((newPm.getPriceNet()*(100+newPm.getVAT()))/100);
    if(ProductService().AddProduct(newPm)){
        QMessageBox::information(this, "Info", "Produkt został dodany.");
    }else{
        QMessageBox::warning(this, "Uwaga", "Produkt nie został dodany.");
    }

}

