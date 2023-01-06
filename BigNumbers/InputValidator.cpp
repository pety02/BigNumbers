#include "InputValidator.h"

bool InputValidator::isDigit(char symbol)
{
	return '0' <= symbol && symbol <= '9';
}

bool InputValidator::isHexLetter(char symbol)
{
	return 'A' <= symbol && symbol <= 'F';
}

bool InputValidator::isValidDecimal(std::string decimalNumberAsString)
{
	bool isDecimal = decimalNumberAsString.length() > 0;
	
	if (decimalNumberAsString.length() > 1 && decimalNumberAsString[0] == '-')
	{
		isDecimal = true;
	}
	
	for (size_t index = 1; index < decimalNumberAsString.length(); ++index)
	{
		if (!isDigit(decimalNumberAsString[index]))
		{
			isDecimal = false; break;
		}
	}

	return isDecimal;
}

bool InputValidator::isValidHex(std::string hexNumberAsString)
{
	bool isHex = hexNumberAsString.length() > 0;

	if (hexNumberAsString.length() > 1 && hexNumberAsString[0] == '-')
	{
		isHex = true;
	}

	for (size_t index = 0; index < hexNumberAsString.length(); ++index)
	{
		if (!isDigit(hexNumberAsString[index]) && !isHexLetter(hexNumberAsString[index]))
		{
			isHex = false; break;
		}
	}

	return isHex;
}