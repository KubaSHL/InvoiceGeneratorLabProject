#include "invoiceheadermodel.h"

std::string InvoiceHeaderModel::getAddres() const
{
    return addres;
}

void InvoiceHeaderModel::setAddres(const std::string &newAddres)
{
    if (addres == newAddres)
        return;
    addres = newAddres;
    emit addresChanged();
}

std::string InvoiceHeaderModel::getReciver() const
{
    return reciver;
}

void InvoiceHeaderModel::setReciver(const std::string &newReciver)
{
    if (reciver == newReciver)
        return;
    reciver = newReciver;
    emit reciverChanged();
}

std::string InvoiceHeaderModel::getPayment() const
{
    return payment;
}

void InvoiceHeaderModel::setPayment(const std::string &newPayment)
{
    if (payment == newPayment)
        return;
    payment = newPayment;
    emit paymentChanged();
}

InvoiceHeaderModel::InvoiceHeaderModel() {}
