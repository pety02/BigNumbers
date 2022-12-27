#include "DecimalCalculator.h"

std::string DecimalCalculator::add(Number n1, Number n2) 
{
	if(n1.getType() == n2.getType()) {
	char* number1 = DecimalNumbersParser::toCharArray(n1.getNumber());
	char* number2 = DecimalNumbersParser::toCharArray(n2.getNumber());

	long sum = DecimalNumbersParser::stringToNumber(number1, 10) + DecimalNumbersParser::stringToNumber(number2, 10);
	std::string res = DecimalNumbersParser::numberToString(sum, 10);

	return res;}
}

std::string DecimalCalculator::substract(Number n1, Number n2)
{
	char* number1 = DecimalNumbersParser::toCharArray(n1.getNumber());
	char* number2 = DecimalNumbersParser::toCharArray(n2.getNumber());

	long subs = std::abs(DecimalNumbersParser::stringToNumber(number1, 10) - DecimalNumbersParser::stringToNumber(number2, 10));
	std::string res = "";
	if (DecimalNumbersParser::stringToNumber(number1, 10) < DecimalNumbersParser::stringToNumber(number2, 10))
	{
		res += '-';
	}
	res += DecimalNumbersParser::numberToString(subs, 10);

	return res;
}

void DecimalCalculator::devide(Number n1, Number n2, long& q, long& r)
{
	char* number1 = DecimalNumbersParser::toCharArray(n1.getNumber());
	char* number2 = DecimalNumbersParser::toCharArray(n2.getNumber());

	q = DecimalNumbersParser::stringToNumber(number1, 10) / DecimalNumbersParser::stringToNumber(number2, 10);
	r = DecimalNumbersParser::stringToNumber(number1, 10) % DecimalNumbersParser::stringToNumber(number2, 10);
}

std::string DecimalCalculator::multiply(Number n1, Number n2)
{
	char* number1 = DecimalNumbersParser::toCharArray(n1.getNumber());
	char* number2 = DecimalNumbersParser::toCharArray(n2.getNumber());

	long pr = DecimalNumbersParser::stringToNumber(number1, 10) * DecimalNumbersParser::stringToNumber(number2, 10);
	std::string res = DecimalNumbersParser::numberToString(pr, 10);

	return res;
}

std::string DecimalCalculator::sqrt(Number n1) 
{
	char* n = DecimalNumbersParser::toCharArray(n1.getNumber());

	long x = DecimalNumbersParser::stringToNumber(n, 10);
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

	return DecimalNumbersParser::numberToString(c, 10);
}