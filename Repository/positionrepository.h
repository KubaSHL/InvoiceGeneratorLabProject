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
    bool AddPosition(PositionModel ct);
    bool DeletePosition(PositionModel ct);
    bool UpdatePosition(PositionModel ct);
    QList<PositionModel> GetAllPositionsForInvoice(int &invoiceId);
};

#endif // POSITIONREPOSITORY_H
