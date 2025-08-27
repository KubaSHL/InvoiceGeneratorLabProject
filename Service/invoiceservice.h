#ifndef INVOICESERVICE_H
#define INVOICESERVICE_H

#include <Model/invoicebodymodel.h>


class InvoiceService
{
public:
    InvoiceService();
    InvoiceBodyModel GetInvoice();
    bool AddInvoice(InvoiceBodyModel inv);
    bool DeleteInvoice(InvoiceBodyModel inv);
    bool UpdateInvoice(InvoiceBodyModel inv);
};

#endif // INVOICESERVICE_H
