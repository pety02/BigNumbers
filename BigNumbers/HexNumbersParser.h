#include "Helpers.h"

#pragma once
#ifndef HEXNUMBERSPARSER_H
#define HEXNUMBERSPARSER_H

class HexNumbersParser
{
private:
	static int findGeatestPower(std::int64_t);

public:
	static const int BASE = 16;

	static std::int64_t hexToDecimal(const char*);

	static std::string decimalToHex(std::int64_t);
};

#endif