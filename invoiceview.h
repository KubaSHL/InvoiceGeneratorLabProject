#ifndef INVOICEVIEW_H
#define INVOICEVIEW_H

#include <QWidget>
#include <qstandarditemmodel.h>

namespace Ui {
class InvoiceView;
}

class InvoiceView : public QWidget
{
    Q_OBJECT

public:
    explicit InvoiceView(QWidget *parent = nullptr);
    ~InvoiceView();

    void ShowInvoices();
private slots:
    void on_pushButton_add_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::InvoiceView *ui;
    QWidget *QWidget;
    QStandardItemModel *model;
};

#endif // INVOICEVIEW_H
