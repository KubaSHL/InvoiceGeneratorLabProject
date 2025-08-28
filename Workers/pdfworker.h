#ifndef PDFWORKER_H
#define PDFWORKER_H

#include "Workers/fileworker.h"
#include <string>

#include <Model/invoicebodymodel.h>

#include <QMap>
#include <Qstring>
class pdfworker
{
public:
    pdfworker();
    void PrintHTML();
    void SetInvoice(InvoiceBodyModel inv);
private:
    void FileWorker();
    void GetTemplate();
    void CreateHeader(QString header);
    void CreateContractor(QString header);
    void CreatePositionList(QString header);
    void CreateFooter(QString header);
    void GeneratePoisitions();
    QString InsertValues(const QString &html, const QMap<QString, QString> &values);
    std::string pdfTemplateFilePath = "..\\..\\..\\InvoiceGenerator\\Database\\pdftemplate.txt";
    std::string pdfDestinationFilePath = "..\\..\\..\\InvoiceGenerator\\Database\\pdftest.pdf";
    std::string pdfTemplate = "";
    std::string pdfOutput = "";
    QString  positionsHMTL = "";
    InvoiceBodyModel invoice;
    class FileWorker* fileWorker;
    float nettoSum = 0;
    float grossSum = 0;

};

#endif // PDFWORKER_H
