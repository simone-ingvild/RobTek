#include <iostream>
#include "Temperatures.h"

int main()
{
    Temperatures t1{ {298.15, 300.00, 296.77}, 'K' };
    Temperatures t2{ {21.0, 23.5, 19.6}, 'C' };

    t1.add(299.00);

    std::cout << "t1 mean (K): "   << t1.mean()  << '\n';
    std::cout << "t1 range (K): "  << t1.range() << '\n';

    Temperatures t1C = t1.toDegC();
    std::cout << "t1 mean converted to C: " << t1C.mean() << '\n';

    std::cout << "t2 mean (C): "   << t2.mean()  << '\n';
}
