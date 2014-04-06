// C++11_Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>


#include "OverrideFinalExample.h"


//  static assert
/*
template<class T>
void f(T vim){
	static_assert(sizeof(vim) == 4, "vim must have size of 4 bytes");
	//do something with v 
}
*/

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


	//  raw string literals
	//  Notes: easier way to add line breaks and 
	//  write paths without double backslash
	std::string test = R"( line one
                           line two
                           line three )";

	printf("%s \n", test.c_str());


	//  member class intialiser
	//  Notes: being able to intialise a member variable directly
	//  without having to use constructors
	class CMemberClassIntializer
	{
		int m_iNum = 5;
		std::string m_strName = "Name";
	};


	//  delegating constructors
	//  Notes: being able to call another constructor in the intialiser list of a constructor
	class CDelegatingConstructors
	{
		int m_iNum;
	public:
		CDelegatingConstructors() : CDelegatingConstructors(100) {}
		CDelegatingConstructors(const int iNum) : m_iNum(iNum) {}

	};


	/*
	//  static assert
	//  Notes: check at compile time validity of template generated code
	long long iVim = 50; // 8 bytes
	f(iVim);
	*/


	//  decltype
	//  Notes: used to determine the type of an expression
	{
		int iVar = 0;
		decltype(iVar) iVar2 = 0;  //  iVar2 will be type int

	}

	return 0;
}

