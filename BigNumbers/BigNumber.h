#include<string>
#include <vector>
#include <fstream>
#include <iostream>

#include "Helpers.h"
#include "InputValidator.h"

#pragma once
#ifndef BIGNUMBER_H
#define BIGNUMBER_H

class BigNumber
{
private:
	std::string number;
	
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

	BigNumber& mod(size_t);

	const std::string getNumber() const;

	const int getBase() const;

	int hexToDecimal(std::string hex);
};

#endif