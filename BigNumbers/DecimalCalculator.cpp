#include "DecimalCalculator.h"

std::string DecimalCalculator::addDecimals(Number n1, Number n2)
{
	char* number1 = Helpers::toCharArray(n1.getNumber());
	char* number2 = Helpers::toCharArray(n2.getNumber());

	long sum = DecimalNumbersParser::stringToNumber(number1) + DecimalNumbersParser::stringToNumber(number2);
	return DecimalNumbersParser::numberToString(sum);
}

std::string DecimalCalculator::substractDecimnals(Number n1, Number n2)
{
	char* number1 = Helpers::toCharArray(n1.getNumber());
	char* number2 = Helpers::toCharArray(n2.getNumber());

	long subs = std::abs(DecimalNumbersParser::stringToNumber(number1) - DecimalNumbersParser::stringToNumber(number2));
	std::string res = "";
	if (DecimalNumbersParser::stringToNumber(number1) < DecimalNumbersParser::stringToNumber(number2))
	{
		res += "-";
	}
	res += DecimalNumbersParser::numberToString(subs);

	return res;
}

void DecimalCalculator::devideDecimals(Number n1, Number n2, long& q, long& r)
{
	char* number1 = Helpers::toCharArray(n1.getNumber());
	char* number2 = Helpers::toCharArray(n2.getNumber());

	q = DecimalNumbersParser::stringToNumber(number1) / DecimalNumbersParser::stringToNumber(number2);
	r = DecimalNumbersParser::stringToNumber(number1) % DecimalNumbersParser::stringToNumber(number2);

	return;
}

std::string DecimalCalculator::multiplyDecimals(Number n1, Number n2)
{
	char* number1 = Helpers::toCharArray(n1.getNumber());
	char* number2 = Helpers::toCharArray(n2.getNumber());

	long pr = DecimalNumbersParser::stringToNumber(number1) * DecimalNumbersParser::stringToNumber(number2);
	std::string res = DecimalNumbersParser::numberToString(pr);

	return res;
}

std::string DecimalCalculator::sqrtDecimals(Number n1)
{
	char* n = Helpers::toCharArray(n1.getNumber());

	long x = DecimalNumbersParser::stringToNumber(n);
	long c = 0;
	long d = 1 << 30;

	while (d > x)
	{
		d >>= 2;

		while (d != 0) {
			if (x >= c + d) {
				x -= c + d;
				c = (c >> 1) + d;
			}
			else {
				c >>= 1;
			}
			d >>= 2;
		}
	}

	return DecimalNumbersParser::numberToString(c);
}