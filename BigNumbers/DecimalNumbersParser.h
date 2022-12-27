#pragma once
#include <iostream>
#include <cmath>
#include "Helpers.h"

class DecimalNumbersParser
{
public:
	static long stringToNumber(const char*, int);
	static std::string numberToString(long, int);
};