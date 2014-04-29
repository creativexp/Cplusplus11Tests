// C++11_Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <memory>
#include <cassert>


#include "OverrideFinalExample.h"
#include "SmartPointerTest.h"


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

	//  actual lamba return type
	int iLambaInput = 50;
	std::function<bool(int)> func1 = [](int iLambaInput){ return iLambaInput < 42; };
	//  call the function
	func1(iLambaInput);

	//  easier way to write it
	auto func2 = [](int iLambaInput){ return iLambaInput < 42; };
	//  call the function
	func2(iLambaInput);

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

	//  shared_ptr

	//  Notes: created using two allocations 1) new int 2) shared_ptr<int>
	//  could cause memory leak as the order of evaluation of parameters is unspecified in C++
	std::shared_ptr<int> pSharedInt( new int(10) );

	//  Notes: undefined behaviour. must use the copy or assign 
	//  uncomment to cause crash
	//  std::shared_ptr<int> pSharedIntUndef( pSharedInt.get() );
	
	//  ok
	std::shared_ptr<int> pSharedDef( pSharedInt );
	std::shared_ptr<int> pSharedDef2 = pSharedInt;

	//  Notes: created using one memory allocation
	std::shared_ptr<int> pSharedIntInt2 = std::make_shared<int>(10);



	//  weak ptr

	{

		//  Cyclic Redundancy
		//  this will leak memmory.
		//  two shared pointer references are made. 1) make_shared 2) within ->Set( 
		//  the second shared ptr reference will not be uncounted leading 
		//  to the CCyclicSmartPointerTest object not be deleted
		//  ~CCyclicSmartPointerTest() will not get called
		std::shared_ptr<CCyclicSharedPointerTest> pCycSmtPtr = std::make_shared<CCyclicSharedPointerTest>();
		assert(pCycSmtPtr);
		if (pCycSmtPtr) {
			pCycSmtPtr->Set(pCycSmtPtr);
		}

		//  Raw pointer test. this will not leak memory 
		CCyclicPointerTest* pCycPtr = new CCyclicPointerTest();
		assert(pCycPtr);
		if (pCycPtr) {
			pCycPtr->Set(pCycPtr);
			delete pCycPtr;
			pCycPtr = 0;
		}

		//  solution
		//  use weak pointers
		//  breaks strong cyclic reference
		std::shared_ptr<CCyclicSharedPointerSolution> pCycSmtPtrSol = std::make_shared<CCyclicSharedPointerSolution>();
		assert(pCycSmtPtrSol);
		if (pCycSmtPtrSol) {
			pCycSmtPtrSol->Set(pCycSmtPtrSol);
		}
	}
	
	
	//  empty unique pointer
	std::unique_ptr<int> pUnique1 = nullptr;

	//  new scope
	{
		//  unique pointer
		std::unique_ptr<int> pUnique2(new int() );
		assert( pUnique2 );
		if (pUnique2) {
			//  assign to external unique pointer
			pUnique1 = std::move(pUnique2);
		}
	}

	//  pUnique1 now owns the memory that was pointed to by pUnique2
	//  pUnique1 will free memory when it leaves this scope

	return 0;
}

