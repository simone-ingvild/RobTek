#include <iostream>
#include "valuable.h"
#include "exchangeRate.h"
#include "stackOfMoney.h"
#include "allValuables.h"

int main(int argc, char** argv){
    Valuable mona("Monika Lisa", 30000);
    Valuable venus("Venus de Milano", 20000);
    Valuable scream("The Screamer", 23000);

    ExchangeRate dollar("USD", 631);
    ExchangeRate euro("EUR", 768);

    StackOfMoney whistler("Payment Whistler’s Father", 5000, dollar);
    StackOfMoney guernica("Payment Guernicalala", 3000, euro);
    StackOfMoney mom("From mom", 1000, euro);

    AllValuables all;
    all.add(mona);
    all.add(venus);
    all.add(scream);
    all.add(whistler);
    all.add(guernica);
    all.add(mom);

    std::cout << all.getValue() << std::endl; // 135270
    euro.setExchangeRate(759);
    std::cout << all.getValue() << std::endl; // 134910
    all.printAll();
}
