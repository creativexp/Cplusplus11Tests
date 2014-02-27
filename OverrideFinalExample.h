#ifndef H_OVERRIDEFINALEXAMPLE_H
#define H_OVERRIDEFINALEXAMPLE_H


class CClassA
{
public:
	virtual void TestOverideKeyWord(short& i) { i++;  }
	virtual void TestFinalKeyWord(short& i) { i++; }
};


class CClassB : public CClassA
{
public:
	virtual void TestOverideKeyWord(short& i) override { --i; }  //  correct

	//  error as function has different parameter type 
	//  function is being overloaded not overriden
	//  so the override keyword triggers a compiler error
	//virtual void TestOverideKeyWord(int& i) override { --i; }  

	virtual void TestFinalKeyWord(short& i) override final { --i; }
};


class CClassC : public CClassB
{
public:
	//  complier error is triggered because ClassC is trying to override a function
	//  that is not allowed to be overriden
	//  the final keyword is used to signal this to the complier
	//virtual void TestFinalKeyWord(short& i) override { --i; }

};


#endif