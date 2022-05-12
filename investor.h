#pragma once
#include <iostream>
#include <string>

using namespace std;

class Investor
{
    private:
        string name;
        double numMoney;
        //Stock ownedStocks;
    public:
        Investor(string name, double numMoney);
        void setName(string newName);
        string getName();
        void setMoney(double newMoney);
        double getMoney();
};

