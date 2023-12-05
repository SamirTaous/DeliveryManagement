#include "deliveryorder.h"
#include <iostream>
#include <string>
#include <vector>
#include "orderitem.h"

DeliveryOrder::DeliveryOrder(int _orderID,const std::string& _customerInfo,const std::string& _deliveryAddress,const int _orderItems,const std::string& _deliveryStatus)
    : orderID{_orderID},customerInfo{_customerInfo},deliveryAddress{_deliveryAddress},orderItems{_orderItems},deliveryStatus{_deliveryStatus} {}

void DeliveryOrder::setOrderID(int _orderID){
    orderID=_orderID;
}
int DeliveryOrder::getOrderID() const{
    return orderID;
}

void DeliveryOrder::setCustomerInfo(const std::string& _customerInfo)
{
    customerInfo=_customerInfo;
}
std::string DeliveryOrder::getCustomerInfo() const{
    return customerInfo;
}

void DeliveryOrder::setDeliveryAddress(const std::string& _deliveryAddress){
    deliveryAddress=_deliveryAddress;
}
std::string DeliveryOrder::getDeliveryAddress() const{
    return deliveryAddress;
}

void DeliveryOrder::setOrderItems(const int _orderItems){
    orderItems=_orderItems;
}
int DeliveryOrder::getOrderItems() const{
    return orderItems;
}

void DeliveryOrder::setDeliveryStatus(const std::string& _deliveryStatus){
    deliveryStatus=_deliveryStatus;
}
std::string DeliveryOrder::getDeliveryStatus() const{
    return deliveryStatus;
}
