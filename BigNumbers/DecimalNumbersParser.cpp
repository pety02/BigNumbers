/*#include "DecimalNumbersParser.h"
#include <cstring>

std::int64_t DecimalNumbersParser::stringToDecimal(const char* numberAsCharArray)
{
	std::string numberAsString = numberAsCharArray;
	int power = numberAsString.length() - 1;
	std::int64_t number = 0;
	while (*numberAsCharArray != '\0')
	{
		number += (*(numberAsCharArray++) - '0') * pow(DecimalNumbersParser::BASE, power--);
	}

	return number;
}

std::string DecimalNumbersParser::decimalToString(std::int64_t number)
{
	int numberSize = Helpers::numberSize(number, DecimalNumbersParser::BASE);
	char* numberAsString = new char[numberSize + 1];

	int index = numberSize;
	while (index != 0)
	{
		numberAsString[--index] = (number % DecimalNumbersParser::BASE) + '0'; 
		number /= DecimalNumbersParser::BASE;
	}
	numberAsString[numberSize] = '\0';

	return numberAsString;
}*/