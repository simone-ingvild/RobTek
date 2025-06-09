#include <iostream>
#include "stddev.h"

int main()
{
    std::vector<double> d{ 1.0, 2.0, 3.0 };
    std::vector<int>    i{ 2, 4, 4, 4, 5, 5, 7, 9 };
    std::vector<std::string> s{ "a", "b" };

    std::cout << "stdDev<double>: " << stdDev(d) << '\n';
    std::cout << "stdDev<int>:    " << stdDev(i) << '\n';
    std::cout << "stdDev<string>: " << stdDev(s) << '\n';
}
