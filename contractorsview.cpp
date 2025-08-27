#include "contractorsview.h"
#include "ui_contractorsview.h"

ContractorsView::ContractorsView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ContractorsView)
{
    ui->setupUi(this);
}

ContractorsView::~ContractorsView()
{
    delete ui;
}

void ContractorsView::on_pushButton_add_clicked()
{
    dialogAddContractor.show();
}

