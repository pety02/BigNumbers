#include "Helpers.h"

#pragma once
#ifndef DECIMALNUMBERSPARSER_H
#define DECIMALNUMBERSPARSER_H

class DecimalNumbersParser
{
public:
	static const int BASE = 10;
	static long stringToNumber(const char*);
	static std::string numberToString(long);
};

#endif