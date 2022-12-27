#include "Calculator.h"

std::string Calculator::add(Number n1, Number n2)
{
	if (n1.getType() == NumberType::DECIMAL && n2.getType() == NumberType::DECIMAL)
	{
		char* number1 = Helpers::toCharArray(n1.getNumber());
		char* number2 = Helpers::toCharArray(n2.getNumber());

		long sum = DecimalNumbersParser::stringToNumber(number1, 10) + DecimalNumbersParser::stringToNumber(number2, 10);
		return DecimalNumbersParser::numberToString(sum, 10);
	}

	if (n1.getType() == NumberType::HEXA && n2.getType() == NumberType::HEXA)
	{
		char* number1 = Helpers::toCharArray(n1.getNumber());
		char* number2 = Helpers::toCharArray(n2.getNumber());

		long sum = HexaNumbersParser::hexaToNumber(number1, 16) + HexaNumbersParser::hexaToNumber(number2, 16);
		return HexaNumbersParser::numberToHexa(sum, 16);
	}
}

std::string Calculator::substract(Number n1, Number n2)
{
	if (n1.getType() == NumberType::DECIMAL && n2.getType() == NumberType::DECIMAL)
	{
		char* number1 = Helpers::toCharArray(n1.getNumber());
		char* number2 = Helpers::toCharArray(n2.getNumber());

		long subs = std::abs(DecimalNumbersParser::stringToNumber(number1, 10) - DecimalNumbersParser::stringToNumber(number2, 10));
		std::string res = "";
		if (DecimalNumbersParser::stringToNumber(number1, 10) < DecimalNumbersParser::stringToNumber(number2, 10))
		{
			res += "-";
		}
		res += DecimalNumbersParser::numberToString(subs, 10);

		return res;
	}

	if (n1.getType() == NumberType::HEXA && n2.getType() == NumberType::HEXA)
	{
		char* number1 = Helpers::toCharArray(n1.getNumber());
		char* number2 = Helpers::toCharArray(n2.getNumber());

		long subs = std::abs(HexaNumbersParser::hexaToNumber(number1, 16) - HexaNumbersParser::hexaToNumber(number2, 16));
		std::string res = "";
		if (HexaNumbersParser::hexaToNumber(number1, 16) < HexaNumbersParser::hexaToNumber(number2, 16))
		{
			res += "-";
		}
		res += HexaNumbersParser::numberToHexa(subs, 16);

		return res;
	}
}

void Calculator::devide(Number n1, Number n2, long& q, long& r)
{
	if (n1.getType() == NumberType::DECIMAL && n2.getType() == NumberType::DECIMAL)
	{
		char* number1 = Helpers::toCharArray(n1.getNumber());
		char* number2 = Helpers::toCharArray(n2.getNumber());

		q = DecimalNumbersParser::stringToNumber(number1, 10) / DecimalNumbersParser::stringToNumber(number2, 10);
		r = DecimalNumbersParser::stringToNumber(number1, 10) % DecimalNumbersParser::stringToNumber(number2, 10);

		return;
	}

	if (n1.getType() == NumberType::HEXA && n2.getType() == NumberType::HEXA)
	{
		char* number1 = Helpers::toCharArray(n1.getNumber());
		char* number2 = Helpers::toCharArray(n2.getNumber());

		q = HexaNumbersParser::hexaToNumber(number1, 16) / HexaNumbersParser::hexaToNumber(number2, 16);
		r = HexaNumbersParser::hexaToNumber(number1, 16) % HexaNumbersParser::hexaToNumber(number2, 16);

		return;
	}
}

std::string Calculator::multiply(Number n1, Number n2)
{
	if (n1.getType() == NumberType::DECIMAL && n2.getType() == NumberType::DECIMAL)
	{
		char* number1 = Helpers::toCharArray(n1.getNumber());
		char* number2 = Helpers::toCharArray(n2.getNumber());

		long pr = DecimalNumbersParser::stringToNumber(number1, 10) * DecimalNumbersParser::stringToNumber(number2, 10);
		std::string res = DecimalNumbersParser::numberToString(pr, 10);

		return res;
	}

	if (n1.getType() == NumberType::HEXA && n2.getType() == NumberType::HEXA)
	{
		char* number1 = Helpers::toCharArray(n1.getNumber());
		char* number2 = Helpers::toCharArray(n2.getNumber());

		long pr = HexaNumbersParser::hexaToNumber(number1, 16) * HexaNumbersParser::hexaToNumber(number2, 16);
		std::string res = HexaNumbersParser::numberToHexa(pr, 16);

		return res;
	}
}

std::string Calculator::sqrt(Number n1)
{
	if (n1.getType() == NumberType::DECIMAL)
	{
		char* n = Helpers::toCharArray(n1.getNumber());

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

	if (n1.getType() == NumberType::HEXA)
	{
		char* n = Helpers::toCharArray(n1.getNumber());

		long x = HexaNumbersParser::hexaToNumber(n, 16);
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

		return HexaNumbersParser::numberToHexa(c, 16);
	}
}