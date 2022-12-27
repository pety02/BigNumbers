#include "Number.h"
#include "Calculator.h"
#include <fstream>

void drawScene(Number& firstNumber, Number& secondNumber, char& operation)
{
    std::cout << "Enter two numbers: \n firstNumber: ";
    std::istream* in = &std::cin;
    firstNumber.operator>>(*in);
    std::cout << "secondNumber: ";
    secondNumber.operator>>(*in);
    
    std::cout << std::endl << "OPERATIONS: \n\t+ add \n\t- substract \n\t* multiply \n\t" 
        << "/ devide \n\t~ sqrt \n\n Enter operation: ";
    std::cin >> operation;
    std::cout << std::endl;
}

void calculate(std::string firstNumber, std::string secondNumber, const char operation)
{
    std::cout << std::endl;
    switch (operation)
    {
        case '+':   
            {
                std::cout << "\"" << firstNumber << "\" " << operation << " "
                    << "\"" << secondNumber << "\" " << " = " << "\"" 
                    << Calculator::add(firstNumber, secondNumber) << "\" ";
                break;
            }
        case '-': 
            {
                std::cout << "\"" << firstNumber << "\" " << operation << " "
                    << "\"" << secondNumber << "\" " << " = " << "\"" 
                    << Calculator::substract(firstNumber, secondNumber) << "\" ";
                break;
            }
        case '*': 
            {
                std::cout << "\"" << firstNumber << "\" " << operation << " "
                    << "\"" << secondNumber << "\" " << " = " << "\"" 
                    << Calculator::multiply(firstNumber, secondNumber) << "\" ";
                break;
            }
        case '/': 
            {
                long q = 0, r = 0; 
                Calculator::devide(firstNumber, secondNumber, q, r);
                std::cout << "\"" << firstNumber << "\" " << operation << " "
                    << "\"" << secondNumber << "\" " << " = " << "\"" << q << "\" (" << "\"" << r << "\")";
                break;
            }
        case '~': 
            {
                std::cout << operation << " \"" << firstNumber << "\"" << " = " 
                    << "\"" << Calculator::sqrt(firstNumber) << "\"\n" 
                    << operation << " \"" << secondNumber << "\"" << " = "
                    << "\"" << Calculator::sqrt(secondNumber) << "\"";
                break;
            }

        default: break;
    }
}

int main()
{
    Number n1 = Number();
    Number n2 = Number();
    char op;
    drawScene(n1, n2, op);
    calculate(n1.getNumber(), n2.getNumber(), op);
    return 0;
}