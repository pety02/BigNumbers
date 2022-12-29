#include "Number.h"
#include "Helpers.h"

#pragma once
#ifndef DECIMALCALCULATOR_H
#define DECIMALCALCULATOR_H

class DecimalCalculator
{
public:
	static std::string addDecimals(Number, Number);
	static std::string substractDecimnals(Number, Number);
	static void devideDecimals(Number, Number, std::int64_t&, std::int64_t&);
	static std::string multiplyDecimals(Number, Number);
	static std::string sqrtDecimals(Number);
};

#endif