#include "contractorrepository.h"
#include "DAL/contractordal.h"

#include <Model/contractormodel.h>

ContractorRepository::ContractorRepository() {}

ContractorModel ContractorRepository::GetContractor(int id)
{
    return ContractorDAL().GetContractor(id);
}

QList<ContractorModel> ContractorRepository::GetAllContractors()
{
    return ContractorDAL().GetAllContractors();
}

bool ContractorRepository::AddContractor(ContractorModel ct)
{
    return ContractorDAL().AddContractor(ct);
}

bool ContractorRepository::DeleteContractor(ContractorModel ct)
{
    return ContractorDAL().DeleteContractor(ct);
}

bool ContractorRepository::UpdateContractor(ContractorModel ct)
{
    return ContractorDAL().UpdateContractor(ct);
}
