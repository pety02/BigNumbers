#include "BigNumber.h"

void drawScene(BigNumber& fstNumber, char& operation, BigNumber& sndNumber)
{
    std::istream* input = &std::cin;

    std::cout << "\tfirstNumber: ";
    fstNumber >> *input;

    std::cout << std::endl << "OPERATIONS: \n\t+ add \n\t- substract \n\t* multiply \n\t"
        << "/ devide \n\t% divide by module \n\t~ square root \n\nEnter operation: ";
    std::cin >> operation;
    std::cout << std::endl;

    if (operation != '~')
    {
        std::cout << "\tsecondNumber: ";
        sndNumber >> *input;
    } 
}

void printNumbersOperation(BigNumber fstNumber, BigNumber sndNumber, const char operation)
{
    std::cout << "\"" << fstNumber.getNumber() << "\" " << operation << " "
        << "\"" << sndNumber.getNumber() << "\"" << " = " << "\"";
}

void calculate(BigNumber fstNumber, BigNumber sndNumber, const char operation)
{
    std::cout << std::endl;
    try
    {
        switch (operation)
        {
            case '+':   
            {
                
                printNumbersOperation(fstNumber, sndNumber, operation);
                BigNumber sum = fstNumber + sndNumber;
                std::cout << sum.getNumber() << "\"" << std::endl;
                break;
            }
            case '-': 
            {
                printNumbersOperation(fstNumber, sndNumber, operation);
                BigNumber substraction = fstNumber - sndNumber;
                std::cout << substraction.getNumber() << "\"" << std::endl;
                break;
            }
            case '*': 
            {
               printNumbersOperation(fstNumber, sndNumber, operation);
               BigNumber product = fstNumber * sndNumber;
               std::cout << product.getNumber() << "\"" << std::endl;
               break;
            }
            case '/': 
            {
                printNumbersOperation(fstNumber, sndNumber, operation);
                BigNumber quotient = fstNumber / sndNumber;
                std::cout << quotient.getNumber() << "\"" << std::endl;
                break;
            }
            /*case '%':
            {
                printNumbersOperation(fstNumber, sndNumber, operation);
                BigNumber reminder;
                BigNumber quotient = fstNumber.mod(sndNumber, reminder);
                std::cout << quotient.getNumber() << "\" " << " (\"" << reminder.getNumber() << "\")" << std::endl;
                break;
            }
            case '~': 
            {
                std::cout << operation << "\"" << fstNumber.getNumber() << "\"" << " = " << "\"";
                BigNumber squareRoot = fstNumber.sqrt();
                std::cout << squareRoot.getNumber() << "\"" << std::endl;
                break;
            }*/

            default: throw "No such operation support!";
        }
    }
    catch (std::invalid_argument invalidArgumentEx)
    {
        std::cout << invalidArgumentEx.what() << std::endl;
    }
    catch (const char* messageEx)
    {
        std::cout << messageEx << std::endl;
    }
}

int main()
{
    BigNumber fstNumber;
    BigNumber sndNumber;
    char operation;
    drawScene(fstNumber, operation, sndNumber);
    calculate(fstNumber, sndNumber, operation);
    
    /*std::string n1("22");
    std::string n2("5");
    BigNumber num1 = BigNumber(n1);
    BigNumber num2 = BigNumber(n2);
    BigNumber sum = num1.operator/(num2);
    std::cout << sum.getNumber();*/
    
    return 0;
}