// MemoryManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Foo.h"
#include "MemoryDebugger.h"

using namespace std;
int main()
{
	HeapManager::InitializeHeaps();


	HeapManager::CleanUp();
}

