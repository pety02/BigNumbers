#pragma once
#include <iostream>
#include <string>
#include <cmath>

class NumbersParser
{
private:
	static int numberSize(long n, int base) 
	{
		int cnt = (n >= 0) ? 0 : 1;
		while (n != 0)
		{
			cnt++;
			n /= base;
		}

		return cnt;
	}
public:
	static long stringToNumber(const char* sPos, int base) 
	{
		std::string s = sPos;
		int power = s.length() - 1;
		long number = 0;
		while (*sPos != '\0')
		{
			number += (*(sPos++) - '0') * pow(base, power--);
		}

		return number;
	}

	static std::string numberToString(long n, int base)
	{
		int size = NumbersParser::numberSize(n, base);
		char* s = new char[size + 1];

		int index = size;
		while (index != 0)
		{
			s[--index] = (n % base) + '0';
			n /= base;
		}
		s[size] = '\0';
		return s;
	}

	static char* toCharArray(const std::string s) 
	{
		char* arr = new char[s.length()];
		for (int i = 0; i < s.length(); i++)
		{
			arr[i] = s[i];
		}

		arr[s.length()] = '\0';

		return arr;
	}
};