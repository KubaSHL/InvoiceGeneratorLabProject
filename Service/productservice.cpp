#include "productservice.h"
#include "Repository/positionrepository.h"
#include "Repository/productrepository.h"

#include <QList>

ProductService::ProductService() {}

QList<ProductModel> ProductService::GetAllProducts(){
    return ProductRepository().GetAllProducts();
}

ProductModel ProductService::GetProduct(int id){
    return ProductRepository().GetProduct(id);
}

bool ProductService::AddProduct(ProductModel pm){
    return ProductRepository().AddProduct(pm);
}

bool ProductService::UpdateProduct(ProductModel pm){
    return ProductRepository().UpdateProduct(pm);
}

bool ProductService::DeleteProduct(ProductModel pm){
    if(PositionRepository().GetPositionWithProductId(pm.getId()).size()>0){
        return false;
    }

    return ProductRepository().DeleteProduct(pm);
}
