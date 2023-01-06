#include <fstream>

#include "DecimalNumbersParser.h"
#include "HexNumbersParser.h"
#include "Helpers.h"
#include "InputValidator.h"

#pragma once
#ifndef NUMBER_H
#define NUMBER_H

enum class NumberType
{
	DECIMAL, HEX
};

class Number
{
private:
	std::string number;

	NumberType type;

	void setNumberAndNumberType(std::string);

public:
	Number();
	
	Number(std::string);
	
	void operator>>(std::istream&);
	
	void operator <<(std::ostream&);

	const Number operator+(Number&) const;

	const Number operator-(Number&) const;

	const Number operator*(Number&) const;

	const Number operator/(Number&) const;

	const Number mod(Number&, Number&) const;

	const Number sqrt() const;

	std::string getNumber();

	NumberType getType();
};

#endif