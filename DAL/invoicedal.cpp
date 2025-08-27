#include "invoicedal.h"

InvoiceDAL::InvoiceDAL() {}

QList<InvoiceBodyModel> InvoiceDAL::GetAllInvoices(){

    QList<InvoiceBodyModel> allInvoices;
    for (const QStringList &line :  fileWorker->ReadFileContent(filePath)) {
        InvoiceBodyModel inv;
        inv.setId(line[0].toInt());
        inv.setPayment(line[1].toStdString());
        inv.setContractorId(line[2].toInt());
        allInvoices.append(inv);
        break;
    }
    return allInvoices;
}


InvoiceBodyModel InvoiceDAL::GetInvoice(int id){
    InvoiceBodyModel inv;
    for (const QStringList &line :  fileWorker->ReadFileContent(filePath)) {
        if(line[0].toInt()==id)
        {
            InvoiceBodyModel inv;
            inv.setId(line[0].toInt());
            inv.setPayment(line[1].toStdString());
            inv.setContractorId(line[2].toInt());
        }
    }
    return inv;
}

bool InvoiceDAL::AddInvoice(InvoiceBodyModel inv, int &invoiceId){

    QString name = QString::fromStdString(inv.getPayment());
    QString sname = QString::number(inv.getContractorId());
    QStringList newinv = {name,sname};
    invoiceId = fileWorker->AddObjectToFile(filePath,newinv);
    return invoiceId==0?false:true;
}

bool InvoiceDAL::DeleteInvoice(InvoiceBodyModel inv){
    return fileWorker->RemoveLineFromFile(filePath,inv.getId());
}

bool InvoiceDAL::UpdateInvoice(InvoiceBodyModel inv){
    QString id = QString::number(inv.getId());
    QString name = QString::fromStdString(inv.getPayment());
    QString sname = QString::number(inv.getContractorId());
    QStringList newinv = {name,sname};
    return fileWorker->AddObjectToFile(filePath,newinv);
}
