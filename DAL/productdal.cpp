#include "productdal.h"
#include "qlist.h"

#include <Model/productmodel.h>

#include <QFile>
#include <QTextStream>

ProductDAL::ProductDAL() {}

QList<ProductModel> ProductDAL::GetAllProducts(){

    QList<ProductModel> allProducts;
    for (const QStringList &line :  fileWorker->ReadFileContent(filePath)) {
        ProductModel pm;
        pm.setId(line[0].toInt());
        pm.setName(line[1].toStdString());
        pm.setEan(line[2].toStdString());
        pm.setManofacturer(line[3].toStdString());
        pm.setPriceNet(line[4].toFloat());
        pm.setVAT(line[5].toFloat());
        pm.setPriceGross(line[6].toFloat());
        allProducts.append(pm);
    }
    return allProducts;
}


ProductModel ProductDAL::GetProduct(int id){
    ProductModel pm;
    for (const QStringList &line :  fileWorker->ReadFileContent(filePath)) {
        ProductModel pm;
        pm.setId(line[0].toInt());
        pm.setName(line[1].toStdString());
        pm.setEan(line[2].toStdString());
        pm.setManofacturer(line[3].toStdString());
        pm.setPriceNet(line[4].toFloat());
        pm.setVAT(line[5].toFloat());
        pm.setPriceGross(line[6].toFloat());

    }
    return pm;
}

bool ProductDAL::SaveProduct(ProductModel pm){

    QString name = QString::fromStdString(pm.getName());
    QString ean = QString::fromStdString(pm.getEan());
    QString manofacturer = QString::fromStdString(pm.getManofacturer());
    QString netPrice = QString::number(pm.getPriceNet());
    QString vat = QString::number(pm.getVAT());
    QString grossPrice = QString::number(pm.getPriceGross());
    QStringList newPm = {name,ean,manofacturer,netPrice,vat,grossPrice};
    return fileWorker->AddObjectToFile(filePath,newPm);
}

bool ProductDAL::DeleteProduct(ProductModel pm){
    return fileWorker->RemoveLineFromFile(filePath,pm.getId());
}

bool ProductDAL::UpdateProduct(ProductModel pm){
    QString id = QString::number(pm.getId());
    QString name = QString::fromStdString(pm.getName());
    QString ean = QString::fromStdString(pm.getEan());
    QString manofacturer = QString::fromStdString(pm.getManofacturer());
    QString netPrice = QString::number(pm.getPriceNet());
    QString vat = QString::number(pm.getVAT());
    QString grossPrice = QString::number(pm.getPriceGross());
    QStringList newPm = {id,name,ean,manofacturer,netPrice,vat,grossPrice};
    return fileWorker->ModifyLineInFile(filePath,pm.getId(),newPm);
}
