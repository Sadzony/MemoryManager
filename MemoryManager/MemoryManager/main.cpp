// MemoryManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Foo.h"
#include "MemoryDebugger.h"

using namespace std;
int main()
{

	Foo* foo = new Foo(24);
	Foo* foo2 = new Foo(12);
#ifdef _DEBUG
	HeapManager::GetHeapByIndex(1)->WalkTheHeap();
	HeapManager::CleanUp();
#endif // DEBUG
}

