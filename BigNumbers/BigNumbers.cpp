#include "Number.h"
#include "Calculator.h"

int main()
{
    std::istream* stream = &std::cin;
    std::ostream* stream2 = &std::cout;

    Number n1 = Number("AB");
    //n1.operator>>(*stream);

    Number n2 = Number("BC");
    //n2.operator>>(*stream);
    

    //std::cout << std::endl << "NUMBERS: " << std::endl;
    //n1.operator<<(*stream2); 
    //n2.operator<<(*stream2);
    //std::cout << std::endl;

    //Calculator::add(n1, n2);

    //long q = 0, r = 0;
    std::cout << Calculator::multiply(n1, n2);
    //std::cout << q << std::endl;
    //std::cout << r << std::endl;
    return 0;
}