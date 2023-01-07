#include <fstream>

#include "DecimalNumbersParser.h"
#include "HexNumbersParser.h"
#include "Helpers.h"
#include "InputValidator.h"

#pragma once
#ifndef BIGNUMBER_H
#define BIGNUMBER_H

enum class NumberType
{
	DECIMAL, HEX
};

class BigNumber
{
private:
	std::string number;

	NumberType type;

	void setNumberAndNumberType(std::string);

public:
	BigNumber();
	
	BigNumber(std::string);
	
	virtual ~BigNumber() = default;

	void operator>>(std::istream&);
	
	void operator <<(std::ostream&);

	BigNumber& operator=(const BigNumber& otherNumber);

	const BigNumber operator+(BigNumber&) const;

	const BigNumber operator-(BigNumber&) const;

	const BigNumber operator*(BigNumber&) const;

	const BigNumber operator/(BigNumber&) const;

	const BigNumber mod(BigNumber&, BigNumber&) const;

	const BigNumber sqrt() const;

	std::string getNumber();

	NumberType getType();
};

#endif