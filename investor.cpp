#include <iostream>
#include <string>
#include "investor.h"

Investor::Investor(string name, double numMoney) {
    this->name = name;
    this->numMoney = numMoney;
    //ownedStocks = new Stock[3]; Need to find way to store stocks without breaking memory
}

void Investor::setName(string newName) {
    this->name = newName;
}

string Investor::getName() {
    return this->name;
}
void Investor::setMoney(double newMoney) {
    this->numMoney = newMoney;
}
double Investor::getMoney() {
    return this->numMoney;
}