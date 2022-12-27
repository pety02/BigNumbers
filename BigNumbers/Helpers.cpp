#include "Helpers.h"

int Helpers::numberSize(long n, int base)
{
	int cnt = (n >= 0) ? 0 : 1;
	while (n != 0)
	{
		cnt++;
		n /= base;
	}

	return cnt;
}

char* Helpers::toCharArray(const std::string s)
{
	char* arr = new char[s.length()];
	for (int i = 0; i < s.length(); i++)
	{
		arr[i] = s[i];
	}

	arr[s.length()] = '\0';

	return arr;
}