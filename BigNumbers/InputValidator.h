#include<string>

#pragma once
#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

class InputValidator
{
public:	
	/*!
	 *  Returns true if the symbol is digit.
	 *
	 *      @param [in] symbol 
	 *
	 *      @return True if digit. False if not.
	 */
	static bool isDigit(char);

	/*!
	 *  Returns true if the symbol is hex letter.
	 *
	 *      @param [in] symbol 
	 *
	 *      @return True if hex letter. False if not.
	 */
	static bool isHexLetter(char symbol);

	/*!
	 *  Returns true if the decimalNumberAsString is valid decimal.
	 *
	 *      @param [in]  decimalNumberAsString
	 *
	 *      @return True if valid decimal. False if not.
	 */
	static bool isValidDecimal(std::string);

	/*!
	 *  Returns true if the hexNumberAsString is valid hex.
	 *
	 *      @param [in]  hexNumberAsString
	 *
	 *      @return True if valid hex. False if not.
	 */
	static bool isValidHex(std::string);
};

#endif