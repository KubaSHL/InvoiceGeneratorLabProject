#include "Service/contractorservice.h"
#include "Service/invoiceservice.h"
#include "Service/productservice.h"
#include "ui_invoicedetailsview.h"

#include <InvoiceDetailsView.h>

InvoiceDetailsView::InvoiceDetailsView(QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::InvoiceDetailsView)
{
    ui->setupUi(this);

    QList<ContractorModel> contractors = ContractorService().GetAllContractors();
    for (const ContractorModel &c : contractors) {
        ui->comboBox->addItem(QString::fromStdString(c.getNip()), QVariant(c.getId())); // id w QVariant
    }

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &InvoiceDetailsView::OnContractorChanged);


    modelCt = new QStandardItemModel(this);
    modelCt->setColumnCount(5);
    modelCt->setHeaderData(0, Qt::Horizontal, "Nazwa");
    modelCt->setHeaderData(1, Qt::Horizontal, "EAN");
    modelCt->setHeaderData(2, Qt::Horizontal, "Ilość");
    modelCt->setHeaderData(3, Qt::Horizontal, "Wartość Netto");
    modelCt->setHeaderData(4, Qt::Horizontal, "Wartość Brutto");
}

InvoiceDetailsView::~InvoiceDetailsView()
{
    delete ui;
}

void InvoiceDetailsView::SetInvoice(InvoiceBodyModel *thisInvoice){
    invoice =  thisInvoice;
}


void InvoiceDetailsView::ShowPositions(){
    QList<PositionModel> products = InvoiceService().GetInvoice(invoice->getId()).getPositionList();

    modelCt->removeRows(0, modelCt->rowCount());
    modelCt->setRowCount(products.size());

    for (int i = 0; i < products.size(); ++i) {
        const ProductModel &pm = ProductService().GetProduct(products[i].getProductId());
        modelCt->setItem(i, 1, new QStandardItem(QString::fromStdString( pm.getName())));
        modelCt->setItem(i, 2, new QStandardItem(QString::fromStdString( pm.getEan())));
    }
}

void InvoiceDetailsView::OnContractorChanged(int index)
{
    if (index < 0) return;

    int contractorId = ui->comboBox->itemData(index).toInt();
    ContractorModel ct = ContractorService().GetContractor(contractorId);
    ui->tableWidget->setRowCount(4);
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(ct.getName())));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem(QString::fromStdString(ct.getSname())));
    ui->tableWidget->setItem(2, 1, new QTableWidgetItem(QString::fromStdString(ct.getAddress())));
    ui->tableWidget->setItem(3, 1, new QTableWidgetItem(QString::fromStdString(ct.getNip())));
}
