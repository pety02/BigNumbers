#include "Number.h"

void Number::setNumberAndNumberType(std::string numberAsString = "0")
{
	try
	{
		if (InputValidator::isValidDecimal(numberAsString))
		{
			number = numberAsString;
			type = NumberType::DECIMAL;
			return;
		}
	
		if (InputValidator::isValidHex(numberAsString))
		{
			number = numberAsString;
			type = NumberType::HEX;
			return;
		}
		
		throw std::invalid_argument("Invalid number as string!");
	}
	catch (std::invalid_argument)
	{
		number = "0";
		type = NumberType::DECIMAL;
	}
}

Number::Number()
{
	setNumberAndNumberType();
}

Number::Number(std::string numberAsString)
{
	setNumberAndNumberType(numberAsString);
}

void Number::operator>>(std::istream& input)
{
	if (input.good()) 
	{
		std::string numberAsString;
		input >> numberAsString;
		
		setNumberAndNumberType(numberAsString);
	}
}

void Number::operator <<(std::ostream& output)
{
	if (output.good()) 
	{
		output << this->number << '\n';
	}
}

const Number Number::operator+(Number& sndCollectable) const
{
	if (type == NumberType::DECIMAL && sndCollectable.getType() == NumberType::DECIMAL)
	{
		std::int64_t firstCollectable = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(number));
		std::int64_t secondCollectable = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(sndCollectable.getNumber()));

		Number sum = Number(DecimalNumbersParser::decimalToString(firstCollectable + secondCollectable));
		return sum;
	}

	if ((type == NumberType::DECIMAL && sndCollectable.getType() == NumberType::HEX) 
		|| (type == NumberType::HEX && sndCollectable.getType() == NumberType::DECIMAL) 
		|| (type == NumberType::HEX && sndCollectable.getType() == NumberType::HEX))
	{
		std::int64_t firstCollectable = HexNumbersParser::hexToDecimal(Helpers::toCharArray(number));
		std::int64_t secondCollectable = HexNumbersParser::hexToDecimal(Helpers::toCharArray(sndCollectable.getNumber()));

		Number sum = Number(HexNumbersParser::decimalToHex(firstCollectable + secondCollectable));
		return sum;
	}

	throw std::invalid_argument("Invalid collectables!");
}

const Number Number::operator-(Number& diminutive) const
{
	if (type == NumberType::DECIMAL && diminutive.getType() == NumberType::DECIMAL)
	{
		std::int64_t _reducive = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(number));
		std::int64_t _diminutive = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(diminutive.getNumber()));

		std::string substraction = "";
		if (_reducive < _diminutive)
		{
			substraction += "-";
		}
		substraction += DecimalNumbersParser::decimalToString(std::abs(_reducive - _diminutive));

		return Number(substraction);
	}

	if ((type == NumberType::DECIMAL && diminutive.getType() == NumberType::HEX)
		|| (type == NumberType::HEX && diminutive.getType() == NumberType::DECIMAL)
		|| (type == NumberType::HEX && diminutive.getType() == NumberType::HEX))
	{
		std::int64_t _reducive = HexNumbersParser::hexToDecimal(Helpers::toCharArray(number));
		std::int64_t _diminutive = HexNumbersParser::hexToDecimal(Helpers::toCharArray(diminutive.getNumber()));

		std::string substraction = "";
		if (_reducive < _diminutive)
		{
			substraction += "-";
		}
		substraction += HexNumbersParser::decimalToHex(std::abs(_reducive - _diminutive));

		return Number(substraction);
	}

	throw std::invalid_argument("Invalid reducive and diminutive!");
}

const Number Number::operator*(Number& sndMultiplier) const
{
	if (type == NumberType::DECIMAL && sndMultiplier.getType() == NumberType::DECIMAL)
	{
		std::int64_t firstMultiplier = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(number));
		std::int64_t secondMultiplier = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(sndMultiplier.getNumber()));

		return Number(DecimalNumbersParser::decimalToString(firstMultiplier * secondMultiplier));
	}

	if ((type == NumberType::DECIMAL && sndMultiplier.getType() == NumberType::HEX)
		|| (type == NumberType::HEX && sndMultiplier.getType() == NumberType::DECIMAL)
		|| (type == NumberType::HEX && sndMultiplier.getType() == NumberType::HEX))
	{
		std::int64_t firstMultiplier = HexNumbersParser::hexToDecimal(Helpers::toCharArray(number));
		std::int64_t secondMultiplier = HexNumbersParser::hexToDecimal(Helpers::toCharArray(sndMultiplier.getNumber()));

		return Number(HexNumbersParser::decimalToHex(firstMultiplier * secondMultiplier));
	}

	throw std::invalid_argument("Invalid multipliers!");
}

const Number Number::operator/(Number& divisor) const
{
	if (type == NumberType::DECIMAL && divisor.getType() == NumberType::DECIMAL)
	{
		std::int64_t _divisible = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(number));
		std::int64_t _divisor = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(divisor.getNumber()));

		return Number(DecimalNumbersParser::decimalToString(_divisible / _divisor));
	}

	if ((type == NumberType::DECIMAL && divisor.getType() == NumberType::HEX)
		|| (type == NumberType::HEX && divisor.getType() == NumberType::DECIMAL)
		|| (type == NumberType::HEX && divisor.getType() == NumberType::HEX))
	{
		std::int64_t _divisible = HexNumbersParser::hexToDecimal(Helpers::toCharArray(number));
		std::int64_t _divisor = HexNumbersParser::hexToDecimal(Helpers::toCharArray(divisor.getNumber()));

		return Number(HexNumbersParser::decimalToHex(_divisible / _divisor));
	}

	throw std::invalid_argument("Invalid divisible and divisor!");
}

const Number Number::mod(Number& divisor, Number& reminder) const
{
	if (type == NumberType::DECIMAL && divisor.getType() == NumberType::DECIMAL)
	{
		std::int64_t _divisible = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(number));
		std::int64_t _divisor = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(divisor.getNumber()));

		reminder = (_divisible % _divisor != 0) ? Number(DecimalNumbersParser::decimalToString(_divisible % _divisor)) 
			: Number();
		return Number(DecimalNumbersParser::decimalToString(_divisible / _divisor));
	}

	if ((type == NumberType::DECIMAL && divisor.getType() == NumberType::HEX)
		|| (type == NumberType::HEX && divisor.getType() == NumberType::DECIMAL)
		|| (type == NumberType::HEX && divisor.getType() == NumberType::HEX))
	{
		std::int64_t _divisible = HexNumbersParser::hexToDecimal(Helpers::toCharArray(number));
		std::int64_t _divisor = HexNumbersParser::hexToDecimal(Helpers::toCharArray(divisor.getNumber()));

		reminder = (_divisible % _divisor != 0) ? Number(HexNumbersParser::decimalToHex(_divisible % _divisor)) 
			: Number();
		return Number(HexNumbersParser::decimalToHex(_divisible / _divisor));
	}

	throw std::invalid_argument("Invalid divisible and divisor!");
}

const Number Number::sqrt() const
{
	if (type == NumberType::DECIMAL)
	{
		std::int64_t _number = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(number));
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

		return Number(DecimalNumbersParser::decimalToString(updatableSum));
	}

	if (type == NumberType::HEX)
	{
		std::int64_t _number = HexNumbersParser::hexToDecimal(Helpers::toCharArray(number));
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

		return Number(HexNumbersParser::decimalToHex(updatableSum));
	}

	throw std::invalid_argument("Invalid number to be square rooted!");
}

std::string Number::getNumber() 
{
	return this->number;
}

NumberType Number::getType() 
{
	return this->type;
}