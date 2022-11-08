// MemoryManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Foo.h"
#include "MemoryDebugger.h"

using namespace std;
int main()
{
	//HeapManager::InitializeHeaps();

	Foo* foo = new (Identificator::Graphics) Foo(24);
	Foo* foo2 = new Foo(12);
	foo->AMethod();

	Header* fooHead = GetHeaderPntr(foo);
	Header* heapHead = GetHeaderPntr(HeapManager::GetHeapByIndex(0));

	HeapManager::CleanUp();
}

