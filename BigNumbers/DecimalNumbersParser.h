#include "Helpers.h"

#pragma once
#ifndef DECIMALNUMBERSPARSER_H
#define DECIMALNUMBERSPARSER_H

/// <summary>
/// DecimalNumbersParser is a parser class.
/// </summary>
class DecimalNumbersParser
{
public:
	/// <summary>
	/// Constatnt that determines decimal numeric system base.
	/// </summary>
	static const int BASE = 10;
	
	/// <summary>
	/// Method that accepts as 
	/// </summary>
	/// <param name=""> number as const char* in decimal and </param>
	/// <returns> this number as decimal number (std::int64_t). </returns>
	static std::int64_t stringToDecimal(const char*);
	
	/// <summary>
	/// Method that accepts as 
	/// </summary>
	/// <param name=""> decimal number as std::int64_t in and </param>
	/// <returns> this number as std::string. </returns>
	static std::string decimalToString(std::int64_t);
};

#endif