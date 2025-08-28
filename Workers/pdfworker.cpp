#include "pdfworker.h"

#include <QPrinter>
#include <QTextDocument>

#include <Service/productservice.h>

pdfworker::pdfworker() {}

void pdfworker::PrintHTML(){

    GetTemplate();

    QTextDocument document;
    document.setHtml(QString::fromStdString(pdfOutput));
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(QString::fromStdString(pdfDestinationFilePath));

    document.print(&printer);

}


void pdfworker::SetInvoice(InvoiceBodyModel inv){
    invoice = inv;
}


void pdfworker::GetTemplate(){
    QMap<QString,QString> divs = fileWorker->GetHTMLTemplate(QString::fromStdString(pdfTemplateFilePath));

    CreateHeader(divs.value("invoiceNumber"));

    CreateContractor(divs.value("contractor"));

    CreatePositionList(divs.value("positionsHeaders"));

    CreateFooter(divs.value("footeSum"));

}

void pdfworker::CreateHeader(QString header){
    QMap<QString, QString> values;
    values["nrInvoice"] = QString::number(invoice.getId());
    pdfOutput += InsertValues(header, values).toStdString();
}

void pdfworker::CreateContractor(QString header){
    QMap<QString, QString> values;
    values["Imie"] = QString::fromStdString(invoice.getInvoiceHeader().getName());
    values["Nazwisko"] = QString::fromStdString(invoice.getInvoiceHeader().getSname());
    values["Adres"] = QString::fromStdString(invoice.getInvoiceHeader().getAddress());
    values["NIP"] = QString::fromStdString(invoice.getInvoiceHeader().getNip());
    pdfOutput += InsertValues(header, values).toStdString();

}

void pdfworker::CreatePositionList(QString header){
    QMap<QString, QString> values;
    GeneratePoisitions();

    values["content"] = positionsHMTL;
    pdfOutput += InsertValues(header, values).toStdString();

}

void pdfworker::CreateFooter(QString header){
    QMap<QString, QString> values;
    values["razemNet"] = QString::number(nettoSum);
    values["razemBrut"] = QString::number(grossSum);
    pdfOutput += InsertValues(header, values).toStdString();

}

void pdfworker::GeneratePoisitions(){
    QString htmlPositionTamplate = "<tr>"
                                   "<td style=\"width: 12.5%;\">%LP%</td>"
                                   " <td style=\"width: 12.5%;\">%Nazwa%</td>"
                                   " <td style=\"width: 12.5%;\">%EAN%</td>"
                                   " <td style=\"width: 7.73327%;\">%Ilosc%</td>"
                                   " <td style=\"width: 17.2667%; text-align: center;\">%CentaJed%</td>"
                                   " <td style=\"width: 12.5%;\">%warNet%</td>"
                                   " <td style=\"width: 12.5%;\">%vat%</td>"
                                   " <td style=\"width: 12.5%;\">%warBrut%</td>"
                                   "</tr>";
    int lp = 0;
    for(PositionModel pos : invoice.getPositionList())
    {
        QMap<QString, QString> values;
        ProductModel pm = ProductService().GetProduct(pos.getProductId());
        values["LP"] = QString::number(++lp);
        values["Nazwa"] = QString::fromStdString(pm.getName());
        values["EAN"] = QString::fromStdString(pm.getEan());
        values["Ilosc"] = QString::number(pos.getQuantity());
        values["CentaJed"] = QString::number(pos.getPriceNet());
        values["warNet"] = QString::number(pos.getValueNet());
        values["vat"] = QString::number(pm.getVAT());
        values["warBrut"] = QString::number(((100+pm.getVAT())/100) * pos.getValueNet());
        nettoSum+= pos.getValueNet();
        grossSum+=(((100+pm.getVAT())/100) * pos.getValueNet());
        positionsHMTL += InsertValues(htmlPositionTamplate, values);
    }

}


QString pdfworker::InsertValues(const QString &html, const QMap<QString, QString> &values)
{
    QString result = html;

    for (auto it = values.constBegin(); it != values.constEnd(); ++it) {
        QString placeholder = "%" + it.key() + "%";
        result.replace(placeholder, it.value());
    }

    qDebug() << result;
    return result;
}





