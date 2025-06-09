#include "EMA.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    EMA e1("sps@mmmi.sdu.dk");
    cout << e1.getEMA() << " " << e1.isValid() << endl; //false = 0 in terminal
    EMA e2("Bølle Bob");
    cout << e2.getEMA() << " " << e2.isValid() << endl; //false = 0 in terminal
    EMA e3("BoelleBob@sdu.dk");
    cout << e3.getEMA() << " " << e3.isValid() << endl; //true = 1 in terminal
    EMA e4("polle@m.com");
    cout << e4.getEMA() << " " << e4.isValid() << endl; //false = 0 in terminal
    EMA e5("polle@dm.com");
    cout << e5.getEMA() << " " << e5.isValid() << endl; //true = 1 in terminal
    EMA e6("pallesen@gm<ail.com");
    cout << e6.getEMA() << " " << e6.isValid() << endl; //false = 0 in terminal
    EMA e7("pallesen@gmail.com");
    cout << e7.getEMA() << " " << e7.isValid() << endl; //true = 1 in terminal
    EMA e8("peter@piil@gmail.com");
    cout << e8.getEMA() << " " << e8.isValid() << endl; //false = 0 in terminal
    EMA e9("peterpiil@gmail.com");
    cout << e9.getEMA() << " " << e9.isValid() << endl; //true = 1 in terminal
    return 0;
}