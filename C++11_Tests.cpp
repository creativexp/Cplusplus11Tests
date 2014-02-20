// C++11_Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	//  intialiser list
	std::vector<std::string> aNames = { "Paul", "Chad", "Tracy" };

	//  auto keyword
	//  range-for statement
	for (const auto& name : aNames) {
		for (const auto& c : name) {
			std::cout << c << std::endl;
		}
	}

	return 0;
}

