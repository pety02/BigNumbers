#include "Number.h"

bool isDigit(char symbol)
{
	return symbol < '0' || '9' < symbol;
}

bool isHexLetter(char symbol)
{
	return symbol < 'A' || 'F' < symbol;
}

bool Number::isValidDecimal(std::string decimalNumberAsString)
{
	bool isDecimal = true;
	for (size_t index = 0; index < decimalNumberAsString.length(); ++index)
	{
		if (isDigit(decimalNumberAsString[index])) 
		{
			isDecimal = false; break;
		}
	}

	return isDecimal;
}

bool Number::isValidHex(std::string hexNumberAsString)
{
	bool isHex = true;
	for (size_t index = 0; index < hexNumberAsString.length(); ++index)
	{
		if (!isDigit(hexNumberAsString[index]) && !isHexLetter(hexNumberAsString[index]))
		{
			isHex = false; break;
		}
	}

	return isHex;
}

void Number::setNumberAndNumberType(std::string numberAsString)
{
	if (isValidDecimal(numberAsString))
	{
		this->number = numberAsString;
		this->type = NumberType::DECIMAL;
		return;
	} 
	else if (isValidHex(numberAsString))
	{
		this->number = numberAsString;
		this->type = NumberType::HEXA;
		return;
	}
}

Number::Number()
{
	setNumberAndNumberType("0");
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

std::string Number::getNumber() 
{
	return this->number;
}

NumberType Number::getType() 
{
	return this->type;
}