#pragma once
#include <iostream>

#include "MemoryDebugger.h"

class Foo
{
public:
	Foo() { m_int = 0; std::cout << "Constructor!" << std::endl; }
	Foo(int p_int) { m_int = p_int; std::cout << "Constructor!" << std::endl; }
	~Foo() { std::cout << "Destructor!" << std::endl; }
	void AMethod() { std::cout << "Hello From Foo!" << " My int is " << m_int << std::endl; }
	int GetInt() { return m_int; }
private:
	int m_int;

#ifdef _DEBUG
	//new and delete overrides
public:
	static void* operator new (size_t size) { return ::operator new(size, HeapID::Graphics); }
	static void operator delete(void* p, size_t size) { ::operator delete(p); }
#endif
};

