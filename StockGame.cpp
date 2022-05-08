// StockGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

/*Ideas to consider
 * Want to develop ai's that will learn as you play
 * Farther you go the faster and better you will have to be at choosing to invest
 * Random world invents and news will affect how certain investors invest 
 */

//Stock class
class Stock {
    private:
        string name;
        double price;
    public: 
        Stock(string name, double price) {
            this->name = name;
            this->price = price;
        }

        void setPrice(double newPrice) {
            if (this->price > 0) {
                this->price = newPrice;
            }
            else {
                printf("Not valid price\n");
            }
        }

        double getPrice() {
            return this->price;
        }
};

//Investor class
class Investor {
    private:
        string name;
        double numMoney;
        //Stock ownedStocks;
    public: 
        Investor(string name, double numMoney) {
            this->name = name;
            this->numMoney = numMoney;
            //ownedStocks = new Stock[3]; Need to find way to store stocks without breaking memory
        }
};



int main()
{
    printf("----------- Stock Market ---------\n");
    const int numStocks = 4; 
    int playerBal = 500;
    string stockNames[numStocks] = {"Ball", "Tesla", "Apple", "Google"};
    float stockPrices[numStocks] = {5.34, 6.75, 1.12, 500.23}; 

    //Make objects
    for (int i = 0; i < numStocks; i++) {
        printf("%s : %.2lf \n", stockNames[i].c_str(), stockPrices[i]);
    }
    string invStock = "";
    printf("Player Balance : %d \n", playerBal);
    while (true) {
        printf("------------------------------------ \n What stock would you like to invest in? : ");
        cin >> invStock;
        for (int j = 0; j < numStocks; j++) {
            if (invStock.compare(stockNames[j]) == 0) {
                break;
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
