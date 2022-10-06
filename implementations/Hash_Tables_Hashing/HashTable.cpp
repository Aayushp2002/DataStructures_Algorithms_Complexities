
#include "HashTable.h"

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize)
{
	tableSize = initTableSize;
	dataTable = new BSTree<DataType, KeyType>[tableSize];
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable& other)
{
	tableSize = other.tableSize;
	dataTable = new BSTree<T, KeyType>[tableSize];
	copyTable(other);
}

template <typename DataType, typename KeyType>
HashTable<DataType,KeyType>& HashTable<DataType, KeyType>::operator=(const HashTable& other)
{
	clear();
	copyTable(other);
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable()
{
	clear();
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem)
{
	int x = DataType::hash(newDataItem.getKey()) % tableSize;
	dataTable[x].insert(newDataItem);
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& deleteKey)
{
	int x = DataType::hash(deleteKey) % tableSize;
	if (dataTable[x].remove(deleteKey))
		return true;
	else
		return false;
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const
{
	int x = DataType::hash(searchKey) % tableSize;
	if (dataTable[x].retrieve(searchKey, returnItem))
		return true;
	else
		return false;
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear()
{
	for (int x = 0; x < tableSize; x+=1) {
		if (!dataTable[x].isEmpty()) {
			dataTable[x].clear();
		}
	}
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const
{
	for (int x = 0; x < tableSize; x+=1) {
		if (!dataTable[x].isEmpty()) {
			return false;
		}
	}
	return true;
}

#include "show10.cpp"

template <typename DataType, typename KeyType>
double HashTable<DataType, KeyType>::standardDeviation() const
{
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source)
{
}
