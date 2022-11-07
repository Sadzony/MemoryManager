#pragma once
#include <iostream>
#include <vector>

//Header and footer structs for identifying allocated memory
struct Header {
	int dataSize;
	int identificator;
};
struct Footer {
	int reserved;
	int identificator;
};

//global new and delete overrides
//void* operator new (size_t size);
//void operator delete (void* pMem);

//forward declaration of the private class
class MemoryHeap;

class HeapManager
{
//heap definitions
private:
	class MemoryHeap
	{
	public:
		MemoryHeap() { ; }
		~MemoryHeap() { ; }
	protected:
		int curBytesAllocated = 0;
		std::vector<void*> heap;
	};

//static data and static methods
public:
	static void InitializeHeaps();
	static void CleanUp();

	static void AddToHeap(MemoryHeap* heap, Header* info);
	static void AddToHeap(int heapIndex, Header* info);
	static void RemoveFromHeap(MemoryHeap* heap, Header* info);
	static void RemoveFromHeap(int heapIndex, Header* info);

	//heap specific new and delete overrides
	//static void* operator new (size_t size);
	//static void operator delete (void* pMem);
protected:
	static std::vector<MemoryHeap*> active_heaps;
};

//get footer and get header
Header* GetHeaderPntr(void* pntr);
Footer* GetFooterPntr(void* pntr);

