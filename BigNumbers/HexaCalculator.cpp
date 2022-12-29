#include "HexaCalculator.h"

std::string HexaCalculator::addHexas(Number fstCollectable, Number sndCollectable)
{
	std::int64_t firstCollectable = HexaNumbersParser::hexToNumber(Helpers::toCharArray(fstCollectable.getNumber()));
	std::int64_t secondCollectable = HexaNumbersParser::hexToNumber(Helpers::toCharArray(sndCollectable.getNumber()));
	
	return HexaNumbersParser::numberToHex(firstCollectable + secondCollectable);
}

std::string HexaCalculator::substractHexas(Number reducible, Number diminutive)
{
	std::int64_t _reducible = HexaNumbersParser::hexToNumber(Helpers::toCharArray(reducible.getNumber()));
	std::int64_t _diminutive = HexaNumbersParser::hexToNumber(Helpers::toCharArray(diminutive.getNumber()));

	std::string substraction = "";
	if (_reducible < _diminutive)
	{
		substraction += "-";
	}
	substraction += HexaNumbersParser::numberToHex(std::abs(_reducible - _diminutive));

	return substraction;
}

void HexaCalculator::devideHexas(Number deivisible, Number divisor, std::string& quotient, std::string& reminder)
{
	std::int64_t _divisible = HexaNumbersParser::hexToNumber(Helpers::toCharArray(deivisible.getNumber()));
	std::int64_t _divisor = HexaNumbersParser::hexToNumber(Helpers::toCharArray(divisor.getNumber()));

	quotient = _divisible / _divisor;
	reminder = _divisible % _divisor;

	return;
}

std::string HexaCalculator::multiplyHexas(Number fstMultiplier, Number sndMultiplier)
{
	std::int64_t firstMultiplier = HexaNumbersParser::hexToNumber(Helpers::toCharArray(fstMultiplier.getNumber()));
	std::int64_t secondMultiplier = HexaNumbersParser::hexToNumber(Helpers::toCharArray(sndMultiplier.getNumber()));
	
	return HexaNumbersParser::numberToHex(firstMultiplier * secondMultiplier);;
}

std::string HexaCalculator::sqrtHexas(Number number)
{
	std::int64_t _number = HexaNumbersParser::hexToNumber(Helpers::toCharArray(number.getNumber()));
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

	return HexaNumbersParser::numberToHex(updatableSum);
}