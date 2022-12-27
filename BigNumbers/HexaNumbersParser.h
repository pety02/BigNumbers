#pragma once
#include <iostream>
#include <cmath>
#include "Helpers.h"

class HexaNumbersParser
{
private:
	static int findGeatestPower(long n, int base);

public:
	static long hexaToNumber(const char*, int);
	static std::string numberToHexa(long, int);
};