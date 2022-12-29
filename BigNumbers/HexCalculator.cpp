#include "HexCalculator.h"

std::string HexCalculator::addHexes(Number fstCollectable, Number sndCollectable)
{
	std::int64_t firstCollectable = HexNumbersParser::hexToDecimal(Helpers::toCharArray(fstCollectable.getNumber()));
	std::int64_t secondCollectable = HexNumbersParser::hexToDecimal(Helpers::toCharArray(sndCollectable.getNumber()));
	
	return HexNumbersParser::decimalToHex(firstCollectable + secondCollectable);
}

std::string HexCalculator::substractHexes(Number reducible, Number diminutive)
{
	std::int64_t _reducible = HexNumbersParser::hexToDecimal(Helpers::toCharArray(reducible.getNumber()));
	std::int64_t _diminutive = HexNumbersParser::hexToDecimal(Helpers::toCharArray(diminutive.getNumber()));

	std::string substraction = "";
	if (_reducible < _diminutive)
	{
		substraction += "-";
	}
	substraction += HexNumbersParser::decimalToHex(std::abs(_reducible - _diminutive));

	return substraction;
}

void HexCalculator::devideHexes(Number deivisible, Number divisor, std::string& quotient, std::string& reminder)
{
	std::int64_t _divisible = HexNumbersParser::hexToDecimal(Helpers::toCharArray(deivisible.getNumber()));
	std::int64_t _divisor = HexNumbersParser::hexToDecimal(Helpers::toCharArray(divisor.getNumber()));

	quotient = HexNumbersParser::decimalToHex(_divisible / _divisor);
	reminder = (_divisible % _divisor != 0) ? HexNumbersParser::decimalToHex(_divisible % _divisor) : "0";

	return;
}

std::string HexCalculator::multiplyHexes(Number fstMultiplier, Number sndMultiplier)
{
	std::int64_t firstMultiplier = HexNumbersParser::hexToDecimal(Helpers::toCharArray(fstMultiplier.getNumber()));
	std::int64_t secondMultiplier = HexNumbersParser::hexToDecimal(Helpers::toCharArray(sndMultiplier.getNumber()));
	
	return HexNumbersParser::decimalToHex(firstMultiplier * secondMultiplier);;
}

std::string HexCalculator::sqrtHexes(Number number)
{
	std::int64_t _number = HexNumbersParser::hexToDecimal(Helpers::toCharArray(number.getNumber()));
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

	return HexNumbersParser::decimalToHex(updatableSum);
}