#include "invoicepositiondal.h"

InvoicePositionDAL::InvoicePositionDAL() {}

QList<PositionModel> InvoicePositionDAL::GetAllPositions(){

    QList<PositionModel> allPositions;
    for (const QStringList &line :  fileWorker->ReadFileContent(filePath)) {
        PositionModel pos;
        pos.setId(line[0].toInt());
        pos.setInvoiceId(line[1].toInt());
        pos.setProductId(line[2].toInt());
        pos.setQuantity(line[3].toInt());
        pos.setPriceNet(line[4].toFloat());
        pos.setValueNet(line[5].toFloat());
        allPositions.append(pos);
    }
    return allPositions;
}

QList<PositionModel> InvoicePositionDAL::GetAllPositionsForInvoice(int &invoiceId){
    QList<PositionModel> allPositions;
    for (const QStringList &line :  fileWorker->ReadFileContent(filePath)) {
        if(line[1].toInt()==invoiceId)
        {
            PositionModel pos;
            pos.setId(line[0].toInt());
            pos.setInvoiceId(line[1].toInt());
            pos.setProductId(line[2].toInt());
            pos.setQuantity(line[3].toInt());
            pos.setPriceNet(line[4].toFloat());
            pos.setValueNet(line[5].toFloat());
            allPositions.append(pos);
        }


    }
    return allPositions;
}

PositionModel InvoicePositionDAL::GetPosition(int id){
    PositionModel pos;
    for (const QStringList &line :  fileWorker->ReadFileContent(filePath)) {
        if(line[0].toInt()==id)
        {
            pos.setId(line[0].toInt());
            pos.setInvoiceId(line[1].toInt());
            pos.setProductId(line[2].toInt());
            pos.setQuantity(line[3].toInt());
            pos.setPriceNet(line[4].toFloat());
            pos.setValueNet(line[5].toFloat());
            break;
        }

    }
    return pos;
}

bool InvoicePositionDAL::AddPosition(PositionModel pos){

    QString invoice = QString::number(pos.getInvoiceId());
    QString product = QString::number(pos.getProductId());
    QString quantity = QString::number(pos.getQuantity());
    QString priceNet = QString::number(pos.getPriceNet());
    QString netVal = QString::number(pos.getValueNet());
    QStringList newpos = {invoice,product,quantity,priceNet,netVal};
    return fileWorker->AddObjectToFile(filePath,newpos)==0?false:true;

}

bool InvoicePositionDAL::DeletePosition(PositionModel pos){
    return fileWorker->RemoveLineFromFile(filePath,pos.getId());
}

bool InvoicePositionDAL::UpdatePosition(PositionModel pos){
    QString id = QString::number(pos.getId());
    QString invoice = QString::number(pos.getInvoiceId());
    QString product = QString::number(pos.getProductId());
    QString quantity = QString::number(pos.getQuantity());
    QString priceNet = QString::number(pos.getPriceNet());
    QString netVal = QString::number(pos.getValueNet());
    QStringList newpos = {id,invoice,product,quantity,priceNet,netVal};
    return fileWorker->ModifyLineInFile(filePath,pos.getId(),newpos);
}

QList<PositionModel> InvoicePositionDAL::GetPositionWithProductId(int productId)
{
    QList<PositionModel> allPositions;
    for (const QStringList &line :  fileWorker->ReadFileContent(filePath)) {
        if(line[2].toInt()==productId)
        {
            PositionModel pos;
            pos.setId(line[0].toInt());
            pos.setInvoiceId(line[1].toInt());
            pos.setProductId(line[2].toInt());
            pos.setQuantity(line[3].toInt());
            pos.setPriceNet(line[4].toFloat());
            pos.setValueNet(line[5].toFloat());
            allPositions.append(pos);
        }
    }
    return allPositions;
}
