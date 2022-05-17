#include <iostream>
#include <string>
#include "Stock.h"

Stock::Stock(string name, double price) {
    this->name = name;
    this->price = price;
}

Stock::Stock() {
    this->name = "";
    this->price = 0;
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

void Stock::setName(string newName) {
    this->name = newName;
}

string Stock::getName() {
    return this->name;
}