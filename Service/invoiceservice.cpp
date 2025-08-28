#include "invoiceservice.h"
#include "Repository/contractorrepository.h"
#include "Repository/invoicerepository.h"
#include "Repository/positionrepository.h"

InvoiceService::InvoiceService() {}

InvoiceBodyModel InvoiceService::GetInvoice(int id)
{
    InvoiceBodyModel inv = InvoiceRepository().GetInvoice(id);
    inv.setInvoiceHeader(ContractorRepository().GetContractor(inv.getContractorId()));
    inv.setPositionList(PositionRepository().GetAllPositionsForInvoice(id));
    return inv;
}

QList<InvoiceBodyModel> InvoiceService::GetAllInvoices()
{

    QList<InvoiceBodyModel> invList = InvoiceRepository().GetAllInvoices();
    for(InvoiceBodyModel &inv : invList){
        int invid = inv.getId();
        inv.setInvoiceHeader(ContractorRepository().GetContractor(inv.getContractorId()));
        inv.setPositionList(PositionRepository().GetAllPositionsForInvoice(invid));

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
    int invoiceInt = inv.getId();
    bool invoiceUpdated = InvoiceRepository().UpdateInvoice(inv);
    bool positionsUpdated = true;
    for(PositionModel &pos : inv.getPositionList())
    {
        pos.setInvoiceId(invoiceInt);
        PositionRepository().UpdatePosition(pos)?positionsUpdated=true:positionsUpdated=false;
    }
    return invoiceUpdated*positionsUpdated;

}
