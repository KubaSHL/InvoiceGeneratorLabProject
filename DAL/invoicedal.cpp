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
    }
    return allInvoices;
}


InvoiceBodyModel InvoiceDAL::GetInvoice(int id){
    InvoiceBodyModel inv;
    for (const QStringList &line :  fileWorker->ReadFileContent(filePath)) {
        if(line[0].toInt()==id)
        {
            inv.setId(line[0].toInt());
            inv.setPayment(line[1].toStdString());
            inv.setContractorId(line[2].toInt());
            break;
        }
    }
    return inv;
}

bool InvoiceDAL::AddInvoice(InvoiceBodyModel inv, int &invoiceId){

    QString payment = QString::fromStdString(inv.getPayment());
    QString contractor = QString::number(inv.getContractorId());
    QStringList newinv = {payment,contractor};
    invoiceId = fileWorker->AddObjectToFile(filePath,newinv);
    return invoiceId==0?false:true;
}

bool InvoiceDAL::DeleteInvoice(InvoiceBodyModel inv){
    return fileWorker->RemoveLineFromFile(filePath,inv.getId());
}

bool InvoiceDAL::UpdateInvoice(InvoiceBodyModel inv){
    QString id = QString::number(inv.getId());
    QString payment = QString::fromStdString(inv.getPayment());
    QString contractor = QString::number(inv.getContractorId());
    QStringList newinv = {id,payment,contractor};
    return fileWorker->ModifyLineInFile(filePath,inv.getId(),newinv);
}


QList<InvoiceBodyModel> InvoiceDAL::GetInvoiceByContractor(int contractorId){
    QList<InvoiceBodyModel> allInvoices;
    for (const QStringList &line :  fileWorker->ReadFileContent(filePath)) {
        if(line[2].toInt()==contractorId)
        {
        InvoiceBodyModel inv;
        inv.setId(line[0].toInt());
        inv.setPayment(line[1].toStdString());
        inv.setContractorId(line[2].toInt());
        allInvoices.append(inv);
        }
    }
    return allInvoices;
}


