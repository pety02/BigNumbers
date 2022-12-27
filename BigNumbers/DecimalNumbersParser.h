#pragma once
#include <iostream>
#include <string>
#include <cmath>

class DecimalNumbersParser
{
private:
	static int numberSize(long, int);

public:
	static long stringToNumber(const char*, int);
	static std::string numberToString(long, int);
	static char* toCharArray(const std::string);
};