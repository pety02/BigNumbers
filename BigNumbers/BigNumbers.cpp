#include "Number.h"
#include "DecimalCalculator.h"

int main()
{
    std::istream* stream = &std::cin;
    std::ostream* stream2 = &std::cout;

    Number n1 = Number();
    n1.operator>>(*stream);

    Number n2 = Number();
    n2.operator>>(*stream);
    

    std::cout << std::endl << "NUMBERS: " << std::endl;
    n1.operator<<(*stream2); 
    n2.operator<<(*stream2);
    std::cout << std::endl;

    std::cout << DecimalCalculator::add(n1, n2);
    return 0;
}