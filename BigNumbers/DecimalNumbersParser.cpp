#include "DecimalNumbersParser.h"

long DecimalNumbersParser::stringToNumber(const char* sPos, int base)
{
	std::string s = sPos;
	int power = s.length() - 1;
	long number = 0;
	while (*sPos != '\0')
	{
		number += (*(sPos++) - '0') * pow(base, power--);
	}

	return number;
}

std::string DecimalNumbersParser::numberToString(long n, int base)
{
	int size = Helpers::numberSize(n, base);
	char* s = new char[size + 1];

	int index = size;
	while (index != 0)
	{
		s[--index] = (n % base) + '0';
		n /= base;
	}
	s[size] = '\0';
	return s;
}