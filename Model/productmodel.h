#ifndef PRODUCTMODEL_H
#define PRODUCTMODEL_H

#include <string>

class ProductModel
{
private:
    int id;
    std::string name;
    std::string manofacturer;
    std::string ean;
    float priceNet;
    float priceGross;
    float VAT;
public:
    ProductModel(): id(0), priceNet(0.0f), priceGross(0.0f), VAT(0.0f){};

    std::string getName() const;
    void setName(const std::string &newName);
    std::string getManofacturer() const;
    void setManofacturer(const std::string &newManofacturer);
    std::string getEan() const;
    void setEan(const std::string &newEan);
    float getPriceNet() const;
    void setPriceNet(float newPriceNet);
    float getPriceGross() const;
    void setPriceGross(float newPriceGross);
    float getVAT() const;
    void setVAT(float newVAT);
    int getId() const;
    void setId(int newId);

};

#endif // PRODUCTMODEL_H
