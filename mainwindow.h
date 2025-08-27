#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ContractorsView.h>
#include <InvoiceView.h>
#include <ProductView.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_invoice_clicked();

    void on_pushButton_product_clicked();

    void on_pushButton_contractor_clicked();

private:
    Ui::MainWindow *ui;
    InvoiceView invoiceView;
    ProductView productView;
    ContractorsView contractorsView;

};
#endif // MAINWINDOW_H
