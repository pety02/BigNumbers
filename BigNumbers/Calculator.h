#include "DecimalCalculator.h"
#include "HexCalculator.h"

#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

/// <summary>
/// Calculator is combined hex and decimal numbers calculator class.
/// </summary>
class Calculator
{
public:
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> firstCollectable (Number), accepts as </param>
	/// <param name=""> secondCollectable (Number) and </param>
	/// <returns> their sum as decimal or hex number (std::string)
	/// in dependance of params' numbers' types. </returns>
	static std::string add(Number, Number);
	
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> redusable (Number), accepts as </param>
	/// <param name=""> reducive (Number) and </param>
	/// <returns> their substraction as decimal or hex number (std::string)
	/// in dependance of params' numbers' types. </returns>
	static std::string substract(Number, Number);
	
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> divisible (Number), accepts as </param>
	/// <param name=""> divisor (Number) and </param>
	/// <returns> their quotion as decimal or hex number (std::string)
	/// in dependance of params' numbers' types. </returns>
	static void devide(Number, Number, std::string&, std::string&);
	
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> firstMultiplier (Number), accepts as </param>
	/// <param name=""> secondMultiplier (Number) and </param>
	/// <returns> their product as decimal or hex number (std::string)
	/// in dependance of params' numbers' types. </returns>
	static std::string multiply(Number, Number);
	
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> number (Number) and </param>
	/// <returns> its square root as decimal or hex number (std::string)
	/// in dependance of param's number's type. </returns>
	static std::string sqrt(Number);
};

#endif