#include "dialogaddcontractor.h"
#include "Model/contractormodel.h"
#include "ui_dialogaddcontractor.h"

DialogAddContractor::DialogAddContractor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAddContractor)
{
    ui->setupUi(this);
}

DialogAddContractor::~DialogAddContractor()
{
    delete ui;
}

void DialogAddContractor::on_buttonBox_accepted()
{
    newCt = new ContractorModel();
    newCt->setName(ui->lineEdit_name->text().toStdString());
    newCt->setSname(ui->lineEdit_sname->text().toStdString());
    newCt->setAddress(ui->lineEdit_address->text().toStdString());
    newCt->setNip(ui->lineEdit_nip->text().toStdString());

}

