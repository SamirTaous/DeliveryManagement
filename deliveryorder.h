#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H
#include <iostream>
#include <string>
#include <vector>
#include "orderitem.h"

class DeliveryOrder
{
    int orderID;
    std::string customerInfo;
    std::string deliveryAddress;
    std::vector<OrderItem> orderItems;
    std::string deliveryStatus;


public:
    DeliveryOrder(int _orderID,const std::string& _customerInfo,const std::string& deliveryAddress,const std::vector<OrderItem>& _orderItems,const std::string& _deliveryStatus);

    void setOrderID(int _orderID);
    int getOrderID() const;

    void setCustomerInfo(const std::string& _customerInfo);
    std::string getCustomerInfo() const;

    void setDeliveryAddress(const std::string& _deliveryAddress);
    std::string getDeliveryAddress() const;

    void setOrderItems(const std::vector<OrderItem>& _orderItems);
    std::vector<OrderItem> getOrderItems() const;

    void setDeliveryStatus(const std::string& _deliveryStatus);
    std::string getDeliveryStatus() const;
};

#endif // DELIVERYORDER_H
