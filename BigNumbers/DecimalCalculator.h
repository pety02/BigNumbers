#include "Number.h"
#include "Helpers.h"

#pragma once
#ifndef DECIMALCALCULATOR_H
#define DECIMALCALCULATOR_H

/// <summary>
/// DecimalCalculator is decimal numbers calculator class.
/// </summary>
class DecimalCalculator
{
public:
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> firstCollectable (Number), accepts as </param>
	/// <param name=""> secondCollectable (Number) and </param>
	/// <returns> their sum as decimal number (std::string). </returns>
	static std::string addDecimals(Number, Number);
	
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> redusable (Number), accepts as </param>
	/// <param name=""> reducive (Number) and </param>
	/// <returns> their substraction as decimal number (std::string). </returns>
	static std::string substractDecimnals(Number, Number);
	
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> divisible (Number), accepts as </param>
	/// <param name=""> divisor (Number) and </param>
	/// <returns> their quotion as decimal number (std::string) 
	/// and reminder as decimal number (std::string). </returns>
	static void devideDecimals(Number, Number, std::string&, std::string&);
	
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> firstMultiplier (Number), accepts as </param>
	/// <param name=""> secondMultiplier (Number) and </param>
	/// <returns> their product as decimal number (std::string). </returns>
	static std::string multiplyDecimals(Number, Number);
	
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> number (Number) and </param>
	/// <returns> its square root as decimal number (std::string). </returns>
	static std::string sqrtDecimals(Number);
};

#endif