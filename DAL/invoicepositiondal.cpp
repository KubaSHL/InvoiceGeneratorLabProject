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
        pos.setValueNet(line[4].toFloat());
        pos.setValueGross(line[5].toFloat());
        allPositions.append(pos);
        break;
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
            pos.setValueNet(line[4].toFloat());
            pos.setValueGross(line[5].toFloat());
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
            pos.setValueNet(line[4].toFloat());
            pos.setValueGross(line[5].toFloat());
        }

    }
    return pos;
}

bool InvoicePositionDAL::AddPosition(PositionModel pos){

    QString invoice = QString::number(pos.getInvoiceId());
    QString product = QString::number(pos.getProductId());
    QString quantity = QString::number(pos.getQuantity());
    QString netVal = QString::number(pos.getValueNet());
    QString grossVal = QString::number(pos.getValueGross());
    QStringList newpos = {invoice,product,quantity,netVal,grossVal};
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
    QString netVal = QString::number(pos.getValueNet());
    QString grossVal = QString::number(pos.getValueGross());
    QStringList newpos = {invoice,product,quantity,netVal,grossVal};
    return fileWorker->ModifyLineInFile(filePath,pos.getId(),newpos);
}
