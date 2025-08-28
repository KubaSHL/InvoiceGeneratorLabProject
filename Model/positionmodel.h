#ifndef POSITIONMODEL_H
#define POSITIONMODEL_H

class PositionModel
{
private:
    int id;
    int invoiceId;
    int productId;
    int quantity;
    float priceNet;
    float valueNet;
public:
    PositionModel();

    int getId() const;
    void setId(int newId);
    int getInvoiceId() const;
    void setInvoiceId(int newInvoiceId);
    int getProductId() const;
    void setProductId(int newProductId);
    int getQuantity() const;
    void setQuantity(int newQuantity);
    float getValueNet() const;
    void setValueNet(float newValueNet);
    float getPriceNet() const;
    void setPriceNet(float newPriceNet);
};

#endif // POSITIONMODEL_H
