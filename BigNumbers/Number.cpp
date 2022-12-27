#include "Number.h"

void Number::operator>>(std::istream& in)
{
	if (in.good()) 
	{
		in >> this->number;
	}
}

void Number::operator <<(std::ostream& os)
{
	if (os.good()) 
	{
		os << this->number << ", ";
	}
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

	long subs = std::abs(NumbersParser::stringToNumber(number1, 10) - NumbersParser::stringToNumber(number2, 10));
	std::string res = "";
	if(NumbersParser::stringToNumber(number1, 10) < NumbersParser::stringToNumber(number2, 10))
	{
		res += '-';
	}
	res += NumbersParser::numberToString(subs, 10);

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

std::string Number::sqrtDecimals() 
{
	char* n = NumbersParser::toCharArray(this->number);

	long x = NumbersParser::stringToNumber(n, 10);
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
	
	return NumbersParser::numberToString(c, 10);
}