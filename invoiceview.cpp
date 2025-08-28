#include "invoiceview.h"
#include "Service/invoiceservice.h"
#include "invoicedetailsview.h"
#include "ui_invoiceview.h"

#include <DialogNewInvoice.h>

InvoiceView::InvoiceView(class QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InvoiceView)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    model->setColumnCount(6);
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Płatność");
    model->setHeaderData(2, Qt::Horizontal, "Imie");
    model->setHeaderData(3, Qt::Horizontal, "Nazwisko");
    model->setHeaderData(4, Qt::Horizontal, "Adres");
    model->setHeaderData(5, Qt::Horizontal, "NIP");

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ShowInvoices();
}

InvoiceView::~InvoiceView()
{
    delete ui;
}


void InvoiceView::ShowInvoices(){

    QList<InvoiceBodyModel> invoices = InvoiceService().GetAllInvoices();

    model->removeRows(0, model->rowCount());
    model->setRowCount(invoices.size());

    for (int i = 0; i < invoices.size(); ++i) {
        const InvoiceBodyModel &inv = invoices[i];
        model->setItem(i, 0, new QStandardItem(QString::number(inv.getId())));
        model->setItem(i, 1, new QStandardItem(QString::fromStdString( inv.getPayment())));
        model->setItem(i, 2, new QStandardItem(QString::fromStdString( inv.getInvoiceHeader().getName())));
        model->setItem(i, 3, new QStandardItem(QString::fromStdString( inv.getInvoiceHeader().getSname())));
        model->setItem(i, 4, new QStandardItem(QString::fromStdString( inv.getInvoiceHeader().getAddress())));
        model->setItem(i, 5, new QStandardItem(QString::fromStdString( inv.getInvoiceHeader().getNip())));

    }
}

void InvoiceView::on_pushButton_add_clicked()
{
    DialogNewInvoice newInvoice;
    newInvoice.setWindowTitle("Nowa Faktura");

    QPoint currentPos = this->pos();
    newInvoice.move(currentPos.x() + this->width() + 50, currentPos.y());

    newInvoice.exec();
    ShowInvoices();
}

void InvoiceView::on_tableView_doubleClicked(const QModelIndex &index)
{
    int invoiceId = model->item(index.row(), 0)->text().toInt();
    InvoiceBodyModel inv = InvoiceService().GetInvoice(invoiceId);

    InvoiceDetailsView detailsView;
    detailsView.SetInvoice(inv);
    detailsView.setWindowTitle("Faktura nr:" + QString::number(inv.getId()));

    QPoint currentPos = this->pos();
    detailsView.move(currentPos.x() + this->width() + 50, currentPos.y());

    detailsView.exec();
    ShowInvoices();
}

