#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <string>

class OrderItem {
    int productID;
    int quantity;
public:
    OrderItem(int _productID, int _quantity);

    void setProductID(int _productID);
    int getProductID() const;

    void setQuantity(int _quantity);
    int getQuantity() const;
};

#endif // ORDERITEM_H
