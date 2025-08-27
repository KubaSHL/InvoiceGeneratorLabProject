#include "positionmodel.h"

int PositionModel::getId() const
{
    return id;
}

void PositionModel::setId(int newId)
{
    id = newId;
}

int PositionModel::getInvoiceId() const
{
    return invoiceId;
}

void PositionModel::setInvoiceId(int newInvoiceId)
{
    invoiceId = newInvoiceId;
}

int PositionModel::getProductId() const
{
    return productId;
}

void PositionModel::setProductId(int newProductId)
{
    productId = newProductId;
}

int PositionModel::getQuantity() const
{
    return quantity;
}

void PositionModel::setQuantity(int newQuantity)
{
    quantity = newQuantity;
}

float PositionModel::getValueNet() const
{
    return valueNet;
}

void PositionModel::setValueNet(float newValueNet)
{
    valueNet = newValueNet;
}

float PositionModel::getValueGross() const
{
    return valueGross;
}

void PositionModel::setValueGross(float newValueGross)
{
    valueGross = newValueGross;
}

PositionModel::PositionModel() {}
