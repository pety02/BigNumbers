#include "Number.h"
#include "Calculator.h"

/// <summary>
/// Method that accepts as 
/// </summary>
/// <param name="fstNumber"> fstNumber (Number&), accepts as </param>
/// <param name="sndNumber"> sndNumber (Number&), accepts as </param>
/// <param name="operation"> operation (char&) and store in them 
/// user's input from the console. </param>
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

/// <summary>
/// Method that accepts as 
/// </summary>
/// <param name="fstNumber"> fstNumber (Number&), accepts as </param>
/// <param name="sndNumber"> sndNumber (Number&), accepts as </param>
/// <param name="operation"> operation (char&), 
/// make calculation and prints the result on the console. </param>
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
                std::string q = "", r = ""; 
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

// TEST in main() method.
int main()
{
    Number fstNumber;
    Number sndNumber;
    char operation;
    drawScene(fstNumber, sndNumber, operation);
    calculate(fstNumber.getNumber(), sndNumber.getNumber(), operation);
    return 0;
}