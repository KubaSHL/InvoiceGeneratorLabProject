#ifndef INVOICEBODYMODEL_H
#define INVOICEBODYMODEL_H

#include "Model/contractormodel.h"
#include "Model/positionmodel.h"
#include "productmodel.h"
#include <QList>

class InvoiceBodyModel
{
private:
    int id;
    std::string payment;
    int contractorId;
    ContractorModel invoiceHeader;
    QList<PositionModel> positionList;
public:
    InvoiceBodyModel();
    int getId() const;
    void setId(int newId);
    ContractorModel getInvoiceHeader() const;
    void setInvoiceHeader(const ContractorModel &newInvoiceHeader);
    QList<PositionModel> getPositionList() const;
    void setPositionList(const QList<PositionModel> &newPositionList);
    std::string getPayment() const;
    void setPayment(const std::string &newPayment);
    int getContractorId() const;
    void setContractorId(int newContractorId);
};

#endif // INVOICEBODYMODEL_H
