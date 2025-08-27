#include "productrepository.h"
#include "DAL/productdal.h"

ProductRepository::ProductRepository() {}

QList<ProductModel> ProductRepository::GetAllProducts(){
    return ProductDAL().GetAllProducts();
}
ProductModel ProductRepository::GetProduct(int id){
    return ProductDAL().GetProduct(id);
}
bool ProductRepository::AddProduct(ProductModel pm){
    return ProductDAL().SaveProduct(pm);
}

bool ProductRepository::UpdateProduct(ProductModel pm){
    return ProductDAL().UpdateProduct(pm);
}

bool ProductRepository::DeleteProduct(ProductModel pm){
    return ProductDAL().DeleteProduct(pm);
}
