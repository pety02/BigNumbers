#include "BigNumber.h"

void BigNumber::setNumberTypeAndBase(std::string numberAsString)
{
	try
	{
		if (InputValidator::isValidDecimal(numberAsString))
		{
			number = numberAsString;
			type = NumberType::DECIMAL;
			base = 10;
			return;
		}
	
		if (InputValidator::isValidHex(numberAsString))
		{
			number = numberAsString;
			type = NumberType::HEX;
			base = 16;
			return;
		}
		
		throw std::invalid_argument("Invalid number as string!");
	}
	catch (std::invalid_argument)
	{
		number = "0";
		type = NumberType::DECIMAL;
		base = 10;
	}
}

char BigNumber::getSymbol(int num) {
	switch (num) {
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';

	case 10: return 'A';
	case 11: return 'B';
	case 12: return 'C';
	case 13: return 'D';
	case 14: return 'E';
	case 15: return 'F';

	default: throw "Not valid value";
	}
}

int BigNumber::getValue(char ch) {
	switch (ch) {
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;

	case 'A': return 10;
	case 'B': return 11;
	case 'C': return 12;
	case 'D': return 13;
	case 'E': return 14;
	case 'F': return 15;

	default: throw "Not valid symbol";
	}
}

bool BigNumber::isSmaller(std::string fstNumberString, std::string sndNumberString)
{
	int fstNumberLength = fstNumberString.length(),
		sndNumberLength = sndNumberString.length();

	if (fstNumberLength < sndNumberLength) {
		return true;
	}
	if (sndNumberLength < fstNumberLength) {
		return false;
	}

	for (size_t fstNumberIndex = 0; fstNumberIndex < fstNumberLength; fstNumberIndex++) {
		if (fstNumberString[fstNumberIndex] < sndNumberString[fstNumberIndex]) {
			return true;
		}
		else if (fstNumberString[fstNumberIndex] > sndNumberString[fstNumberIndex]) {
			return false;
		}
	}

	return false;
}

bool BigNumber::areSame(std::string str1, std::string str2) {
	bool areIdentical = true;
	if (str1.length() != str2.length()) {
		areIdentical = false;
	}
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] != str2[i]) {
			areIdentical = false;
			break;
		}
	}

	return areIdentical;
}

BigNumber::BigNumber()
{
	setNumberTypeAndBase("0");
}

BigNumber::BigNumber(std::string numberAsString)
{
	setNumberTypeAndBase(numberAsString);
}

void BigNumber::operator>>(std::istream& input)
{
	if (input.good()) 
	{
		std::string numberAsString;
		input >> numberAsString;
		
		setNumberTypeAndBase(numberAsString);
	}
}

void BigNumber::operator <<(std::ostream& output)
{
	if (output.good()) 
	{
		output << this->number << '\n';
	}
}

BigNumber& BigNumber::operator=(const BigNumber& otherNumber)
{
	if (this != nullptr) 
	{
		setNumberTypeAndBase(otherNumber.number);
	}

	return *this;
}

BigNumber& BigNumber::operator+(BigNumber& sndCollectable)
{
	std::string smallerCollectable = number, 
		largerCollectable = sndCollectable.getNumber();
	size_t smallerCollectableLength = smallerCollectable.length(), 
		largerCollectableLength = largerCollectable.length();
	
	if (largerCollectableLength < smallerCollectableLength) {
		std::swap(smallerCollectable, largerCollectable);
	}

	std::reverse(smallerCollectable.begin(), smallerCollectable.end());
	std::reverse(largerCollectable.begin(), largerCollectable.end());

	std::string sum = "";
	int holder = 0, currentSum = 0;
	for (size_t smallerCollectableIndex = 0; smallerCollectableIndex < largerCollectableLength; smallerCollectableIndex++) {
		currentSum = getValue(smallerCollectable[smallerCollectableIndex]) 
			+ getValue(largerCollectable[smallerCollectableIndex]) + holder;
		sum.push_back(getSymbol(currentSum % base));
		std::cout << getValue(smallerCollectable[smallerCollectableIndex]);
		std::cout << getValue(largerCollectable[smallerCollectableIndex]);
		holder = currentSum / base;
	}

	for (size_t largerCollectableIndex = largerCollectableLength; largerCollectableIndex < smallerCollectableLength; largerCollectableIndex++)
	{
		currentSum = getValue(largerCollectable[largerCollectableIndex]) + holder;
		sum.push_back(getSymbol(currentSum % base));
		holder = currentSum / base;
	}

	if (holder) {
		sum.push_back(getSymbol(holder));
	}

	std::reverse(sum.begin(), sum.end());

	*this = BigNumber(sum);
	return *this;
}

