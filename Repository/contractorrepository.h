#ifndef CONTRACTORREPOSITORY_H
#define CONTRACTORREPOSITORY_H

#include <Model/contractormodel.h>

#include <QList>


class ContractorRepository
{
public:
    ContractorRepository();
    ContractorModel GetContractor(int id);
    QList<ContractorModel> GetAllContractors();
    bool AddContractor(ContractorModel ct);
    bool DeleteContractor(ContractorModel ct);
    bool UpdateContractor(ContractorModel ct);
};

#endif // CONTRACTORREPOSITORY_H
