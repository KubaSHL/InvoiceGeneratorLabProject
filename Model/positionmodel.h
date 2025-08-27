#ifndef POSITIONMODEL_H
#define POSITIONMODEL_H

class PositionModel
{
private:
    int id;
    int invoiceId;
    int productId;
    int quantity;
    float valueNet;
    float valueGross;
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
    float getValueGross() const;
    void setValueGross(float newValueGross);
};

#endif // POSITIONMODEL_H
