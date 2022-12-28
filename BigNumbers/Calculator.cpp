#include "Calculator.h"

std::string Calculator::add(Number n1, Number n2)
{
	if (n1.getType() == NumberType::DECIMAL && n2.getType() == NumberType::DECIMAL)
	{
		return DecimalCalculator::addDecimals(n1, n2);
	}

	if (n1.getType() == NumberType::HEXA && n2.getType() == NumberType::HEXA)
	{
		return HexaCalculator::addHexas(n1, n2);
	}
}

std::string Calculator::substract(Number n1, Number n2)
{
	if (n1.getType() == NumberType::DECIMAL && n2.getType() == NumberType::DECIMAL)
	{
		return DecimalCalculator::substractDecimnals(n1, n2);
	}

	if (n1.getType() == NumberType::HEXA && n2.getType() == NumberType::HEXA)
	{
		return HexaCalculator::substractHexas(n1, n2);
	}
}

void Calculator::devide(Number n1, Number n2, long& q, long& r)
{
	if (n1.getType() == NumberType::DECIMAL && n2.getType() == NumberType::DECIMAL)
	{
		DecimalCalculator::devideDecimals(n1, n2, q, r);
	}

	if (n1.getType() == NumberType::HEXA && n2.getType() == NumberType::HEXA)
	{
		std::string q1 = HexaNumbersParser::numberToHex(q);
		std::string r1 = HexaNumbersParser::numberToHex(r);

		HexaCalculator::devideHexas(n1, n2, q1, r1);
	}
}

std::string Calculator::multiply(Number n1, Number n2)
{
	if (n1.getType() == NumberType::DECIMAL && n2.getType() == NumberType::DECIMAL)
	{
		return DecimalCalculator::multiplyDecimals(n1, n2);
	}

	if (n1.getType() == NumberType::HEXA && n2.getType() == NumberType::HEXA)
	{
		return HexaCalculator::multiplyHexas(n1, n2);
	}
}

std::string Calculator::sqrt(Number n1)
{
	if (n1.getType() == NumberType::DECIMAL)
	{
		return DecimalCalculator::sqrtDecimals(n1);
	}

	if (n1.getType() == NumberType::HEXA)
	{
		return HexaCalculator::sqrtHexas(n1);
	}
}