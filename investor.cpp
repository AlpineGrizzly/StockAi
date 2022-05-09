#include <iostream>
#include <string>
#include "investor.h"

Investor::Investor(string name, double numMoney) {
    this->name = name;
    this->numMoney = numMoney;
    //ownedStocks = new Stock[3]; Need to find way to store stocks without breaking memory
}