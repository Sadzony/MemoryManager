#include "MemoryDebugger.h"

//void* operator new(size_t size)
//{
//    std::cout << "New override!" << std::endl;
//
//    size_t nRequestedBytes = size + sizeof(Header) + sizeof(Footer); //requested size plus the size of header and footer
//    char* pMem = (char*)malloc(nRequestedBytes); //allocate memory + header and footer
//
//    Header* pHeader = (Header*)pMem; //header pointer is at the start of memory block
//    pHeader->dataSize = size; //value of size in header equal to size of requested data 
//    pHeader->identificator = 21;
//
//    void* pFooterAddress = pMem + sizeof(Header) + size; //address of footer is past the header data and variable data
//    Footer* pFooter = (Footer*)pFooterAddress;
//    pFooter->identificator = 10;
//
//    void* pStartMemBlock = pMem + sizeof(Header);
//    return pStartMemBlock;
//}
//
//void operator delete(void* pMem)
//{
//    std::cout << "delete override!" << std::endl;
//    Header* pHeader = (Header*)((char*)pMem - sizeof(Header));
//    Footer* pFooter = (Footer*)((char*)pMem + pHeader->dataSize);
//
//    free(pHeader);
//}


std::vector<HeapManager::MemoryHeap*> HeapManager::active_heaps;
void HeapManager::InitializeHeaps()
{
    MemoryHeap* defaultHeap = new MemoryHeap();
    HeapManager::active_heaps.push_back(defaultHeap);
}
void HeapManager::CleanUp() 
{
    for (MemoryHeap* heap : HeapManager::active_heaps)
    {
        delete heap;
    }
    HeapManager::active_heaps.clear();
}






Header* GetHeaderPntr(void* pntr)
{
    return (Header*)((char*)pntr - sizeof(Header));
}

Footer* GetFooterPntr(void* pntr)
{
    Header* pHeader = GetHeaderPntr(pntr);
    return (Footer*)((char*)pntr + pHeader->dataSize);;
}





