#ifndef INVOICEDETAILSVIEW_H
#define INVOICEDETAILSVIEW_H

#include "Model/invoicebodymodel.h"
#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class InvoiceDetailsView;
}

class InvoiceDetailsView : public QDialog
{
    Q_OBJECT

public:
    explicit InvoiceDetailsView(QDialog *parent = nullptr);
    ~InvoiceDetailsView();

    void OnContractorChanged(int index);

    void SetInvoice(InvoiceBodyModel *thisInvoice);
    void ShowPositions();
private:
    Ui::InvoiceDetailsView *ui;
    QStandardItemModel *modelCt;
    InvoiceBodyModel *invoice;
};

#endif // INVOICEDETAILSVIEW_H
