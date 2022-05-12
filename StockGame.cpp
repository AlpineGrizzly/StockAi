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

void printMarket(Stock ledger[], int size, Investor player) {
    printf("----------- Stock Market ---------\n");
    for (int i = 0; i < size; i++) {
        printf("%s %.2lf \n", ledger[i].getName().c_str(), ledger[i].getPrice());
    }
    printf("Player Balance : %.2lf \n", player.getMoney());
}

//Query for the stock the player would like to invest in
string getstockName(Stock ledger[], Investor player, int numStocks) { //ideally would like to past ledger object so i dont have to pass number of stocks
    string invStock;
    bool found = false;
    while (found) {
        printf("------------------------------------ \n Hello %s, What stock would you like to invest in? : ", player.getName().c_str());
        cin >> invStock;
        for (int j = 0; j < numStocks; j++) {
            if (invStock.compare(ledger[j].getName()) == 0) {
                printf("Transaction Successful!\n");
                found = true;
            }
        }
        printf("That stock does not exist!\n");
    }
    return invStock;
}

//Query for the ammount of stocks the player would like
int getnumStock(Investor player) {
    printf("How many shares? : ");
    int invAmount = 0;
    cin >> invAmount;
    //Can player buy that many?
    cout << "----------- End of Market -------------\n ";
    return invAmount;
}
int main()
{
    //Initialization of stocks and ledger
    //Need to create ledger class that holds all the stocks (singly linked list of all the stocks
    //Should be able to return size for each element added so I don't have to pass it in
    const int numStocks = 4; 
    Investor player("Player", 500.00);
    Stock stock1("ball", 5.34);
    Stock stock2("Tesla", 6.75);
    Stock stock3("Apple", 1.12);
    Stock stock4("Google", 500.23); //Maybe add a function that reads these in from a file and creates them and adds to ledger
    Stock ledger[numStocks] = {stock1, stock2, stock3, stock4}; //Create a ledger item?
    //Figure out how to get ledger, maybe create another class, singly linked list with all stocks connected, hash map?

    printMarket(ledger, numStocks, player);
    string stockName = getstockName(ledger, player, numStocks);
    int stockNum = getnumStock(player);
    printf("%s purchased %d stocks of %s\n", player.getName().c_str(), stockNum, stockName.c_str());
    return 0;
}

