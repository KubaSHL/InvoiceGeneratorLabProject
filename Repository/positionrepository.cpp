#include "positionrepository.h"
#include "DAL/InvoicePositionDAL.h"

PositionRepository::PositionRepository() {}

PositionModel PositionRepository::GetPosition(int id)
{
    return InvoicePositionDAL().GetPosition(id);
}

QList<PositionModel> PositionRepository::GetAllPositionsForInvoice(int &invoiceId)
{
    return InvoicePositionDAL().GetAllPositionsForInvoice(invoiceId);
}

QList<PositionModel> PositionRepository::GetAllPositions()
{
    return InvoicePositionDAL().GetAllPositions();
}

bool PositionRepository::AddPosition(PositionModel pos)
{
    return InvoicePositionDAL().AddPosition(pos);
}

bool PositionRepository::DeletePosition(PositionModel pos)
{
    return InvoicePositionDAL().DeletePosition(pos);
}

bool PositionRepository::UpdatePosition(PositionModel pos)
{
    return InvoicePositionDAL().UpdatePosition(pos);
}
