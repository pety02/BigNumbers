#include "Calculator.h"

std::string Calculator::add(Number fstCollectable, Number sndCollectable)
{
	if (fstCollectable.getType() == NumberType::DECIMAL && sndCollectable.getType() == NumberType::DECIMAL)
	{
		return DecimalCalculator::addDecimals(fstCollectable, sndCollectable);
	}

	if (fstCollectable.getType() == NumberType::HEXA && sndCollectable.getType() == NumberType::HEXA)
	{
		return HexCalculator::addHexes(fstCollectable, sndCollectable);
	}
}

std::string Calculator::substract(Number reducible, Number reducive)
{
	if (reducible.getType() == NumberType::DECIMAL && reducive.getType() == NumberType::DECIMAL)
	{
		return DecimalCalculator::substractDecimnals(reducible, reducive);
	}

	if (reducible.getType() == NumberType::HEXA && reducive.getType() == NumberType::HEXA)
	{
		return HexCalculator::substractHexes(reducible, reducive);
	}
}

void Calculator::devide(Number divisible, Number divisor, std::string& quotient, std::string& reminder)
{
	if (divisible.getType() == NumberType::DECIMAL && divisor.getType() == NumberType::DECIMAL)
	{
		DecimalCalculator::devideDecimals(divisible, divisor, quotient, reminder);
	}

	if (divisible.getType() == NumberType::HEXA && divisor.getType() == NumberType::HEXA)
	{
		HexCalculator::devideHexes(divisible, divisor, quotient, reminder);
	}
}

std::string Calculator::multiply(Number fstMultiplier, Number sndMultiplier)
{
	if (fstMultiplier.getType() == NumberType::DECIMAL && sndMultiplier.getType() == NumberType::DECIMAL)
	{
		return DecimalCalculator::multiplyDecimals(fstMultiplier, sndMultiplier);
	}

	if (fstMultiplier.getType() == NumberType::HEXA && sndMultiplier.getType() == NumberType::HEXA)
	{
		return HexCalculator::multiplyHexes(fstMultiplier, sndMultiplier);
	}
}

std::string Calculator::sqrt(Number number)
{
	if (number.getType() == NumberType::DECIMAL)
	{
		return DecimalCalculator::sqrtDecimals(number);
	}

	if (number.getType() == NumberType::HEXA)
	{
		return HexCalculator::sqrtHexes(number);
	}
}