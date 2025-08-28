#ifndef POSITIONREPOSITORY_H
#define POSITIONREPOSITORY_H

#include "Model/positionmodel.h"

#include <QList>
class PositionRepository
{
public:
    PositionRepository();
    PositionModel GetPosition(int id);
    QList<PositionModel> GetAllPositions();
    bool AddPosition(PositionModel pos);
    bool DeletePosition(PositionModel pos);
    bool UpdatePosition(PositionModel pos);
    QList<PositionModel> GetAllPositionsForInvoice(int &invoiceId);
    QList<PositionModel> GetPositionWithProductId(int productId);
};

#endif // POSITIONREPOSITORY_H
