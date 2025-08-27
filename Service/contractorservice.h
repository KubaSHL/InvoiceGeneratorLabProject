#ifndef CONTRACTORSERVICE_H
#define CONTRACTORSERVICE_H

#include "Model/contractormodel.h"
class ContractorService
{
public:
    ContractorService();
    ContractorModel GetContractor();
    bool AddContractor(ContractorModel ct);
    bool DeleteContractor(ContractorModel ct);
    bool UpdateContractor(ContractorModel ct);
};

#endif // CONTRACTORSERVICE_H
