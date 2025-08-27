#include "invoicerepository.h"
#include "DAL/invoicedal.h"

#include <Model/invoicebodymodel.cpp>

InvoiceRepository::InvoiceRepository() {}

InvoiceBodyModel InvoiceRepository::GetInvoice(int id)
{
    return InvoiceDAL().GetInvoice(id);
}

QList<InvoiceBodyModel> InvoiceRepository::GetAllInvoices()
{
    return InvoiceDAL().GetAllInvoices();
}

bool InvoiceRepository::AddInvoice(InvoiceBodyModel inv, int &invoiceId)
{
    return InvoiceDAL().AddInvoice(inv,invoiceId);
}

bool InvoiceRepository::DeleteInvoice(InvoiceBodyModel inv)
{
    return InvoiceDAL().DeleteInvoice(inv);
}

bool InvoiceRepository::UpdateInvoice(InvoiceBodyModel inv)
{
    return InvoiceDAL().UpdateInvoice(inv);
}
