#include "contractorservice.h"
#include "Repository/contractorrepository.h"
#include "Service/invoiceservice.h"

#include <Repository/invoicerepository.h>

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
    if(InvoiceRepository().GetInvoiceByContractor(ct.getId()).size()>0){
        return false;
    }
    return ContractorRepository().DeleteContractor(ct);

}

bool ContractorService::UpdateContractor(ContractorModel ct)
{
    return ContractorRepository().UpdateContractor(ct);

}
