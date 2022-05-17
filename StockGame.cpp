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
#include "Investor.h"
using namespace std;

void printMarket(Stock ledger[], int size, Investor player);
Stock getStock(Stock ledger[], Investor player, int numStocks);
int getnumStock(Investor player, Stock stock);

int main()
{
    //Need to create ledger class that holds all the stocks (singly linked list of all the stocks
    //Should be able to return size for each element added so I don't have to pass it in
    const int numStocks = 4;
    Investor player("Player", 500.00);
    Stock stock1("ball", 5.34);
    Stock stock2("Tesla", 6.75);
    Stock stock3("Apple", 1.12);
    Stock stock4("Google", 500.23); //Maybe add a function that reads these in from a file and creates them and adds to ledger
    Stock ledger[numStocks] = { stock1, stock2, stock3, stock4 }; //Create a ledger item?
    //Figure out how to get ledger, maybe create another class, singly linked list with all stocks connected, hash map?

    while (true) {
        printMarket(ledger, numStocks, player);
        Stock foundStock = getStock(ledger, player, numStocks);
        int stockNum = getnumStock(player, foundStock);
        printf("%s purchased %d stocks of %s\n", player.getName().c_str(), stockNum, foundStock.getName().c_str());
    }
    cout << "----------- End of Market -------------\n ";
    return 0;
}

//Print the ledger for the stock market
void printMarket(Stock ledger[], int size, Investor player) {
    printf("----------- Stock Market ---------\n");
    for (int i = 0; i < size; i++) {
        printf("%s %.2lf \n", ledger[i].getName().c_str(), ledger[i].getPrice());
    }
    printf("---------------------------------- \n Player Balance : %.2lf \n", player.getMoney());
}

//Query for the stock the player would like to invest in
Stock getStock(Stock ledger[], Investor player, int numStocks) { //ideally would like to past ledger object so i dont have to pass number of stocks
    string stockName;
    Stock foundStock;
    bool found = false;
    printf("------------------------------------ \n Hello %s, What stock would you like to invest in? : ", player.getName().c_str());
    while (found != true) {
        cin >> stockName;
        for (int j = 0; j < numStocks; j++) {
            if (stockName.compare(ledger[j].getName()) == 0) {
                foundStock = ledger[j];
                printf("Stock Available! %s is selling shares for $%.2f \n", ledger[j].getName().c_str(), ledger[j].getPrice());
                found = true;
            }
        }
        if (found == false) {
            printf("That stock does not exist! Please choose one from the ledger.  \n Player : ");
        }
    }
    return foundStock;
}

//Query for the ammount of stocks the player would like ----BROKEN
double buyStock(Investor player, Stock stock) {
    int invAmount = 0;
    double wallet = player.getMoney();
    double price = 0;
    printf("How many shares? : ");
    cin >> invAmount;

    //Can player buy that many?
    price = invAmount * stock.getPrice();
    if (price <= player.getMoney()) {
        player.setMoney(wallet - price);
    }
    cout << player.getMoney();
    return player.getMoney();
}


