#include <fstream>
#include <string>

#include "DecimalNumbersParser.h"
#include "HexNumbersParser.h"

#pragma once
#ifndef NUMBER_H
#define NUMBER_H

/// <summary>
/// NumberType is an enum type that will be used to
/// determine from what type is any number which will
/// be neede in calculation. 
/// </summary>
enum NumberType
{
	DECIMAL, HEXA
};

/// <summary>
/// Number is a class which describes numbers that can be calculated. 
/// </summary>
class Number
{
private:
	/// <summary>
	/// Number's std::string value.
	/// </summary>
	std::string number;

	/// <summary>
	/// Number's NumberType value.
	/// </summary>
	NumberType type;



	/// ---------- HELPER METHODS: ----------
	
	/// /// <summary>
	/// Inner validation method that accepts as
	/// </summary>
	/// <param name=""> number as std::string from outside and </param>
	/// <returns> wheather this number is valid decimal number or not. </returns>
	bool isValidDecimal(std::string);

	/// <summary>
	/// Inner validation method that accepts as
	/// </summary>
	/// <param name=""> number as std::string and </param>
	/// <returns> wheather this number is valid hex number or not. </returns>
	bool isValidHex(std::string);

	/// <summary>
	/// Prvate set method that accepts as
	/// </summary>
	/// <param name=""> number as std::string, validates it via inner validation methods
	/// and if it is valid sets values for this.number (std::string) and this.type (NumberType). </param>
	void setNumberAndNumberType(std::string);

public:
	/// <summary>
	/// Default constructor.
	/// </summary>
	Number();
	
	/// /// <summary>
	/// Constructor that accepts as
	/// </summary>
	/// <param name=""> number as std::string, validates it via inner validation methods and 
	/// if it is valid sets values for this.number (std::string) and this.type (NumberType). </param>
	Number(std::string);
	
	/// <summary>
	/// Overriden operator>> that accepts as
	/// </summary>
	/// <param name=""> stream as std::istream for input Number and initialize its fields 
	/// from it with valid values. </param>
	void operator>>(std::istream&);
	
	/// <summary>
	/// Overriden operator<< tha accepts as
	/// </summary>
	/// <param name=""> stream as std::ostream for printing Number in it. </param>
	void operator <<(std::ostream&);

	/// <summary>
	/// Public get methot that 
	/// </summary>
	/// <returns> this.number's value. </returns>
	std::string getNumber();

	/// <summary>
	/// Public get method that 
	/// </summary>
	/// <returns> this.type's value. </returns>
	NumberType getType();
};

#endif