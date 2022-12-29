#include "Helpers.h"

int Helpers::numberSize(std::int64_t number, int base)
{
	int digitsCounter = (number >= 0) ? 0 : 1;
	while (number != 0)
	{
		digitsCounter++;
		number /= base;
	}

	return digitsCounter;
}

char* Helpers::toCharArray(const std::string string)
{
	char* charsArr = new char[string.length()];
	for (size_t index = 0; index < string.length(); ++index)
	{
		charsArr[index] = string[index];
	}

	charsArr[string.length()] = '\0';

	return charsArr;
}