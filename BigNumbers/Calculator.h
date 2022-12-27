#pragma once
#include "Number.h"

class Calculator
{
public:
	virtual std::string add(Number, Number) = 0;
	virtual std::string substract(Number, Number) = 0;
	virtual void devide(Number, Number, long&, long&) = 0;
	virtual std::string multiply(Number, Number) = 0;
	virtual std::string sqrt(Number) = 0;
};