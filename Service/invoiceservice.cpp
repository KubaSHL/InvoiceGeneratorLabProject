#include "invoiceservice.h"
#include "Repository/contractorrepository.h"
#include "Repository/invoicerepository.h"
#include "Repository/positionrepository.h"

InvoiceService::InvoiceService() {}

InvoiceBodyModel InvoiceService::GetInvoice(int id)
{
    InvoiceBodyModel inv = InvoiceRepository().GetInvoice(id);
    inv.setInvoiceHeader(ContractorRepository().GetContractor(inv.getContractorId()));
    return inv;
}

QList<InvoiceBodyModel> InvoiceService::GetAllInvoices()
{

    QList<InvoiceBodyModel> invList = InvoiceRepository().GetAllInvoices();
    for(InvoiceBodyModel &inv : invList){
        inv.setInvoiceHeader(ContractorRepository().GetContractor(inv.getContractorId()));
    }
    return invList;

}

bool InvoiceService::AddInvoice(InvoiceBodyModel inv)
{
    int invoiceInt;
    bool invoiceAdded = InvoiceRepository().AddInvoice(inv, invoiceInt);
    bool positionsAdded = true;
    for(PositionModel &pos : inv.getPositionList())
    {
        pos.setInvoiceId(invoiceInt);
        PositionRepository().AddPosition(pos)?positionsAdded=true:positionsAdded=false;
    }
    return invoiceAdded*positionsAdded;

}

bool InvoiceService::DeleteInvoice(InvoiceBodyModel inv)
{
    return InvoiceRepository().DeleteInvoice(inv);

}

bool InvoiceService::UpdateInvoice(InvoiceBodyModel inv)
{
    return InvoiceRepository().UpdateInvoice(inv);

}
