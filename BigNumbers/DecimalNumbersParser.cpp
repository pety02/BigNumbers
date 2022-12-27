#include "DecimalNumbersParser.h"

long DecimalNumbersParser::stringToNumber(const char* sPos)
{
	std::string s = sPos;
	int power = s.length() - 1;
	long number = 0;
	while (*sPos != '\0')
	{
		number += (*(sPos++) - '0') * pow(DecimalNumbersParser::BASE, power--);
	}

	return number;
}

std::string DecimalNumbersParser::numberToString(long n)
{
	int size = Helpers::numberSize(n, DecimalNumbersParser::BASE);
	char* s = new char[size + 1];

	int index = size;
	while (index != 0)
	{
		s[--index] = (n % DecimalNumbersParser::BASE) + '0';
		n /= DecimalNumbersParser::BASE;
	}
	s[size] = '\0';
	return s;
}