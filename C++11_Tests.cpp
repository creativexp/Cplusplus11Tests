// C++11_Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>


#include "OverrideFinalExample.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//  intialiser list
	std::vector<std::string> aNames = { "Name1", "Name2", "Name3" };

	//  auto keyword
	//  range-for statement
	for (const auto& name : aNames) {
		for (const auto& c : name) {
			std::cout << c << std::endl;
		}
	}

	//  nullptr
	int* pIntPtr = nullptr; 
	bool bTestBool = nullptr;  //  can be used on bools, translates to false
	//  int iTestInt = nullptr;  //  error cant be used for integrals


	//  lamda
	std::vector<int> v = { 50, -10, 20, -30 };

	std::sort(v.begin(), v.end());	// the default sort
	// now v should be { -30, -10, 20, 50 }

	// sort by absolute value:
	std::sort(v.begin(), v.end(), [](int a, int b) { return abs(a)<abs(b); });
	// now v should be { -10, 20, -30, 50 }

	return 0;
}

