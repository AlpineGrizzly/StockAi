// StockGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Ideas to consider
 * Want to develop ai's that will learn as you play
 * Farther you go the faster and better you will have to be at choosing to invest
 * Random world invents and news will affect how certain investors invest
 */

#include <iostream>
#include <string>
#include "stock.h"
using namespace std;

int main()
{
    const int numStocks = 4; 
    int playerBal = 500; 
    Stock stock1("ball", 5.34);
    Stock stock2("Tesla", 6.75);
    Stock stock3("Apple", 1.12);
    Stock stock4("Google", 500.23);
    
    Stock Ledger[4] = { stock1, stock2, stock3, stock4};
    //Figure out how to get ledger, maybe create another class, singly linked list with all stocks connected, hash map?


    printMarket(stockNames, stockPrices, playerBal);
    string invStock;
    bool found = false;
    while (found) {
        printf("------------------------------------ \n What stock would you like to invest in? : ");
        cin >> invStock;
        for (int j = 0; j < numStocks; j++) {
            if (invStock.compare(stockNames[j]) == 0) {
                printf("Transaction Successful!\n");
                found = true;
            }
        }
        printf("That stock does not exist!: %s is not %s\n");
    }
    printf("How many shares? : ");
    int invAmount = 0;
    cin >> invAmount;
    //Can player buy that many?
    cout << "----------- End of Market -------------\n ";
    
    return 0;
}

void printMarket(string stockNames[], float stockPrices[], double playerBal) {
    printf("----------- Stock Market ---------\n");
    for (int i = 0; i < stockNames->size(); i++) {
        printf("%s : %.2lf \n", stockNames[i].c_str(), stockPrices[i]);
    }
    printf("Player Balance : %d \n", playerBal);
}

