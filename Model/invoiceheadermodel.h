#ifndef INVOICEHEADERMODEL_H
#define INVOICEHEADERMODEL_H
#include "qtmetamacros.h"
#include <string>
class InvoiceHeaderModel
{
private:
    std::string addres;
    std::string reciver;
    std::string payment;
public:
    InvoiceHeaderModel();

    std::string getAddres() const;
    void setAddres(const std::string &newAddres);
    std::string getReciver() const;
    void setReciver(const std::string &newReciver);
    std::string getPayment() const;
    void setPayment(const std::string &newPayment);
signals:
    void addresChanged();
    void reciverChanged();
    void paymentChanged();
};

#endif // INVOICEHEADERMODEL_H
