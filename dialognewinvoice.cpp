#include "Service/contractorservice.h"
#include "Service/invoiceservice.h"
#include "dialognewinvoiceaddproduct.h"
#include "ui_dialognewinvoice.h"

#include <dialognewinvoice.h>.h>
#include <QMessageBox>

DialogNewInvoice::DialogNewInvoice(QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::DialogNewInvoice)
{
    ui->setupUi(this);

    QList<ContractorModel> contractors = ContractorService().GetAllContractors();
    for (const ContractorModel &c : contractors) {
        ui->comboBox->addItem(QString::fromStdString(c.getNip()), QVariant(c.getId())); // id w QVariant
    }

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &DialogNewInvoice::OnContractorChanged);

    ui->tableWidget_newpositions->clearContents();
    ui->tableWidget_newpositions->setColumnCount(5);

    QStringList headers = {"Nazwa", "EAN", "Ilość", "Cena Netto", "Wart. Netto"};
    ui->tableWidget_newpositions->setHorizontalHeaderLabels(headers);
    ui->tableWidget_newpositions->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

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

    lp = 0;
    quantities.begin();

}

DialogNewInvoice::~DialogNewInvoice()
{
    delete ui;
}


void DialogNewInvoice::ShowPositions(){

    ui->tableWidget_newpositions->setRowCount(products.size());

    ui->tableWidget_newpositions->blockSignals(true);

    for (int i = 0; i < products.size(); ++i) {
        const ProductModel &pm = products[i];

        QTableWidgetItem *item0 = new QTableWidgetItem(QString::fromStdString(pm.getName()));
        item0->setFlags(item0->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget_newpositions->setItem(i, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem(QString::fromStdString(pm.getEan()));
        item1->setFlags(item1->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget_newpositions->setItem(i, 1, item1);


        QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(quantities.value(pm.getId())));
        item2->setFlags(item2->flags() | Qt::ItemIsEditable);
        ui->tableWidget_newpositions->setItem(i, 2, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(pm.getPriceNet()));
        item3->setFlags(item3->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget_newpositions->setItem(i, 3, item3);


        QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(pm.getPriceNet() * item2->text().toFloat()));
        item4->setFlags(item4->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget_newpositions->setItem(i, 4, item4);
    }

    ui->tableWidget_newpositions->blockSignals(false);

}


void DialogNewInvoice::ShowContractor(int contractorId){

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


void DialogNewInvoice::OnContractorChanged(int index)
{
    if (index < 0) return;
    int contractorId = ui->comboBox->itemData(index).toInt();
    ShowContractor(contractorId);
}


void DialogNewInvoice::on_pushButton_AddProduct_clicked()
{
    ProductModel pm;
    DialogNewInvoiceAddProduct newProduct;
    newProduct.setWindowTitle("Nowa pozycja");

    QPoint currentPos = this->pos();
    newProduct.move(currentPos.x() + this->width() + 50, currentPos.y());
    if(products.size()!=0){
        newProduct.SetAlreadyPickedProducts(products);
    }
    newProduct.ShowProducts();
    newProduct.exec();
    pm = newProduct.GetProductModel();
    if(pm.getId()!=0){
        lp++;
        quantities.insert(pm.getId(),1);
        products.append(pm);
    }
    ShowPositions();
}

void DialogNewInvoice::on_tableWidget_newpositions_itemChanged(QTableWidgetItem *item)
{
    if(item->column() == 2){
        QTableWidgetItem *item4 = ui->tableWidget_newpositions->item(item->row(), 4);
        if(item4) {
            float quantity = ui->tableWidget_newpositions->item(item->row(), 2)->text().toFloat();
            float priceNet = ui->tableWidget_newpositions->item(item->row(), 3)->text().toFloat();
            item4->setFlags(item4->flags() & ~Qt::ItemIsEditable);
            item4->setText(QString::number(quantity * priceNet));
            quantities.remove(products[item->row()].getId());
            quantities.insert(products[item->row()].getId(),quantity);
        }
    }
}


void DialogNewInvoice::on_buttonBox_accepted()
{

    InvoiceBodyModel inv;
    inv.setPayment(ui->lineEdit_payment->text().toStdString());
    inv.setContractorId(ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt());
    inv.setInvoiceHeader(ContractorService().GetContractor(inv.getContractorId()));
    QList<PositionModel> positions;

    for (int i = 0; i < ui->tableWidget_newpositions->rowCount(); ++i) {
        PositionModel pos;
        pos.setProductId(products[i].getId());
        pos.setInvoiceId(inv.getId());
        pos.setQuantity(ui->tableWidget_newpositions->item(i, 2)->text().toInt());
        pos.setPriceNet(ui->tableWidget_newpositions->item(i, 3)->text().toFloat());
        pos.setValueNet(ui->tableWidget_newpositions->item(i, 4)->text().toFloat());
        positions.append(pos);
    }
    inv.setPositionList(positions);
    if(InvoiceService().AddInvoice(inv)){

        QMessageBox::information(this, "Info", "Faktura została dodana.");
        ui->tableWidget_newpositions->clearContents();
        ui->tableWidget_newpositions->setRowCount(0);
        ui->tableWidget_contractors->clear();
        accept();
    }
    else
    {
        QMessageBox::warning(this, "Uwaga", "Faktura została dodana.");
    }

    ShowPositions();
}

