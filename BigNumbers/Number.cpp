#include "Number.h"

bool Number::isValidDecimal(std::string number)
{
	bool isValid = true;
	for (int i = 0; i < number.length(); i++)
	{
		if (number[i] < '0' || '9' < number[i]) 
		{
			isValid = false; break;
		}
	}

	return isValid;
}

bool Number::isValidHexa(std::string number)
{
	bool isValid = true;
	for (int i = 0; i < number.length(); i++)
	{
		if (!('0' <= number[i] && number[i] <= '9') && 
			!('A' <= number[i] && number[i] <= 'F'))
		{
			isValid = false; break;
		}
	}

	return isValid;
}

void Number::operator>>(std::istream& in)
{
	if (in.good()) 
	{
		std::string number;
		in >> number;
		
		if (isValidDecimal(number)) 
		{
			this->number = number;
			this->type = NumberType::DECIMAL;
		}

		if (isValidHexa(number))
		{
			this->number = number;
			this->type = NumberType::HEXA;
		}
	}
}

void Number::operator <<(std::ostream& os)
{
	if (os.good()) 
	{
		os << "Number: " << this->number << '\n';
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