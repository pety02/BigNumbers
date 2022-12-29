#include "HexNumbersParser.h"

int HexNumbersParser::findGeatestPower(std::int64_t number)
{
	int power = 0;
	while (number >= HexNumbersParser::BASE)
	{
		power++;
		number /= HexNumbersParser::BASE;
	}

	return power;
}

std::int64_t HexNumbersParser::hexToDecimal(const char* hex)
{
	std::string hexAsString = hex;
	int power = hexAsString.length() - 1;
	std::int64_t number = 0;
	int multiplier = 0;
	while (*hex != '\0')
	{
		switch (*hex)
		{
			case '0': multiplier = 0; break;
			case '1': multiplier = 1; break;
			case '2': multiplier = 2; break;
			case '3': multiplier = 3; break;
			case '4': multiplier = 4; break;
			case '5': multiplier = 5; break;
			case '6': multiplier = 6; break;
			case '7': multiplier = 7; break;
			case '8': multiplier = 8; break;
			case '9': multiplier = 9; break;

			case 'A': multiplier = 10; break;
			case 'B': multiplier = 11; break;
			case 'C': multiplier = 12; break;
			case 'D': multiplier = 13; break;
			case 'E': multiplier = 14; break;
			case 'F': multiplier = 15; break;

			default: break;
		}

		number += multiplier * pow(16, power--);
		hex++;
	}

	return number;
}

std::string HexNumbersParser::decimalToHex(std::int64_t number)
{
	std::string hex = "";
	int greatestPower = findGeatestPower(number);

	int multiplier = number / pow(HexNumbersParser::BASE, greatestPower);
	while (number / 16 >= 0 && number)
	{
		std::string ch = "";
		switch (multiplier)
		{
		case 0: ch = "0"; break;
		case 1: ch = "1"; break;
		case 2: ch = "2"; break;
		case 3: ch = "3"; break;
		case 4: ch = "4"; break;
		case 5: ch = "5"; break;
		case 6: ch = "6"; break;
		case 7: ch = "7"; break;
		case 8: ch = "8"; break;
		case 9: ch = "9"; break;

		case 10: ch = "A"; break;
		case 11: ch = "B"; break;
		case 12: ch = "C"; break;
		case 13: ch = "D"; break;
		case 14: ch = "E"; break;
		case 15: ch = "F"; break;

		default: break;
		}
		hex += ch;

		std::int64_t previousSum = multiplier * pow(HexNumbersParser::BASE, greatestPower);
		number -= previousSum;
		previousSum = number;
		greatestPower--;
		multiplier = previousSum / pow(HexNumbersParser::BASE, greatestPower);
	}

	return hex;
}