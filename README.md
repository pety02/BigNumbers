# BigNumbers

## Task

Creating C++ Console Application of calculating Big Numbers 
for decimal and hexadecimal numbers. Project for Data Structure 
course in the university.

## Brief description

This calculator should can calculate very long numbers with more than 
255 characters, so for that aim I used std::string type and calculations
by different algorithms.

## Supported Counting Systems
  
  1. Decimals
  2. Hexadecimals

## Functionalitites
  
  1. Sum - summing char by char
  2. Substraction - substracting char by char
  3. Multiplication - multiplying char by char whit extra variable incrementing 
                      when we need it
  4. Devision - substracting multiple times the smaller number from the bigger 
                one and counting repeations of this algorith while thier substraction 
                is bigger than zero.
  5. Devision with qutient and reminder - using devision algorithm and applying this formula
                                          reminder = number - (counter * quotient)

## Developing decisions

Firstly, I wanted to work with numeric data types wich to convert to strd::string after calculations,
but this was bad decision because of excluding calculations with really long numbers and loss of accuracy.
Then, I decided to work with chars, but  working with std::string becouse of the convinience and made it so.

For the application I decidet to create a class BigNumber in which to store the data of these type numbers, such as:
  
  * value - std::string
  * type - NumberType (enumerator with two options - DECIMAL and HEXA, which will tell the program how to cqalculate 
           the numbers)

## Literature
 
 1. https://www.geeksforgeeks.org - ideas for implementing calculations
 2. https://stackoverflow.com - ideas for logic mistakes corrections
  
