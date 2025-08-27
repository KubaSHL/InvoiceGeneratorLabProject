#include "productmodel.h"

std::string ProductModel::getName() const
{
    return name;
}

void ProductModel::setName(const std::string &newName)
{
    if (name == newName)
        return;
    name = newName;
}

std::string ProductModel::getManofacturer() const
{
    return manofacturer;
}

void ProductModel::setManofacturer(const std::string &newManofacturer)
{
    if (manofacturer == newManofacturer)
        return;
    manofacturer = newManofacturer;
}

std::string ProductModel::getEan() const
{
    return ean;
}

void ProductModel::setEan(const std::string &newEan)
{
    if (ean == newEan)
        return;
    ean = newEan;
}

float ProductModel::getPriceNet() const
{
    return priceNet;
}

void ProductModel::setPriceNet(float newPriceNet)
{

    priceNet = newPriceNet;
}

float ProductModel::getPriceGross() const
{
    return priceGross;
}

void ProductModel::setPriceGross(float newPriceGross)
{

    priceGross = newPriceGross;
}

float ProductModel::getVAT() const
{
    return VAT;
}

void ProductModel::setVAT(float newVAT)
{

    VAT = newVAT;
}

int ProductModel::getId() const
{
    return id;
}

void ProductModel::setId(int newId)
{
    if (id == newId)
        return;
    id = newId;
}

ProductModel::ProductModel() {}
