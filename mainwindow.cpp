#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(&invoiceView);
    ui->stackedWidget->addWidget(&productView);
    ui->stackedWidget->addWidget(&contractorsView);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_invoice_clicked()
{
    invoiceView.ShowInvoices();
    ui->stackedWidget->setCurrentWidget(&invoiceView);

}


void MainWindow::on_pushButton_product_clicked()
{
    productView.ShowProducts();
    ui->stackedWidget->setCurrentWidget(&productView);

}


void MainWindow::on_pushButton_contractor_clicked()
{
    contractorsView.ShowContractors();
    ui->stackedWidget->setCurrentWidget(&contractorsView);

}

