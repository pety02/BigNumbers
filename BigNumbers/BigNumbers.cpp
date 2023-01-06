#include "Number.h"

void drawScene(Number& fstNumber, char& operation, Number& sndNumber)
{
    std::istream* input = &std::cin;

    std::cout << "\tfirstNumber: ";
    fstNumber >> *input;

    std::cout << std::endl << "OPERATIONS: \n\t+ add \n\t- substract \n\t* multiply \n\t"
        << "/ devide \n\t% divide by module \n\t~ square root \n\n Enter operation: ";
    std::cin >> operation;
    std::cout << std::endl;

    if (operation != '~')
    {
        std::cout << "\tsecondNumber: ";
        sndNumber >> *input;
    } 
}

void printNumbersOperation(Number fstNumber, Number sndNumber, const char operation)
{
    std::cout << "\"" << fstNumber.getNumber() << "\" " << operation << " "
        << "\"" << sndNumber.getNumber() << "\"" << " = " << "\"";
}

void calculate(Number fstNumber, Number sndNumber, const char operation)
{
    std::cout << std::endl;
    try
    {
        switch (operation)
        {
            case '+':   
            {
                
                printNumbersOperation(fstNumber, sndNumber, operation);
                Number sum = fstNumber + sndNumber;
                std::cout << sum.getNumber() << "\" ";
                break;
            }
            case '-': 
            {
                printNumbersOperation(fstNumber, sndNumber, operation);
                Number substraction = fstNumber - sndNumber;
                std::cout << substraction.getNumber() << "\" ";
                break;
            }
            case '*': 
            {
               printNumbersOperation(fstNumber, sndNumber, operation);
               Number product = fstNumber * sndNumber;
               std::cout << product.getNumber() << "\" ";
               break;
            }
            case '/': 
            {
                printNumbersOperation(fstNumber, sndNumber, operation);
                Number quotient = fstNumber / sndNumber;
                std::cout << quotient.getNumber() << "\" ";
                break;
            }
            case '%':
            {
                printNumbersOperation(fstNumber, sndNumber, operation);
                Number reminder;
                Number quotient = fstNumber.mod(sndNumber, reminder);
                std::cout << quotient.getNumber() << "\" " << " (\"" << reminder.getNumber() << "\")";
                break;
            }
            case '~': 
            {
                std::cout << operation << "\"" << fstNumber.getNumber() << "\"" << " = " << "\"";
                Number squareRoot = fstNumber.sqrt();
                std::cout << squareRoot.getNumber() << "\"";
                break;
            }

            default: break;
        }
    }
    catch (std::invalid_argument ex)
    {
        std::cout << ex.what();
    }
}

int main()
{
    Number fstNumber;
    Number sndNumber;
    char operation;
    drawScene(fstNumber, operation, sndNumber);
    calculate(fstNumber, sndNumber, operation);
    return 0;
}