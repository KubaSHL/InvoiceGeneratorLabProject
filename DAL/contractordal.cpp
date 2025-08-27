#include "contractordal.h"

#include <QString>

ContractorDAL::ContractorDAL() {}

QList<ContractorModel> ContractorDAL::GetAllContractors(){

    QList<ContractorModel> allContractors;
    for (const QStringList &line :  fileWorker->ReadFileContent(filePath)) {
        ContractorModel ct;
        ct.setId(line[0].toInt());
        ct.setName(line[1].toStdString());
        ct.setSname(line[2].toStdString());
        ct.setAddress(line[3].toStdString());
        ct.setNip(line[4].toStdString());

        allContractors.append(ct);
    }
    return allContractors;
}


ContractorModel ContractorDAL::GetContractor(int id){
    ContractorModel ct;
    for (const QStringList &line :  fileWorker->ReadFileContent(filePath)) {
        if(line[0].toInt()==id)
        {
            ct.setId(line[0].toInt());
            ct.setName(line[1].toStdString());
            ct.setSname(line[2].toStdString());
            ct.setAddress(line[3].toStdString());
            ct.setNip(line[4].toStdString());
            break;
        }

    }
    return ct;
}

bool ContractorDAL::AddContractor(ContractorModel ct){

    QString name = QString::fromStdString(ct.getName());
    QString sname = QString::fromStdString(ct.getSname());
    QString address = QString::fromStdString(ct.getAddress());
    QString nip = QString::fromStdString(ct.getNip());
    QStringList newct = {name,sname,address,nip};
    return fileWorker->AddObjectToFile(filePath,newct)==0?false:true;
}

bool ContractorDAL::DeleteContractor(ContractorModel ct){
    return fileWorker->RemoveLineFromFile(filePath,ct.getId());
}

bool ContractorDAL::UpdateContractor(ContractorModel ct){
    QString id = QString::number(ct.getId());
    QString name = QString::fromStdString(ct.getName());
    QString sname = QString::fromStdString(ct.getSname());
    QString address = QString::fromStdString(ct.getAddress());
    QString nip = QString::fromStdString(ct.getNip());
    QStringList newct = {id,name,sname,address,nip};
    return fileWorker->ModifyLineInFile(filePath,ct.getId(),newct);
}
