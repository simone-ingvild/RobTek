#include <iostream>
#include <string>
#include "Country.h"
#include "CoinCollection.h"
#include "Coin.h"
using namespace std;
 
int main() { 
    CoinCollection coinC; 
    Country d( "Denmark");    
    Coin c1(d, 12, 1953, "Frederik 9.", 2, 23); 
    coinC.addCoin(c1); 
    Coin c2(d, 12, 1945, "Christian 10.", 1, 38); 
    coinC.addCoin(c2); 
    Coin c3(d, 12, 1965, "Frederik 9.", 5, 17); 
    coinC.addCoin(c3); 
    Coin c4(d, 12, 1988, "Margrethe 2.", 10, 15); 
    coinC.addCoin(c4); 
    Coin c5(d, 12, 1999, "Margrethe 2.", 20, 24); 
    coinC.addCoin(c5); 
    Coin c6(d, 12, 1948, "Frederik 9.", 1, 56); 
    coinC.addCoin(c6); 
    c3.changeValue(-5); 
    cout <<   "Total value: " <<   coinC.getTotalValue() <<   endl; // 168 
    cout <<   "Decade value 1940's: " <<   coinC.getTotalValueDecade(194) << endl;// 94 
}