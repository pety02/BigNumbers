#pragma once
#include "Calculator.h"
class DecimalCalculator : public Calculator
{
public:
	static std::string add(Number, Number);
	static std::string substract(Number, Number);
	static void devide(Number, Number, long&, long&);
	static std::string multiply(Number, Number);
	static std::string sqrt(Number);
};