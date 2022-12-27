#include "Number.h"

int main()
{
    std::istream* stream = &std::cin;
    std::ostream* stream2 = &std::cout;

    Number n1 = Number();
    n1.operator>>(*stream);

    Number n2 = Number();
    n2.operator>>(*stream);
    

    std::cout << std::endl << "NUMBERS: ";
    n1.operator<<(*stream2); 
    n2.operator<<(*stream2);
    std::cout << std::endl;
    std::cout << n1.addDecimals(n2) << std::endl;
    std::cout << n1.substractDecimals(n2) << std::endl;
    std::cout << n1.multiplyDecimals(n2) << std::endl;
    long q = 0, r = 0;
    n1.devideDecimals(n2, q, r);
    std::cout << "n1 / n2 = " << q << std::endl;
    std::cout << "n1 % n2 = " << r << std::endl;
    std::cout << n2.sqrtDecimals() << std::endl;
    return 0;
}