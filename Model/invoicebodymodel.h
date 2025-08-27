#ifndef INVOICEBODYMODEL_H
#define INVOICEBODYMODEL_H

#include "invoiceheadermodel.h"
#include "productmodel.h"
#include <QList>

class InvoiceBodyModel
{
private:
    int id;
    InvoiceHeaderModel invoiceHeader;
    QList<ProductModel> productList;
public:
    InvoiceBodyModel();
};

#endif // INVOICEBODYMODEL_H
