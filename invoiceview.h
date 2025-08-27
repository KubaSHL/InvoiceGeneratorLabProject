#ifndef INVOICEVIEW_H
#define INVOICEVIEW_H

#include <QWidget>

namespace Ui {
class InvoiceView;
}

class InvoiceView : public QWidget
{
    Q_OBJECT

public:
    explicit InvoiceView(QWidget *parent = nullptr);
    ~InvoiceView();

private slots:
    void on_pushButton_add_clicked();

private:
    Ui::InvoiceView *ui;
    QWidget *QWidget;
};

#endif // INVOICEVIEW_H
