#include <string>
#include <iostream>

#pragma once
#ifndef HELPERS_H
#define HELPERS_H

class Helpers
{
public:
	static int numberSize(std::int64_t, int);
	
	static char* toCharArray(const std::string);
};

#endif