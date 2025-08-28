#ifndef INVOICEREPOSITORY_H
#define INVOICEREPOSITORY_H

#include <Model/invoicebodymodel.h>


class InvoiceRepository
{
public:
    InvoiceRepository();
    InvoiceBodyModel GetInvoice(int id);
    bool AddInvoice(InvoiceBodyModel inv, int &invoiceId);
    bool DeleteInvoice(InvoiceBodyModel inv);
    bool UpdateInvoice(InvoiceBodyModel inv);
    QList<InvoiceBodyModel> GetAllInvoices();
    QList<InvoiceBodyModel> GetInvoiceByContractor(int contractorId);

};

#endif // INVOICEREPOSITORY_H
