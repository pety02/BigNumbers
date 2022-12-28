#include "Number.h"
#include "Helpers.h"

#pragma once
#ifndef HEXACALCULATOR_H
#define HEXACALCULATOR_H

class HexaCalculator
{
public:
	static std::string addHexas(Number, Number);
	static std::string substractHexas(Number, Number);
	static void devideHexas(Number, Number, std::string&, std::string&);
	static std::string multiplyHexas(Number, Number);
	static std::string sqrtHexas(Number);
};

#endif