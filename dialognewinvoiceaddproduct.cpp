#include "dialognewinvoiceaddproduct.h"
#include "Service/productservice.h"
#include "ui_dialognewinvoiceaddproduct.h"

DialogNewInvoiceAddProduct::DialogNewInvoiceAddProduct(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogNewInvoiceAddProduct)
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
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    outProduct = new ProductModel();
}

DialogNewInvoiceAddProduct::~DialogNewInvoiceAddProduct()
{
    delete ui;
}

ProductModel DialogNewInvoiceAddProduct::GetProductModel(){
    return *outProduct;
}

void DialogNewInvoiceAddProduct::SetAlreadyPickedProducts(QList<ProductModel> pickedList){

    for(ProductModel pm : pickedList){
        restricted.append(pm.getId());
    }
}

void DialogNewInvoiceAddProduct::ShowProducts(){

    QList<ProductModel> products = ProductService().GetAllProducts();

    model->removeRows(0, model->rowCount());
    model->setRowCount(products.size() - restricted.size());
    int i = 0;
    for (int j = 0; j < products.size(); ++j) {

        const ProductModel &pm = products[j];
        if(!restricted.contains(pm.getId())){


            model->setItem(i, 0, new QStandardItem(QString::number(pm.getId())));
            model->item(i, 0)->setFlags(model->item(i, 0)->flags() & ~Qt::ItemIsEditable);

            model->setItem(i, 1, new QStandardItem(QString::fromStdString( pm.getName())));
            model->item(i, 1)->setFlags(model->item(i, 1)->flags() & ~Qt::ItemIsEditable);

            model->setItem(i, 2, new QStandardItem(QString::fromStdString( pm.getEan())));
            model->item(i, 2)->setFlags(model->item(i, 2)->flags() & ~Qt::ItemIsEditable);

            model->setItem(i, 3, new QStandardItem(QString::fromStdString( pm.getManofacturer())));
            model->item(i, 3)->setFlags(model->item(i, 3)->flags() & ~Qt::ItemIsEditable);

            model->setItem(i, 4, new QStandardItem(QString::number( pm.getPriceNet())));
            model->item(i, 4)->setFlags(model->item(i, 4)->flags() & ~Qt::ItemIsEditable);

            model->setItem(i, 5, new QStandardItem(QString::number( pm.getVAT())));
            model->item(i, 5)->setFlags(model->item(i, 5)->flags() & ~Qt::ItemIsEditable);

            model->setItem(i, 6, new QStandardItem(QString::number( pm.getPriceGross())));
            model->item(i, 6)->setFlags(model->item(i, 6)->flags() & ~Qt::ItemIsEditable);

            i++;
        }
    }

}

void DialogNewInvoiceAddProduct::on_buttonBox_accepted()
{

    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) return;

    int row = index.row();
    ProductModel* pm = new ProductModel();
    pm->setId(model->item(row, 0)->text().toInt());
    pm->setName(model->item(row, 1)->text().toStdString());
    pm->setEan(model->item(row, 2)->text().toStdString());
    pm->setManofacturer(model->item(row, 3)->text().toStdString());
    pm->setPriceNet(model->item(row, 4)->text().toFloat());
    pm->setVAT(model->item(row, 5)->text().toFloat());
    pm->setPriceGross(model->item(row, 6)->text().toFloat());

    outProduct = pm;
}


void DialogNewInvoiceAddProduct::on_buttonBox_rejected()
{

}

