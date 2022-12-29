#include "Number.h"
#include "Helpers.h"

#pragma once
#ifndef HEXACALCULATOR_H
#define HEXACALCULATOR_H

/// <summary>
/// HexCalculator is hex numbers calculator class.
/// </summary>
class HexCalculator
{
public:
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> firstCollectable (Number), accepts as </param>
	/// <param name=""> secondCollectable (Number) and </param>
	/// <returns> their sum as hex number (std::string). </returns>
	static std::string addHexes(Number, Number);
	
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> redusable (Number), accepts as </param>
	/// <param name=""> reducive (Number) and </param>
	/// <returns> their substraction as hex number (std::string). </returns>
	static std::string substractHexes(Number, Number);
	
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> divisible (Number), accepts as </param>
	/// <param name=""> divisor (Number) and </param>
	/// <returns> their quotion as hex number (std::string) 
	/// and reminder as hex number (std::string). </returns>
	static void devideHexes(Number, Number, std::string&, std::string&);
	
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> firstMultiplier (Number), accepts as </param>
	/// <param name=""> secondMultiplier (Number) and </param>
	/// <returns> their product as hex number (std::string). </returns>
	static std::string multiplyHexes(Number, Number);
	
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> number (Number) and </param>
	/// <returns> its square root as hex number (std::string). </returns>
	static std::string sqrtHexes(Number);
};

#endif