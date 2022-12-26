#include "Number.h"

int main()
{
    Number n1 = Number();
    n1.operator>>("29");

    Number n2 = Number();
    n2.operator>>("4");

    std::cout << n1.addDecimals(n2) << std::endl;
    std::cout << n1.substractDecimals(n2) << std::endl;
    std::cout << n1.multiplyDecimals(n2) << std::endl;
    long q = 0, r = 0;
    n1.devideDecimals(n2, q, r);
    std::cout << "n1 / n2 = " << q << std::endl;
    std::cout << "n1 % n2 = " << r << std::endl;
    return 0;
}