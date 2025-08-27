#include "invoiceview.h"
#include "ui_invoiceview.h"

InvoiceView::InvoiceView(class QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InvoiceView)
{
    ui->setupUi(this);
}

InvoiceView::~InvoiceView()
{
    delete ui;
}

void InvoiceView::on_pushButton_add_clicked()
{

}

