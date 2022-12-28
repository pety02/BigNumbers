#include "DecimalCalculator.h"
#include "HexaCalculator.h"

#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
public:
	static std::string add(Number, Number);
	static std::string substract(Number, Number);
	static void devide(Number, Number, long&, long&);
	static std::string multiply(Number, Number);
	static std::string sqrt(Number);
};

#endif