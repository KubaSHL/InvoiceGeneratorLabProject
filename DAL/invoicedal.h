#ifndef INVOICEDAL_H
#define INVOICEDAL_H

#include "Model/invoicebodymodel.h"
#include "Workers/fileworker.h"

class InvoiceDAL
{
public:
    InvoiceDAL();
    bool AddInvoice(InvoiceBodyModel inv, int &invoiceId);
    bool DeleteInvoice(InvoiceBodyModel inv);
    bool UpdateInvoice(InvoiceBodyModel inv);
    InvoiceBodyModel GetInvoice(int id);
    QList<InvoiceBodyModel> GetAllInvoices();
private:
    const QString filePath = "C:\\Users\\sageh\\Downloads\\InvoiceGenerator\\InvoiceGenerator\\Database\\Invoices.txt";//do zmiany
    FileWorker* fileWorker;

};

#endif // INVOICEDAL_H
