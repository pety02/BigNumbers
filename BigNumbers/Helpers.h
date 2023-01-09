#include <string>
#include <iostream>

#pragma once
#ifndef HELPERS_H
#define HELPERS_H

class Helpers
{
public:
	/*!
	 *  Returns the number's size depending on the counting system's base.
	 *
	 *      @param [in]  number
	 *      @param [in]  base
	 *
	 *      @return number's size.
	 */
	static int numberSize(std::int64_t, int);
	
	/*!
	 *  Returns the string's to char array.
	 *
	 *      @param [in]  string
	 *
	 *      @return array of string's characters.
	 */
	static char* toCharArray(const std::string);
};

#endif