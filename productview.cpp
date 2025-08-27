#include "productview.h"
#include "Service/productservice.h"
#include "ui_productview.h"
#include <QMessageBox>
ProductView::ProductView(class QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProductView)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    model->setColumnCount(7);
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nazwa");
    model->setHeaderData(2, Qt::Horizontal, "Kod EAN");
    model->setHeaderData(3, Qt::Horizontal, "Producent");
    model->setHeaderData(4, Qt::Horizontal, "Cena Netto");
    model->setHeaderData(5, Qt::Horizontal, "Stawka VAT");
    model->setHeaderData(6, Qt::Horizontal, "Cena Brutton");

    ui->tableView->setModel(model);
    ShowProducts();
}


ProductView::~ProductView()
{
    delete ui;
}

void ProductView::ShowProducts(){

    QList<ProductModel> products = ProductService().GetAllProducts();

    model->removeRows(0, model->rowCount());
    model->setRowCount(products.size());

    for (int i = 0; i < products.size(); ++i) {
        const ProductModel &pm = products[i];
        model->setItem(i, 0, new QStandardItem(QString::number(pm.getId())));
        model->setItem(i, 1, new QStandardItem(QString::fromStdString( pm.getName())));
        model->setItem(i, 2, new QStandardItem(QString::fromStdString( pm.getEan())));
        model->setItem(i, 3, new QStandardItem(QString::fromStdString( pm.getManofacturer())));
        model->setItem(i, 4, new QStandardItem(QString::number( pm.getPriceNet())));
        model->setItem(i, 5, new QStandardItem(QString::number( pm.getVAT())));
        model->setItem(i, 6, new QStandardItem(QString::number( pm.getPriceGross())));

    }
}


void ProductView::on_pushButton_add_clicked()
{
    dialogAddProduct.show();
    ShowProducts();
}


void ProductView::on_pushButton_update_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Uwaga", "Proszę zaznaczyć produkt do aktualizacji.");
        return;
    }

    int row = currentIndex.row();

    ProductModel pm;
    pm.setId(model->item(row, 0)->text().toInt());
    pm.setName(model->item(row, 1)->text().toStdString());
    pm.setEan(model->item(row, 2)->text().toStdString());
    pm.setManofacturer(model->item(row, 3)->text().toStdString());
    pm.setPriceNet(model->item(row, 4)->text().toFloat());
    pm.setVAT(model->item(row, 5)->text().toFloat());
    pm.setPriceGross(model->item(row, 6)->text().toFloat());

    if(ProductService().UpdateProduct(pm)){

        QMessageBox::information(this, "Info", "Produkt został zaktualizowany.");
    }
    else
    {
        QMessageBox::warning(this, "Uwaga", "Produkt nie został zaktualizowany.");
    }

    ShowProducts();
}



void ProductView::on_pushButton_del_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Uwaga", "Proszę zaznaczyć produkt do aktualizacji.");
        return;
    }

    int row = currentIndex.row();

    ProductModel pm;
    pm.setId(model->item(row, 0)->text().toInt());
    pm.setName(model->item(row, 1)->text().toStdString());
    pm.setEan(model->item(row, 2)->text().toStdString());
    pm.setManofacturer(model->item(row, 3)->text().toStdString());
    pm.setPriceNet(model->item(row, 4)->text().toFloat());
    pm.setVAT(model->item(row, 5)->text().toFloat());
    pm.setPriceGross(model->item(row, 6)->text().toFloat());

    if(ProductService().DeleteProduct(pm)){

        QMessageBox::information(this, "Info", "Produkt został zaktualizowany.");
    }
    else
    {
        QMessageBox::warning(this, "Uwaga", "Produkt nie został zaktualizowany.");
    }

    ShowProducts();
}

