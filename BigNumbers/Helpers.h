#include <string>
#include <iostream>
#pragma once
#ifndef HELPERS_H
#define HELPERS_H

/// <summary>
/// Helpers is class with helper functions
/// </summary>
class Helpers
{
public:
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> number as std::string, accepts as </param>
	/// <param name=""> base as int and </param>
	/// <returns> counts of number's digits. </returns>
	static int numberSize(std::int64_t, int);
	
	/// <summary>
	/// Method that accepts as
	/// </summary>
	/// <param name=""> number as std::string and </param>
	/// <returns> this number as chars array. </returns>
	static char* toCharArray(const std::string);
};

#endif