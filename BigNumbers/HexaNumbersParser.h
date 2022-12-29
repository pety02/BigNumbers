#include "Helpers.h"

#pragma once
#ifndef HEXANUMBERSPARSER_H
#define HEXANUMBERSPARSER_H

class HexaNumbersParser
{
private:
	static int findGeatestPower(std::int64_t n);

public:
	static const int BASE = 16;
	static std::int64_t hexToNumber(const char*);
	static std::string numberToHex(std::int64_t);
};

#endif