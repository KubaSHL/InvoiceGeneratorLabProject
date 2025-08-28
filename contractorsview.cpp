#include "contractorsview.h"
#include "ui_contractorsview.h"

#include <QMessageBox>
#include <QStandardItemModel>

#include <Service/contractorservice.h>

ContractorsView::ContractorsView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ContractorsView)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    model->setColumnCount(5);    
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Imie");
    model->setHeaderData(2, Qt::Horizontal, "Nazwisko");
    model->setHeaderData(3, Qt::Horizontal, "Adres");
    model->setHeaderData(4, Qt::Horizontal, "NIP");

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ShowContractors();
}

ContractorsView::~ContractorsView()
{
    delete ui;
}

void ContractorsView::ShowContractors(){

    QList<ContractorModel> Contractors = ContractorService().GetAllContractors();

    model->removeRows(0, model->rowCount());
    model->setRowCount(Contractors.size());

    for (int i = 0; i < Contractors.size(); ++i) {
        const ContractorModel &ct = Contractors[i];
        model->setItem(i, 0, new QStandardItem(QString::number(ct.getId())));
        model->setItem(i, 1, new QStandardItem(QString::fromStdString( ct.getName())));
        model->setItem(i, 2, new QStandardItem(QString::fromStdString( ct.getSname())));
        model->setItem(i, 3, new QStandardItem(QString::fromStdString( ct.getAddress())));
        model->setItem(i, 4, new QStandardItem(QString::fromStdString( ct.getNip())));

    }
}

void ContractorsView::on_pushButton_add_clicked()
{
    dialogAddContractor.show();
    ShowContractors();
}


void ContractorsView::on_pushButton_update_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Uwaga", "Proszę zaznaczyć Kontrahent do aktualizacji.");
        return;
    }

    int row = currentIndex.row();

    ContractorModel ct;
    ct.setId(model->item(row, 0)->text().toInt());
    ct.setName(model->item(row, 1)->text().toStdString());
    ct.setSname(model->item(row, 2)->text().toStdString());
    ct.setAddress(model->item(row, 3)->text().toStdString());
    ct.setNip(model->item(row, 4)->text().toStdString());

    if(ContractorService().UpdateContractor(ct)){

        QMessageBox::information(this, "Info", "Kontrahent został zaktualizowany.");
    }
    else
    {
        QMessageBox::warning(this, "Uwaga", "Kontrahent nie został zaktualizowany.");
    }

    ShowContractors();
}



void ContractorsView::on_pushButton_del_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Uwaga", "Proszę zaznaczyć Kontrahent do aktualizacji.");
        return;
    }

    int row = currentIndex.row();

    ContractorModel ct;
    ct.setId(model->item(row, 0)->text().toInt());
    ct.setName(model->item(row, 1)->text().toStdString());
    ct.setSname(model->item(row, 2)->text().toStdString());
    ct.setAddress(model->item(row, 3)->text().toStdString());
    ct.setNip(model->item(row, 4)->text().toStdString());

    if(ContractorService().DeleteContractor(ct)){

        QMessageBox::information(this, "Info", "Kontrahent został zaktualizowany.");
    }
    else
    {
        QMessageBox::warning(this, "Uwaga", "Kontrahent nie został zaktualizowany.");
    }

    ShowContractors();
}

