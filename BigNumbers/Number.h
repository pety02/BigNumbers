#include "NumbersParser.h"
#include <fstream>
#pragma once

class Number
{
private:
	std::string number;
public:
	void operator >>(std::istream&);
	void operator <<(std::ostream&);
	void printDecimal();
	std::string addDecimals(const Number num);
	std::string substractDecimals(const Number num);
	void devideDecimals(const Number num, long& q, long& r);
	std::string multiplyDecimals(const Number num);
	std::string sqrtDecimals();
};