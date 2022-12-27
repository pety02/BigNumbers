#include "Calculator.h"

std::string Calculator::add(Number n1, Number n2)
{
	if (n1.getType() == NumberType::DECIMAL && n2.getType() == NumberType::DECIMAL)
	{
		char* number1 = Helpers::toCharArray(n1.getNumber());
		char* number2 = Helpers::toCharArray(n2.getNumber());

		long sum = DecimalNumbersParser::stringToNumber(number1) + DecimalNumbersParser::stringToNumber(number2);
		return DecimalNumbersParser::numberToString(sum);
	}

	if (n1.getType() == NumberType::HEXA && n2.getType() == NumberType::HEXA)
	{
		char* number1 = Helpers::toCharArray(n1.getNumber());
		char* number2 = Helpers::toCharArray(n2.getNumber());

		long sum = HexaNumbersParser::hexaToNumber(number1) + HexaNumbersParser::hexaToNumber(number2);
		return HexaNumbersParser::numberToHexa(sum);
	}
}

std::string Calculator::substract(Number n1, Number n2)
{
	if (n1.getType() == NumberType::DECIMAL && n2.getType() == NumberType::DECIMAL)
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

	if (n1.getType() == NumberType::HEXA && n2.getType() == NumberType::HEXA)
	{
		char* number1 = Helpers::toCharArray(n1.getNumber());
		char* number2 = Helpers::toCharArray(n2.getNumber());

		long subs = std::abs(HexaNumbersParser::hexaToNumber(number1) - HexaNumbersParser::hexaToNumber(number2));
		std::string res = "";
		if (HexaNumbersParser::hexaToNumber(number1) < HexaNumbersParser::hexaToNumber(number2))
		{
			res += "-";
		}
		res += HexaNumbersParser::numberToHexa(subs);

		return res;
	}
}

void Calculator::devide(Number n1, Number n2, long& q, long& r)
{
	if (n1.getType() == NumberType::DECIMAL && n2.getType() == NumberType::DECIMAL)
	{
		char* number1 = Helpers::toCharArray(n1.getNumber());
		char* number2 = Helpers::toCharArray(n2.getNumber());

		q = DecimalNumbersParser::stringToNumber(number1) / DecimalNumbersParser::stringToNumber(number2);
		r = DecimalNumbersParser::stringToNumber(number1) % DecimalNumbersParser::stringToNumber(number2);

		return;
	}

	if (n1.getType() == NumberType::HEXA && n2.getType() == NumberType::HEXA)
	{
		char* number1 = Helpers::toCharArray(n1.getNumber());
		char* number2 = Helpers::toCharArray(n2.getNumber());

		q = HexaNumbersParser::hexaToNumber(number1) / HexaNumbersParser::hexaToNumber(number2);
		r = HexaNumbersParser::hexaToNumber(number1) % HexaNumbersParser::hexaToNumber(number2);

		return;
	}
}

std::string Calculator::multiply(Number n1, Number n2)
{
	if (n1.getType() == NumberType::DECIMAL && n2.getType() == NumberType::DECIMAL)
	{
		char* number1 = Helpers::toCharArray(n1.getNumber());
		char* number2 = Helpers::toCharArray(n2.getNumber());

		long pr = DecimalNumbersParser::stringToNumber(number1) * DecimalNumbersParser::stringToNumber(number2);
		std::string res = DecimalNumbersParser::numberToString(pr);

		return res;
	}

	if (n1.getType() == NumberType::HEXA && n2.getType() == NumberType::HEXA)
	{
		char* number1 = Helpers::toCharArray(n1.getNumber());
		char* number2 = Helpers::toCharArray(n2.getNumber());

		long pr = HexaNumbersParser::hexaToNumber(number1) * HexaNumbersParser::hexaToNumber(number2);
		std::string res = HexaNumbersParser::numberToHexa(pr);

		return res;
	}
}

std::string Calculator::sqrt(Number n1)
{
	if (n1.getType() == NumberType::DECIMAL)
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

	if (n1.getType() == NumberType::HEXA)
	{
		char* n = Helpers::toCharArray(n1.getNumber());

		long x = HexaNumbersParser::hexaToNumber(n);
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

		return HexaNumbersParser::numberToHexa(c);
	}
}