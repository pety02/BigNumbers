#include "HexaNumbersParser.h"

int HexaNumbersParser::findGeatestPower(long n, int base = 16)
{
	int power = 0;
	while (n >= base)
	{
		power++;
		n /= base;
	}

	return power;
}

long HexaNumbersParser::hexaToNumber(const char* hex, int base)
{
	std::string s = hex;
	int power = s.length() - 1;
	long number = 0;
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

std::string HexaNumbersParser::numberToHexa(long n, int base = 16)
{
	std::string hex = "";
	int greatestPower = findGeatestPower(n);

	int multiplier = n / pow(base, greatestPower);
	while (n / 16 >= 0 && n)
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

		long prevSum = multiplier * pow(base, greatestPower);
		n -= prevSum;
		prevSum = n;
		greatestPower--;
		multiplier = prevSum / pow(base, greatestPower);
	}

	return hex;
}