#include "invoicebodymodel.h"


InvoiceBodyModel::InvoiceBodyModel(){}

std::string InvoiceBodyModel::getPayment() const
{
    return payment;
}

void InvoiceBodyModel::setPayment(const std::string &newPayment)
{
    payment = newPayment;
}

int InvoiceBodyModel::getContractorId() const
{
    return contractorId;
}

void InvoiceBodyModel::setContractorId(int newContractorId)
{
    contractorId = newContractorId;
}

int InvoiceBodyModel::getId() const
{
    return id;
}

void InvoiceBodyModel::setId(int newId)
{
    id = newId;
}

ContractorModel InvoiceBodyModel::getInvoiceHeader() const
{
    return invoiceHeader;
}

void InvoiceBodyModel::setInvoiceHeader(const ContractorModel &newInvoiceHeader)
{
    invoiceHeader = newInvoiceHeader;
}

QList<PositionModel> InvoiceBodyModel::getPositionList() const
{
    return positionList;
}

void InvoiceBodyModel::setPositionList(const QList<PositionModel> &newPositionList)
{
    positionList = newPositionList;
}
