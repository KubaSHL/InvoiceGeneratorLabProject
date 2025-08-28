#ifndef PRODUCTDAL_H
#define PRODUCTDAL_H

#include <Model/productmodel.h>
#include <Workers/fileworker.h>
#include <qlist.h>


class ProductDAL
{
public:
    ProductDAL();
    bool SaveProduct(ProductModel pm);
    QList<ProductModel> GetAllProducts();
    ProductModel GetProduct(int id);
    bool DeleteProduct(ProductModel pm);
    bool UpdateProduct(ProductModel pm);
private:
    const QString filePath = "..\\..\\..\\InvoiceGenerator\\Database\\products.txt";//do zmiany
    FileWorker* fileWorker;
};

#endif // PRODUCTDAL_H
