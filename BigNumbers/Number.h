#include <fstream>
#include <string>

#include "DecimalNumbersParser.h"
#include "HexaNumbersParser.h"

#pragma once
#ifndef NUMBER_H
#define NUMBER_H

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
	bool isValidHex(std::string);
	void setNumberAndNumberType(std::string);
public:
	Number();
	Number(std::string);
	void operator >>(std::istream&);
	void operator <<(std::ostream&);

	std::string getNumber();
	NumberType getType();
};

#endif