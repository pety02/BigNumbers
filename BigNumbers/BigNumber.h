#include<string>
#include <vector>
#include <fstream>
#include <iostream>

#include "Helpers.h"
#include "InputValidator.h"

#pragma once
#ifndef BIGNUMBER_H
#define BIGNUMBER_H

class BigNumber
{
private:
	std::string number;
	
	int base;

	/*!
	 *  Sets the big number's number and base.
	 *
	 *      @param [in]   to set.
	 */	
	void setNumberAndBase(std::string);

	/*!
	 *  Returns the big number's symbol.
	 *
	 *      @param [in]  
	 *      @return The symbol.
	 */
	char getSymbol(int);

	/*!
	 *  Returns character depending on number's value.
	 *
	 *      @param [in]  number
	 *      @return The value.
	 */
	int getValue(char);

	/*!
	 *  Returns true if the big number is smaller than sndNumberString.
	 *
	 *      @param [in]  sndNumberString
	 *      @return True if smaller. False if not.
	 */
	bool isSmaller(std::string);

	/*!
	 *  Are the big number and sndNumberString same.
	 *
	 *      @param [in]  sndNumberString
	 *      @return True if same. False if not.
	 */
	bool areSame(std::string);

public:
	/*!
	 *  Default constructor.
	 */
	BigNumber();
	
	/*!
	 *  General use constructor.
	 *
	 *      @param [in]  numberAsString
	 */
	BigNumber(std::string);
	
	/*!
	 * Default virtual destructor in case someday extendance needed.
	 */
	virtual ~BigNumber() = default;

	/*!
	 *  Operator>>s inputs big number.
	 *
	 *      @param [in,out]  input
	 */
	void operator>>(std::istream&);
	
	/*!
	 *  Operator<<s otputs big number.
	 *
	 *      @param [in,out]  output
	 */
	void operator <<(std::ostream&);

	/*!
	 *  Operator=s assignes big number.
	 *
	 *      @param [in] otherNumber
	 *      @return copy of otherNumber.
	 */
	BigNumber& operator=(const BigNumber&);

	/*!
	 *  Operator+s sums big numbers. The algorithm behind this method
	 *	sums big numbers by adding them character by character. 
	 *
	 *      @param [in,out]  sndCollectable
	 *      @return sum of two big numbers.
	 */
	BigNumber& operator+(BigNumber&);

	/*!
	 *  Operator-s substracts big numbers. The algorithm behind this method
	 *	substracts big numbers by substracting them character by character. 
	 *
	 *      @param [in,out]  diminutive
	 *      @return difference of two big numbers.
	 */
	BigNumber& operator-(BigNumber&);

	/*!
	 *  Operator*s multiplies big numbers. The algorithm behind this method
	 *	multiplies big numbers by multiplying them character by character. 
	 *
	 *      @param [in,out]  sndMultiplier
	 *      @return product of two big numbers.
	 */
	BigNumber& operator*(BigNumber&);

	/*!
	 *  Operator/s devides big numbers. The algorithm behind this method
	 *	devides big numbers by sbstracting the divisor from divisible while
	 *	their difference become lower or equal to zero and increment a counter
	 *	that is the quotient of these two big numbers at the end of the method. 
	 *
	 *      @param [in,out]  divisor
	 *      @return quotient of two big numbers.
	 */
	BigNumber& operator/(BigNumber&);

	/*!
	 *  Deviddes two big numbers with quotient and reminder. Then return 
	 *	only the reminder. The algorithm behind this method devides big 
	 *	numbers by sbstracting the divisor from divisible while their difference 
	 *	becomes lower or equal to zero and increment a counter that is the 
	 *	quotient of these two big numbers at the end of the method. After all, 
	 *	the method returns the difference between divisible and the product of 
	 * quotient and divisor by the formula:
	 * 
	 *  reminder = divisible - divisor * quotient. 
	 *
	 *      @param [in]  divisor
	 *      @return reminder of division of two big numbers.
	 */
	BigNumber& mod(size_t);

	/*!
	 *  Returns the big number's number.
	 *
	 *      @return The number.
	 */
	const std::string getNumber() const;

	/*!
	 *  Returns the big number's base.
	 *
	 *      @return The base.
	 */
	const int getBase() const;

	/*!
	 *  Hex number to decimal.
	 *
	 *      @param [in] hex 
	 *      @return decimal number from hex. 
	 */
	int hexToDecimal(std::string hex);
};

#endif