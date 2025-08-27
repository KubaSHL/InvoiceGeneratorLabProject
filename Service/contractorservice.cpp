#include "contractorservice.h"
#include "Repository/contractorrepository.h"

ContractorService::ContractorService() {}

ContractorModel ContractorService::GetContractor(int id)
{
    return ContractorRepository().GetContractor(id);
}

QList<ContractorModel> ContractorService::GetAllContractors()
{
    return ContractorRepository().GetAllContractors();

}

bool ContractorService::AddContractor(ContractorModel ct)
{
    return ContractorRepository().AddContractor(ct);

}

bool ContractorService::DeleteContractor(ContractorModel ct)
{
    return ContractorRepository().DeleteContractor(ct);

}

bool ContractorService::UpdateContractor(ContractorModel ct)
{
    return ContractorRepository().UpdateContractor(ct);

}
