#ifndef CONTRACTORMODEL_H
#define CONTRACTORMODEL_H

#include <string>
class ContractorModel
{
private:
    int id;
    std::string address;
    std::string name;
    std::string sname;
    std::string nip;

public:

    ContractorModel();
    int getId() const;
    void setId(int newId);
    std::string getAddress() const;
    void setAddress(const std::string &newAddress);
    std::string getName() const;
    void setName(const std::string &newName);
    std::string getSname() const;
    void setSname(const std::string &newSname);
    std::string getNip() const;
    void setNip(const std::string &newNip);

};

#endif // CONTRACTORMODEL_H
