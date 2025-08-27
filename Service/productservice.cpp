#include "productservice.h"
#include "Repository/productrepository.h"

#include <QList>

ProductService::ProductService() {}

QList<ProductModel> ProductService::GetAllProducts(){
    return ProductRepository().GetAllProducts();
}

bool ProductService::AddProduct(ProductModel pm){
    return ProductRepository().AddProduct(pm);
}

bool ProductService::UpdateProduct(ProductModel pm){
    return ProductRepository().UpdateProduct(pm);
}

bool ProductService::DeleteProduct(ProductModel pm){
    return ProductRepository().DeleteProduct(pm);
}
