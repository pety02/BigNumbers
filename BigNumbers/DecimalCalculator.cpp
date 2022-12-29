#include "DecimalCalculator.h"

std::string DecimalCalculator::addDecimals(Number fstCollectable, Number sndCollectable)
{
	std::int64_t firstCollectable = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(fstCollectable.getNumber()));
	std::int64_t secondCollectable = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(sndCollectable.getNumber()));

	return DecimalNumbersParser::DecimalToString(firstCollectable + secondCollectable);
}

std::string DecimalCalculator::substractDecimnals(Number reducable, Number diminutive)
{
	std::int64_t _reducible = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(reducable.getNumber()));
	std::int64_t _diminutive = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(diminutive.getNumber()));

	std::string substraction = "";
	if (_reducible < _diminutive)
	{
		substraction += "-";
	}
	substraction += DecimalNumbersParser::DecimalToString(std::abs(_reducible - _diminutive));

	return substraction;
}

void DecimalCalculator::devideDecimals(Number divisible, Number divisor, std::int64_t& quotient, std::int64_t& reminder)
{
	std::int64_t _divisible = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(divisible.getNumber()));
	std::int64_t _divisor = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(divisor.getNumber()));

	quotient = _divisible / _divisor;
	reminder = _divisible % _divisor;

	return;
}

std::string DecimalCalculator::multiplyDecimals(Number fstMultiplier, Number sndMultiplier)
{
	std::int64_t firstMultiplier = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(fstMultiplier.getNumber()));
	std::int64_t secondMultiplier = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(sndMultiplier.getNumber()));

	return DecimalNumbersParser::DecimalToString(firstMultiplier * secondMultiplier);
}

std::string DecimalCalculator::sqrtDecimals(Number number)
{
	std::int64_t _number = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(number.getNumber()));
	std::int64_t updatableSum = 0;
	std::int64_t heightestPowerOfFour = 1 << 30;

	while (heightestPowerOfFour > _number)
	{
		heightestPowerOfFour >>= 2;

		while (heightestPowerOfFour != 0) {
			if (_number >= updatableSum + heightestPowerOfFour) {
				_number -= updatableSum + heightestPowerOfFour;
				updatableSum = (updatableSum >> 1) + heightestPowerOfFour;
			}
			else {
				updatableSum >>= 1;
			}
			heightestPowerOfFour >>= 2;
		}
	}

	return DecimalNumbersParser::DecimalToString(updatableSum);
}