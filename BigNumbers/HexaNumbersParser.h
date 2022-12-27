#pragma once
#include <iostream>
#include <cmath>
#include "Helpers.h"

class HexaNumbersParser
{
private:
	static int findGeatestPower(long n);

public:
	static const int BASE = 16;
	static long hexaToNumber(const char*);
	static std::string numberToHexa(long);
};