#include "OrderItem.h"

OrderItem::OrderItem(int _productID, int _quantity)
    : productID(_productID), quantity(_quantity) {}

void OrderItem::setProductID(int _productID) {
    productID = _productID;
}

int OrderItem::getProductID() const {
    return productID;
}

void OrderItem::setQuantity(int _quantity) {
    quantity = _quantity;
}

int OrderItem::getQuantity() const {
    return quantity;
}
