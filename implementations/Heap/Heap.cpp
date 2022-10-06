
#include "Heap.h"

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>::Heap ( int maxNumber = DEFAULT_MAX_HEAP_SIZE )
{
	size = 0;
	maxSize = maxNumber;
	
	dataItems = new DataType[maxSize];
}

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>::Heap ( const Heap& other )
{
	maxSize = other->maxNumber;
	size = 0;
	dataItems = new DataType[maxSize];
	for (auto& x : other->dataItems) {
		dataItems[size+=1] = x;
	}
}

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>& Heap<DataType,KeyType,Comparator>::operator= ( const Heap& other )
{
	delete dataItems;  // remove the dataItem
	maxSize = other->maxSize;
	size = 0;  // assign size to zero
	dataItems = new DataType[maxSize];
	for (auto& x : other->dataItems) {
		dataItems[size+=1] = x;
	}
	return *this;
}

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType,KeyType,Comparator>::~Heap ()
{

	delete[] dataItems;
}

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType,KeyType,Comparator>::insert ( const DataType &newDataItem )
    throw ( logic_error )
{
	if (isFull()==true) { 
		throw logic_error("Heap is not empty"); 
	}
	dataItems[size] = newDataItem;
	int cI = size;
	int pI = ((cI + 1) / 2) - 1;
	DataType pakadvavadu; // it holds
	while (cI != 0 && comparator(dataItems[cI].getPriority(), dataItems[pI].getPriority())) {
		pakadvavadu = dataItems[pI];
		dataItems[pI] = dataItems[cI];
		dataItems[cI] = pakadvavadu; 
		cI = pI; // current index is parent index
		pI = ((cI + 1) / 2) - 1;
	}
	size+=1; // increment size by one 


}

template < typename DataType, typename KeyType, typename Comparator >
DataType Heap<DataType,KeyType,Comparator>::remove () throw ( logic_error )
{
	if (isEmpty()==true) { 
		throw logic_error("Heap is not full"); 
	}
	DataType prime, pI, nanoChild;
	int pI, lCI, rCI;

	prime = dataItems[0];
	dataItems[0] = pI = dataItems[--size];

	pI = 0;
	lCI = ((pI + 1) * 2) - 1;
	rCI = lCI + 1;

	while (comparator(dataItems[lCI].getPriority(), pI.getPriority()) || comparator(dataItems[rCI].getPriority(), pI.getPriority())) {
		if (comparator(dataItems[lCI].getPriority(), dataItems[rCI].getPriority())) {
			nanoChild = dataItems[lCI];
			dataItems[lCI] = pI;
			dataItems[pI] = nanoChild;
			pI = lCI;
		}else {
			nanoChild = dataItems[rCI];
			dataItems[rCI] = pI;
			dataItems[pI] = nanoChild;
			pI = rCI;
		}
		lCI = ((pI + 1) * 2) - 1;
		rCI = lCI + 1;
		if (rCI >= size || lCI >= size) { 
			break; 
		}
	}
	return prime;
}

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType,KeyType,Comparator>::clear ()
{
	delete[] dataItems;
	dataItems = new DataType[maxSize];
	size = 0;
}

template < typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType,KeyType,Comparator>::isEmpty () const
{
	if (size == 0)
		return true;
	else
		return false;
}

template < typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType,KeyType,Comparator>::isFull () const
{
	if (size == maxSize - 1)
		return true;
	else
		return false;
}

template<typename DataType, typename KeyType, typename Comparator>
void Heap<DataType, KeyType, Comparator>::writeLevels() const
{
	int stages;
	int rightNowStage;
	int z;
	stages = size / 2;
	rightNowStage = 1;
	z = 0;
	while (z < size) {
		int fNL = ((z + 1) * 2);
		while (z < fNL - 1) {
			if (z == size)
				break;
			cout << dataItems[z].getPriority() << " "<<endl;
			z+=1;
		}
		rightNowStage+=1;
	}
}

#include "show11.cpp"