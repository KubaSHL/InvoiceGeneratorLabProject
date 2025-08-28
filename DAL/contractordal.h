#ifndef CONTRACTORDAL_H
#define CONTRACTORDAL_H

#include "Model/contractormodel.h"
#include "Workers/fileworker.h"

class ContractorDAL
{
public:
    ContractorDAL();
    QList<ContractorModel> GetAllContractors();
    ContractorModel GetContractor(int id);
    bool AddContractor(ContractorModel ct);
    bool DeleteContractor(ContractorModel ct);
    bool UpdateContractor(ContractorModel ct);

private:
    const QString filePath = "..\\..\\..\\InvoiceGenerator\\Database\\contractors.txt";//do zmiany
    FileWorker* fileWorker;

};
#endif // CONTRACTORDAL_H
