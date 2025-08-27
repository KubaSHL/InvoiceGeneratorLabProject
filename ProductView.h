#ifndef PRODUCTVIEW_H
#define PRODUCTVIEW_H

#include <DialogAddProduct.h>
#include <QStandardItemModel>
#include <QWidget>

namespace Ui {
class ProductView;
}

class ProductView : public QWidget
{
    Q_OBJECT

public:
    explicit ProductView(QWidget *parent = nullptr);
    ~ProductView();


    void ShowProducts();
private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_del_clicked();

private:
    void GetData();
    Ui::ProductView *ui;
    DialogAddProduct dialogAddProduct;
    QWidget *QWidget;
    QStandardItemModel *model;

};

#endif // PRODUCTVIEW_H