BigNumber& BigNumber::operator-(BigNumber& diminutive)
{
	std::string difference = "";
	std::string _reducible = number, _diminutive = diminutive.getNumber();

	if (isSmaller(_reducible, _diminutive)) {
		swap(_reducible, _diminutive);
	}

	int reducibleLength = _reducible.length(), diminutiveLength = _diminutive.length();
	int lengthDifference = reducibleLength - diminutiveLength;

	//std::reverse(_reducible.begin(), _reducible.end());
	//std::reverse(_diminutive.begin(), _diminutive.end());

	int holder = 0, currentDiff = 0;
	for (size_t diminutiveLengthIndex = 0; diminutiveLengthIndex < diminutiveLength; diminutiveLengthIndex++) {

		currentDiff = (getValue(_reducible[diminutiveLengthIndex + lengthDifference]) 
			- getValue(_diminutive[diminutiveLengthIndex]) - holder);
		if (currentDiff < 0) {
			currentDiff = currentDiff + base;
			holder = 1;
		}
		else {
			holder = 0;
		}

		difference.push_back(getSymbol(currentDiff));
	}

	for (int reducibleIndex = reducibleLength - diminutiveLength - 1; reducibleIndex >= 0; reducibleIndex--) {
		if (_reducible[reducibleIndex] == '0' && holder) {
			difference.push_back(getSymbol(base - 1));
			continue;
		}
		currentDiff = (getValue(_reducible[reducibleIndex]) - holder);
		if (reducibleIndex > 0 || currentDiff > 0)
			difference.push_back(getSymbol(currentDiff));
		holder = 0;
	}

	std::reverse(difference.begin(), difference.end());

	int zeroesCounter = 0, firstNonZeroDigitIndex = -1;
	if (areSame(_reducible, _diminutive)) {
		*this = BigNumber();
	}

	for (size_t differenceIndex = 0; differenceIndex < difference.length(); differenceIndex++) {
		if (difference[differenceIndex] == '0')
		{
			zeroesCounter++;
		}
	}

	if (zeroesCounter > 1) {
		for (size_t differenceIndex = 0; differenceIndex < difference.length(); differenceIndex++) {
			if (difference[differenceIndex] != '0')
			{
				firstNonZeroDigitIndex = differenceIndex; 
				break;
			}
		}

		std::string differenceWithoutFrontZeroes = difference.substr(firstNonZeroDigitIndex, difference.length() - 1);
		*this = BigNumber(differenceWithoutFrontZeroes);
	}
	else {
		*this = BigNumber(difference); 
	}

	return *this;
}

BigNumber& BigNumber::operator*(BigNumber& sndMultiplier)
{
	std::string _fstMultiplier = number, _sndMultiplier = sndMultiplier.getNumber();
	int fstMultiplierLength = _fstMultiplier.size(), sndMultiplierLength = _sndMultiplier.size();
	if (fstMultiplierLength == 0 || sndMultiplierLength == 0) {
		*this = BigNumber(); 
		return *this;
	}

	std::vector<int> productVector(fstMultiplierLength + sndMultiplierLength, 0);
	size_t fstMultiplierPosIndex = 0, sndMultiplierPosIndex = 0;

	std::reverse(_fstMultiplier.begin(), _fstMultiplier.end());
	std::reverse(_sndMultiplier.begin(), _sndMultiplier.end());
	
	for (size_t fstMultiplierIndex = 0; fstMultiplierIndex < fstMultiplierLength; fstMultiplierIndex++)
	{
		int holder = 0;
		int fstMultiplierValue = getValue(_fstMultiplier[fstMultiplierIndex]);

		sndMultiplierPosIndex = 0;
         
		for (size_t sndMultiplierIndex = 0; sndMultiplierIndex < sndMultiplierLength; sndMultiplierIndex++)
		{
			int sndMultiplierValue = getValue(_sndMultiplier[sndMultiplierIndex]);
			size_t nextIndex = fstMultiplierPosIndex + sndMultiplierPosIndex;
			int currentSum = fstMultiplierValue * sndMultiplierValue + productVector[nextIndex] + holder;

			holder = currentSum / base;
			productVector[nextIndex] = currentSum % base;

			sndMultiplierPosIndex++;
		}

		if (holder > 0) {
			productVector[fstMultiplierPosIndex + sndMultiplierPosIndex] += holder;
		}

		fstMultiplierPosIndex++;
	}

	int productVectorIndex = productVector.size() - 1;
	while ( 0 <= productVectorIndex 
		&& productVector[productVectorIndex] == 0) {
		
		productVectorIndex--;
		if (productVectorIndex == -1) {
			*this = BigNumber(); return *this;
		}
	}
	
	std::string product = "";

	while (0 <= productVectorIndex) {
		product += getSymbol(productVector[productVectorIndex--]);
	}

	*this = BigNumber(product);
	return *this;
}

