#include "Helpers.h"

#pragma once
#ifndef HEXNUMBERSPARSER_H
#define HEXNUMBERSPARSER_H

/// <summary>
/// HexNumbersParser is a parser class.
/// </summary>
class HexNumbersParser
{
private:
	/// <summary>
	/// Method that accepts as 
	/// </summary>
	/// <param name=""> number as std::int64_t and </param>
	/// <returns> the greates power of 16. </returns>
	static int findGeatestPower(std::int64_t);

public:
	/// <summary>
	/// Constatnt that determines hex numeric system base.
	/// </summary>
	static const int BASE = 16;

	/// <summary>
	/// Method that accepts as 
	/// </summary>
	/// <param name=""> number as const char* in hex and </param>
	/// <returns> this number as decimal number (std::int64_t). </returns>
	static std::int64_t hexToDecimal(const char*);

	/// <summary>
	/// Method that accepts as 
	/// </summary>
	/// <param name=""> decimal number as std::int64_t in and </param>
	/// <returns> this number as hex (std::string). </returns>
	static std::string decimalToHex(std::int64_t);
};

#endif