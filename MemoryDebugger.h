#pragma once
#include <iostream>
#include <vector>


//heap definitions
class MemoryHeap
{
public:
	static MemoryHeap* CreateHeap();

	int curBytesAllocated = 0;
	std::vector<void*> heap;
};

class HeapManager
{
//static methods
public:
	static void InitializeHeaps();
	static void CleanUp();

	//static void AddToHeap(MemoryHeap* heap, Header* info);
	//static void AddToHeap(int heapIndex, Header* info);
	//static void RemoveFromHeap(MemoryHeap* heap, Header* info);
	//static void RemoveFromHeap(int heapIndex, Header* info);
	static std::vector<MemoryHeap*>* GetActiveHeaps() { return &active_heaps; }
protected:
	static std::vector<MemoryHeap*> active_heaps;
};



//Header and footer structs for identifying allocated memory
struct Header {
	int dataSize;
	int identificator;
	MemoryHeap* m_heap;
};
struct Footer {
	int reserved;
	int identificator;
};

//global new and delete overrides
//void* operator new (size_t size);
void operator delete (void* pMem);

//get footer and get header
Header* GetHeaderPntr(void* pntr);
Footer* GetFooterPntr(void* pntr);