BigNumber& BigNumber::operator/(BigNumber& divisor) 
{
	std::string _divisible = number, _divisor = divisor.getNumber();
	if (_divisible.length() < _divisor.length()) {
		*this = BigNumber(); return *this;
	}

	int quotient = 0;
	BigNumber currentDivisible = BigNumber(_divisible);
	BigNumber currentDivisor = BigNumber(_divisor);

	BigNumber diff = currentDivisible;
	while (!isSmaller(diff.getNumber(), currentDivisor.getNumber())) {
		diff = diff - currentDivisor;
		quotient++;
	}

	std::string res = std::to_string(quotient);
	*this = BigNumber(res);
	return *this;
}

const BigNumber BigNumber::mod(BigNumber& divisor, BigNumber& reminder) const
{
	if (type == NumberType::DECIMAL && divisor.getType() == NumberType::DECIMAL)
	{
		std::int64_t _divisible = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(number));
		std::int64_t _divisor = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(divisor.getNumber()));

		reminder = (_divisible % _divisor != 0) ? BigNumber(DecimalNumbersParser::decimalToString(_divisible % _divisor))
			: BigNumber();
		return BigNumber(DecimalNumbersParser::decimalToString(_divisible / _divisor));
	}

	if ((type == NumberType::DECIMAL && divisor.getType() == NumberType::HEX)
		|| (type == NumberType::HEX && divisor.getType() == NumberType::DECIMAL)
		|| (type == NumberType::HEX && divisor.getType() == NumberType::HEX))
	{
		std::int64_t _divisible = HexNumbersParser::hexToDecimal(Helpers::toCharArray(number));
		std::int64_t _divisor = HexNumbersParser::hexToDecimal(Helpers::toCharArray(divisor.getNumber()));

		reminder = (_divisible % _divisor != 0) ? BigNumber(HexNumbersParser::decimalToHex(_divisible % _divisor))
			: BigNumber();
		return BigNumber(HexNumbersParser::decimalToHex(_divisible / _divisor));
	}

	throw std::invalid_argument("Invalid divisible and divisor!");
}

const BigNumber BigNumber::sqrt() const
{
	if (type == NumberType::DECIMAL)
	{
		std::int64_t _number = DecimalNumbersParser::stringToDecimal(Helpers::toCharArray(number));
		std::int64_t updatableSum = 0;
		std::int64_t heightestPowerOfFour = 1 << 30;

		while (heightestPowerOfFour > _number)
		{
			heightestPowerOfFour >>= 2;

			while (heightestPowerOfFour != 0) {
				if (_number >= updatableSum + heightestPowerOfFour) {
					_number -= updatableSum + heightestPowerOfFour;
					updatableSum = (updatableSum >> 1) + heightestPowerOfFour;
				}
				else {
					updatableSum >>= 1;
				}
				heightestPowerOfFour >>= 2;
			}
		}

		return BigNumber(DecimalNumbersParser::decimalToString(updatableSum));
	}

	if (type == NumberType::HEX)
	{
		std::int64_t _number = HexNumbersParser::hexToDecimal(Helpers::toCharArray(number));
		std::int64_t updatableSum = 0;
		std::int64_t heightestPowerOfFour = 1 << 30;

		while (heightestPowerOfFour > _number)
		{
			heightestPowerOfFour >>= 2;

			while (heightestPowerOfFour != 0) {
				if (_number >= updatableSum + heightestPowerOfFour) {
					_number -= updatableSum + heightestPowerOfFour;
					updatableSum = (updatableSum >> 1) + heightestPowerOfFour;
				}
				else {
					updatableSum >>= 1;
				}
				heightestPowerOfFour >>= 2;
			}
		}

		return BigNumber(HexNumbersParser::decimalToHex(updatableSum));
	}

	throw std::invalid_argument("Invalid number to be square rooted!");
}

const std::string BigNumber::getNumber() const
{
	return this->number;
}

const NumberType BigNumber::getType() const
{
	return this->type;
}

const int BigNumber::getBase() const
{
	return base;
}