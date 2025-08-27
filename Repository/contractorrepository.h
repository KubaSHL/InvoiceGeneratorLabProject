#ifndef CONTRACTORREPOSITORY_H
#define CONTRACTORREPOSITORY_H

#include <Model/contractormodel.h>


class ContractorRepository
{
public:
    ContractorRepository();
    ContractorModel GetContractor();
    bool AddContractor(ContractorModel ct);
    bool DeleteContractor(ContractorModel ct);
    bool UpdateContractor(ContractorModel ct);
};

#endif // CONTRACTORREPOSITORY_H
