#pragma once
#include <iostream>
#include <cmath>
#include "Helpers.h"

class DecimalNumbersParser
{
public:
	static const int BASE = 10;
	static long stringToNumber(const char*);
	static std::string numberToString(long);
};