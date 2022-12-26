#include "Number.h"

void Number::operator>>(const std::string number)
{
	this->number = number;
}

void Number::printDecimal()
{
	std::cout << number;
}

std::string Number::addDecimals(const Number num)
{
	char* number1 = NumbersParser::toCharArray(this->number);
	char* number2 = NumbersParser::toCharArray(num.number);
	
	long sum = NumbersParser::stringToNumber(number1, 10) + NumbersParser::stringToNumber(number2, 10);
	std::string res = NumbersParser::numberToString(sum, 10);

	return res;
}

std::string Number::substractDecimals(const Number num)
{
	char* number1 = NumbersParser::toCharArray(this->number);
	char* number2 = NumbersParser::toCharArray(num.number);

	long subs = NumbersParser::stringToNumber(number1, 10) - NumbersParser::stringToNumber(number2, 10);
	std::string res = NumbersParser::numberToString(subs, 10);

	return res;
}

void Number::devideDecimals(const Number num, long& q, long& r)
{
	char* number1 = NumbersParser::toCharArray(this->number);
	char* number2 = NumbersParser::toCharArray(num.number);

	q = NumbersParser::stringToNumber(number1, 10) / NumbersParser::stringToNumber(number2, 10);
	r = NumbersParser::stringToNumber(number1, 10) % NumbersParser::stringToNumber(number2, 10);
}

std::string Number::multiplyDecimals(const Number num)
{
	char* number1 = NumbersParser::toCharArray(this->number);
	char* number2 = NumbersParser::toCharArray(num.number);

	long pr = NumbersParser::stringToNumber(number1, 10) * NumbersParser::stringToNumber(number2, 10);
	std::string res = NumbersParser::numberToString(pr, 10);

	return res;
}