#ifndef INVOICEREPOSITORY_H
#define INVOICEREPOSITORY_H

#include <Model/invoicebodymodel.h>


class InvoiceRepository
{
public:
    InvoiceRepository();
    InvoiceBodyModel GetInvoice();
    bool AddInvoice(InvoiceBodyModel inv);
    bool DeleteInvoice(InvoiceBodyModel inv);
    bool UpdateInvoice(InvoiceBodyModel inv);
};

#endif // INVOICEREPOSITORY_H
