#include<string>
#include <vector>
#include <fstream>
#include <iostream>

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
	int base;

	void setNumberTypeAndBase(std::string);

	char getSymbol(int);

	int getValue(char);

	bool isSmaller(std::string, std::string);

	bool areSame(std::string, std::string);

public:
	BigNumber();
	
	BigNumber(std::string);
	
	virtual ~BigNumber() = default;

	void operator>>(std::istream&);
	
	void operator <<(std::ostream&);

	BigNumber& operator=(const BigNumber& otherNumber);

	BigNumber& operator+(BigNumber&);

	BigNumber& operator-(BigNumber&);

	BigNumber& operator*(BigNumber&);

	BigNumber& operator/(BigNumber&);

	const BigNumber mod(BigNumber&, BigNumber&) const;

	const BigNumber sqrt() const;

	const std::string getNumber() const;

	const NumberType getType() const;

	const int getBase() const;
};

#endif