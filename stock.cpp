#include <iostream>
#include <string>
#include "Stock.h"

Stock::Stock(string name, double price) {
    this->name = name;
    this->price = price;
}

void Stock::setPrice(double newPrice) {
    if (this->price > 0) {
        this->price = newPrice;
    }
    else {
        printf("Not valid price\n");
    }
}

double Stock::getPrice() {
    return this->price;
}