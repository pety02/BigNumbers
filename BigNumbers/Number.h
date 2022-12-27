#include "DecimalNumbersParser.h"
#include "HexaNumbersParser.h"
#include <fstream>
#pragma once

enum NumberType
{
	DECIMAL, HEXA
};

class Number
{
private:
	std::string number;
	NumberType type;

	bool isValidDecimal(std::string);
	bool isValidHexa(std::string);
	void setNumberAndNumberType(std::string);
public:
	Number();
	Number(std::string);
	void operator >>(std::istream&);
	void operator <<(std::ostream&);

	std::string getNumber();
	NumberType getType();
};