#include "Helpers.h"

#pragma once
#ifndef DECIMALNUMBERSPARSER_H
#define DECIMALNUMBERSPARSER_H

class DecimalNumbersParser
{
public:
	static const int BASE = 10;
	
	static std::int64_t stringToDecimal(const char*);
	
	static std::string decimalToString(std::int64_t);
};

#endif