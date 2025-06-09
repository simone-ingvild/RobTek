#include "EAN.h"
#include <iostream>

int main() {
    // 1.1 Exercise: EAN Validation
    EAN e1("9780674062313");
    std::cout << "EAN Validation: " << e1.isValid() << std::endl;

    // 1.2 Exercise: ISBN to EAN Conversion
    EAN e2;
    std::string isbn = "ISBN 0-13-222220-5";
    std::string ean = e2.convertISBNtoEAN(isbn);
    std::cout << "ISBN to EAN: " << ean << std::endl;

    return 0;
}