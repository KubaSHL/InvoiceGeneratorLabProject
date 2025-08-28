#include "Service/contractorservice.h"
#include "Service/invoiceservice.h"
#include "Service/productservice.h"
#include "Workers/pdfworker.h"
#include "ui_invoicedetailsview.h"

#include <InvoiceDetailsView.h>
#include <QMessageBox>

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

    ui->tableWidget_positions->clearContents();
    ui->tableWidget_positions->setColumnCount(5);

    QStringList headers = {"Nazwa", "EAN", "Ilość", "Cena Netto", "Wart. Netto"};
    ui->tableWidget_positions->setHorizontalHeaderLabels(headers);
    ui->tableWidget_positions->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget_contractors->setRowCount(4);
    ui->tableWidget_contractors->setColumnCount(2);
    ui->tableWidget_contractors->horizontalHeader()->setVisible(false);
    ui->tableWidget_contractors->verticalHeader()->setVisible(false);
    ui->tableWidget_contractors->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_contractors->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget_contractors->setItem(0, 0, new QTableWidgetItem("Imie"));
    ui->tableWidget_contractors->setItem(1, 0, new QTableWidgetItem("Nazwisko"));
    ui->tableWidget_contractors->setItem(2, 0, new QTableWidgetItem("Adres"));
    ui->tableWidget_contractors->setItem(3, 0, new QTableWidgetItem("NIP"));


}

InvoiceDetailsView::~InvoiceDetailsView()
{
    delete ui;
}

void InvoiceDetailsView::SetInvoice(InvoiceBodyModel thisInvoice){
    invoice =  thisInvoice;

    ui->comboBox->blockSignals(true);

    int index = ui->comboBox->findData(invoice.getContractorId());
    if(index >= 0){
        ui->comboBox->setCurrentIndex(index);
    }

    ui->comboBox->blockSignals(false);

    ui->lineEdit_payment->setText(QString::fromStdString(invoice.getPayment()));

    ShowContractor(invoice.getContractorId());
    ShowPositions();
}


void InvoiceDetailsView::ShowPositions(){

    QList<PositionModel> positions = InvoiceService().GetInvoice(invoice.getId()).getPositionList();
    ui->tableWidget_positions->setRowCount(positions.size());

    ui->tableWidget_positions->blockSignals(true);

    for (int i = 0; i < positions.size(); ++i) {
        const ProductModel &pm = ProductService().GetProduct(positions[i].getProductId());

        QTableWidgetItem *item0 = new QTableWidgetItem(QString::fromStdString(pm.getName()));
        item0->setFlags(item0->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget_positions->setItem(i, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem(QString::fromStdString(pm.getEan()));
        item1->setFlags(item1->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget_positions->setItem(i, 1, item1);

        ui->tableWidget_positions->setItem(i, 2, new QTableWidgetItem(QString::number( positions[i].getQuantity())));
        ui->tableWidget_positions->setItem(i, 3, new QTableWidgetItem(QString::number( positions[i].getPriceNet())));


        QTableWidgetItem *item4 = new QTableWidgetItem(QString::number( positions[i].getPriceNet()*positions[i].getQuantity()));
        item4->setFlags(item4->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget_positions->setItem(i, 4, item4);
    }

    ui->tableWidget_positions->blockSignals(false);

}


void InvoiceDetailsView::ShowContractor(int contractorId){

    ContractorModel ct = ContractorService().GetContractor(contractorId);

    QTableWidgetItem *item0 = new QTableWidgetItem(QString::fromStdString(ct.getName()));
    item0->setFlags(item0->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget_contractors->setItem(0, 1, item0);

    QTableWidgetItem *item1 = new QTableWidgetItem(QString::fromStdString(ct.getSname()));
    item1->setFlags(item1->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget_contractors->setItem(1, 1, item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromStdString(ct.getAddress()));
    item2->setFlags(item2->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget_contractors->setItem(2, 1, item2);

    QTableWidgetItem *item3 = new QTableWidgetItem(QString::fromStdString(ct.getNip()));
    item3->setFlags(item3->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget_contractors->setItem(3, 1, item3);
}


void InvoiceDetailsView::OnContractorChanged(int index)
{
    if (index < 0) return;
    int contractorId = ui->comboBox->itemData(index).toInt();
    ShowContractor(contractorId);
}


void InvoiceDetailsView::on_pushButton_close_clicked()
{
    ui->tableWidget_positions->clearContents();
    ui->tableWidget_positions->setRowCount(0);
    ui->tableWidget_contractors->clear();
    this->close();
}


void InvoiceDetailsView::on_pushButton_update_clicked()
{


    InvoiceBodyModel inv;
    inv.setId(invoice.getId());
    inv.setPayment(ui->lineEdit_payment->text().toStdString());
    inv.setContractorId(ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt());
    inv.setInvoiceHeader(ContractorService().GetContractor(inv.getContractorId()));
    QList<PositionModel> positions;

    for (int i = 0; i < ui->tableWidget_positions->rowCount(); ++i) {
        PositionModel pos;
        pos.setId(invoice.getPositionList()[i].getId());
        pos.setProductId(invoice.getPositionList()[i].getProductId());
        pos.setInvoiceId(inv.getId());
        pos.setQuantity(ui->tableWidget_positions->item(i, 2)->text().toInt());
        pos.setPriceNet(ui->tableWidget_positions->item(i, 3)->text().toFloat());
        pos.setValueNet(ui->tableWidget_positions->item(i, 2)->text().toFloat() * ui->tableWidget_positions->item(i, 3)->text().toFloat());
        positions.append(pos);
    }
    inv.setPositionList(positions);
    if(InvoiceService().UpdateInvoice(inv)){

        QMessageBox::information(this, "Info", "Pozycja została zaktualizowana.");
    }
    else
    {
        QMessageBox::warning(this, "Uwaga", "Pozycja nie została zaktualizowana.");
    }

    ShowPositions();
}


void InvoiceDetailsView::on_tableWidget_positions_cellChanged(int row, int column)
{
    if(column == 2 || column == 3){
        QTableWidgetItem *item4 = ui->tableWidget_positions->item(row, 4);
        if(item4) {
            float quantity = ui->tableWidget_positions->item(row, 2)->text().toFloat();
            float priceNet = ui->tableWidget_positions->item(row, 3)->text().toFloat();
            item4->setText(QString::number(quantity * priceNet));
        }
    }
}


void InvoiceDetailsView::on_pushButton_clicked()
{
    worker.SetInvoice(invoice);
    worker.PrintHTML();
    QMessageBox::information(this,"Info","Wygenerowano PDF'a.");
}

