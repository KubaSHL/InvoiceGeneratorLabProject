#ifndef CONTRACTORSERVICE_H
#define CONTRACTORSERVICE_H

#include "Model/contractormodel.h"
#include "qlist.h"
class ContractorService
{
public:
    ContractorService();
    ContractorModel GetContractor(int id);
    QList<ContractorModel> GetAllContractors();
    bool AddContractor(ContractorModel ct);
    bool DeleteContractor(ContractorModel ct);
    bool UpdateContractor(ContractorModel ct);
};

#endif // CONTRACTORSERVICE_H
