#include<string>

#pragma once
#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

class InputValidator
{
public:	
	static bool isDigit(char symbol);

	static bool isHexLetter(char symbol);

	static bool isValidDecimal(std::string);

	static bool isValidHex(std::string);
};

#endif