#ifndef PRODUCTSERVICE_H
#define PRODUCTSERVICE_H

#include "Model/productmodel.h"

#include <QList>
class ProductService
{
public:
    ProductService();
    ProductModel GetProduct(int id);
    bool AddProduct(ProductModel pm);
    bool UpdateProduct(ProductModel pm);
    bool DeleteProduct(ProductModel pm);
    QList<ProductModel> GetAllProducts();
};

#endif // PRODUCTSERVICE_H
