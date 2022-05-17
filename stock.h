#pragma once
#include <iostream>
#include <string>

using namespace std;

class Stock {
private:
    string name;
    double price;
public:
    Stock(string name, double price);
    Stock();
    void setPrice(double newPrice);
    double getPrice();
    void setName(string newName);
    string getName();
};



