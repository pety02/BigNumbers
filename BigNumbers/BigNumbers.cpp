#include "Number.h"
#include "Calculator.h"
#include <iostream>

void drawScene(Number& fstNumber, Number& sndNumber, char& operation)
{
    std::cout << "Enter two numbers: \n firstNumber: ";
    std::istream* input = &std::cin;
    fstNumber.operator>>(*input);
    std::cout << "secondNumber: ";
    sndNumber.operator>>(*input);
    
    std::cout << std::endl << "OPERATIONS: \n\t+ add \n\t- substract \n\t* multiply \n\t" 
        << "/ devide \n\t~ sqrt \n\n Enter operation: ";
    std::cin >> operation;
    std::cout << std::endl;
}

void calculate(std::string fstNumber, std::string sndNumber, const char operation)
{
    std::cout << std::endl;
    switch (operation)
    {
        case '+':   
            {
                std::cout << "\"" << fstNumber << "\" " << operation << " "
                    << "\"" << sndNumber << "\" " << " = " << "\"" 
                    << Calculator::add(fstNumber, sndNumber) << "\" ";
                break;
            }
        case '-': 
            {
                std::cout << "\"" << fstNumber << "\" " << operation << " "
                    << "\"" << sndNumber << "\" " << " = " << "\"" 
                    << Calculator::substract(fstNumber, sndNumber) << "\" ";
                break;
            }
        case '*': 
            {
                std::cout << "\"" << fstNumber << "\" " << operation << " "
                    << "\"" << sndNumber << "\" " << " = " << "\"" 
                    << Calculator::multiply(fstNumber, sndNumber) << "\" ";
                break;
            }
        case '/': 
            {
                std::int64_t q = 0, r = 0; 
                Calculator::devide(fstNumber, sndNumber, q, r);
                std::cout << "\"" << fstNumber << "\" " << operation << " "
                    << "\"" << sndNumber << "\" " << " = " << "\"" << q << "\" (" << "\"" << r << "\")";
                break;
            }
        case '~': 
            {
                std::cout << operation << " \"" << fstNumber << "\"" << " = " 
                    << "\"" << Calculator::sqrt(fstNumber) << "\"\n" 
                    << operation << " \"" << sndNumber << "\"" << " = "
                    << "\"" << Calculator::sqrt(sndNumber) << "\"";
                break;
            }

        default: break;
    }
}

int main()
{
    Number fstNumber;
    Number sndNumber;
    char operation;
    drawScene(fstNumber, sndNumber, operation);
    calculate(fstNumber.getNumber(), sndNumber.getNumber(), operation);
    return 0;
}


/*

"12456789031415" + "98765432123456789" = "98777888912488204"
"12456789031415" * "98765432123456789" = "1230300151558439221348916026435"

*/