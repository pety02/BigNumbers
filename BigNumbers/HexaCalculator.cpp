#include "HexaCalculator.h"

std::string HexaCalculator::addHexas(Number fstCollectable, Number sndCollectable)
{
	long firstCollectable = HexaNumbersParser::hexToNumber(Helpers::toCharArray(fstCollectable.getNumber()));
	long secondCollectable = HexaNumbersParser::hexToNumber(Helpers::toCharArray(sndCollectable.getNumber()));
	
	return HexaNumbersParser::numberToHex(firstCollectable + secondCollectable);
}

std::string HexaCalculator::substractHexas(Number reducible, Number diminutive)
{
	long _reducible = HexaNumbersParser::hexToNumber(Helpers::toCharArray(reducible.getNumber()));
	long _diminutive = HexaNumbersParser::hexToNumber(Helpers::toCharArray(diminutive.getNumber()));

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
	long _divisible = HexaNumbersParser::hexToNumber(Helpers::toCharArray(deivisible.getNumber()));
	long _divisor = HexaNumbersParser::hexToNumber(Helpers::toCharArray(divisor.getNumber()));

	quotient = _divisible / _divisor;
	reminder = _divisible % _divisor;

	return;
}

std::string HexaCalculator::multiplyHexas(Number fstMultiplier, Number sndMultiplier)
{
	long firstMultiplier = HexaNumbersParser::hexToNumber(Helpers::toCharArray(fstMultiplier.getNumber()));
	long secondMultiplier = HexaNumbersParser::hexToNumber(Helpers::toCharArray(sndMultiplier.getNumber()));
	
	return HexaNumbersParser::numberToHex(firstMultiplier * secondMultiplier);;
}

std::string HexaCalculator::sqrtHexas(Number number)
{
	long _number = HexaNumbersParser::hexToNumber(Helpers::toCharArray(number.getNumber()));
	long updatableSum = 0;
	long heightestPowerOfFour = 1 << 30;

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