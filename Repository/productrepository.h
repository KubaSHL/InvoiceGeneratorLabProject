#ifndef PRODUCTREPOSITORY_H
#define PRODUCTREPOSITORY_H

#include <Model/productmodel.h>

#include <QList>


class ProductRepository
{
public:
    ProductRepository();
    ProductModel GetProduct(int id);
    QList<ProductModel> GetAllProducts();
    bool AddProduct(ProductModel pm);
    bool UpdateProduct(ProductModel pm);
    bool DeleteProduct(ProductModel pm);


};

#endif // PRODUCTREPOSITORY_H
