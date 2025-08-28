#ifndef INVOICEPOSITIONDAL_H
#define INVOICEPOSITIONDAL_H

#include "Model/positionmodel.h"
#include <Workers/fileworker.h>


class InvoicePositionDAL
{
public:
    InvoicePositionDAL();
    bool AddPosition(PositionModel pos);
    QList<PositionModel> GetAllPositions();
    PositionModel GetPosition(int id);
    bool DeletePosition(PositionModel pos);
    bool UpdatePosition(PositionModel pos);
    QList<PositionModel> GetAllPositionsForInvoice(int &invoiceId);
    QList<PositionModel> GetPositionWithProductId(int productId);
private:
    const QString filePath = "..\\..\\..\\InvoiceGenerator\\Database\\InvoicePositions.txt";//do zmiany
    FileWorker* fileWorker;
};

#endif // INVOICEPOSITIONDAL_H
