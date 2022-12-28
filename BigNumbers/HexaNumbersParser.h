#include "Helpers.h"

#pragma once
#ifndef HEXANUMBERSPARSER_H
#define HEXANUMBERSPARSER_H

class HexaNumbersParser
{
private:
	static int findGeatestPower(long n);

public:
	static const int BASE = 16;
	static long hexToNumber(const char*);
	static std::string numberToHex(long);
};

#endif