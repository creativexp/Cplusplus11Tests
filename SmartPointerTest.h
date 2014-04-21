#ifndef H_SMARTPOINTERTEST_H
#define H_SMARTPOINTERTEST_H


class CSmartPointerTestB;

class CCyclicPointerTest
{
	CCyclicPointerTest* m_pPtr;

public:
	CCyclicPointerTest() : m_pPtr(0) {}
	~CCyclicPointerTest() { std::cout << "~CCyclicPointerTest"; }

	void Set(CCyclicPointerTest* ptr) { m_pPtr = ptr; }
};

class CCyclicSharedPointerTest
{
	std::shared_ptr<CCyclicSharedPointerTest> m_pPtr;

public:
	CCyclicSharedPointerTest() : m_pPtr() {}
	~CCyclicSharedPointerTest() { std::cout << "~CCyclicSharedPointerTest"; }


	void Set(std::shared_ptr<CCyclicSharedPointerTest> ptr) { m_pPtr = ptr; }
};

class CCyclicSharedPointerSolution
{
	std::weak_ptr<CCyclicSharedPointerSolution> m_pPtr;

public:
	CCyclicSharedPointerSolution() : m_pPtr() {}
	~CCyclicSharedPointerSolution() { std::cout << "~CCyclicSharedPointerSolution"; }


	void Set(std::shared_ptr<CCyclicSharedPointerSolution> ptr) { m_pPtr = ptr; }
};


#endif