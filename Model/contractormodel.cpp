#include "contractormodel.h"

int ContractorModel::getId() const
{
    return id;
}

void ContractorModel::setId(int newId)
{
    if (id == newId)
        return;
    id = newId;
}

std::string ContractorModel::getAddress() const
{
    return address;
}

void ContractorModel::setAddress(const std::string &newAddress)
{
    if (address == newAddress)
        return;
    address = newAddress;
}

std::string ContractorModel::getName() const
{
    return name;
}

void ContractorModel::setName(const std::string &newName)
{
    if (name == newName)
        return;
    name = newName;
}

std::string ContractorModel::getSname() const
{
    return sname;
}

void ContractorModel::setSname(const std::string &newSname)
{
    if (sname == newSname)
        return;
    sname = newSname;
}

std::string ContractorModel::getNip() const
{
    return nip;
}

void ContractorModel::setNip(const std::string &newNip)
{
    if (nip == newNip)
        return;
    nip = newNip;
}

ContractorModel::ContractorModel() {}
