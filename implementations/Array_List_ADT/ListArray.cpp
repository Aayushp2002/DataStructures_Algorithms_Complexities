
#include "ListArray.h"

template < typename DataType >
List<DataType>::List ( int maxNumber )
{
	size = 0;
	maxSize = maxNumber;
	dataItems = new DataType[maxSize];
	for (int j = 0; j < maxSize; j++) {
		dataItems[j] = NULL;}
	
}

template < typename DataType >
List<DataType>::List ( const List& source )
{
	size = source.size;
	maxSize = source.maxSize;
	cursor = source.cursor;
	delete[] dataItems;
	dataItems = new DataType[maxSize];
	for (int i = 0; i <= maxSize; i++) {
		if (source.dataItems[i] != NULL)
			dataItems[i] = source.dataItems[i];
		else
			dataItems[i] = NULL;
	}

}
    
template < typename DataType >
List<DataType>& List<DataType>::operator= ( const List& source )
{
	if (maxSize < source.size) {
		delete[] dataItems;
		maxSize = source.size;

		dataItems = new DataType[maxSize];
	}

	for (int j = 0; j <= maxSize; j++) {



		if (source.dataItems[j] != NULL) {

			dataItems[j] = source.dataItems[j];

		}
		else {
			dataItems[j] = NULL;
		}
	}
	return *this;
}

template < typename DataType >
List<DataType>::~List ()
{
	delete[] dataItems;
}

template < typename DataType >
void List<DataType>::insert ( const DataType& newDataItem )
	throw ( logic_error )
{
	// try catch
	try {
		if (size == maxSize)
			throw 0;
		else {
			if (size == 0)
				dataItems[0] = newDataItem;
			else if(size!=0)
				dataItems[cursor + 1] = newDataItem;


			cursor++;
			size++;

				

		}
	}catch(int z){
		cout << "error: " << z << "List is not full" << endl;
	}
}

template < typename DataType >
void List<DataType>::remove () throw ( logic_error )
{
	try {
		if (size != 0) {
			dataItems[cursor] = NULL;
			cursor -= 1;
			size -= 1;
		}
		else if (size == 0) {
			throw 0;
		}
	}
	catch (int z) {
		cout << "error: " << z << "List is not full" << endl;
	}
}

template < typename DataType >
void List<DataType>::replace ( const DataType& newDataItem )
	throw ( logic_error )
{

	try {
		if (size != 0) {
			dataItems[cursor] = newDataItem;
		}
		else if (size == 0) {
			throw 0;
		}
	}
	catch(int z){
		cout << "error: " << z << "List is not full" << endl;
	}
}

template < typename DataType >
void List<DataType>::clear ()
{
	for (int j = 0; j < size; j++) {
		if (dataItems[j] != NULL) {
			dataItems[j] == NULL;
		}
		// cursor and size to zero
		cursor = 0;
		size = 0;
	}
}

template < typename DataType >
bool List<DataType>::isEmpty () const
{
	return size==0;
}

template < typename DataType >
bool List<DataType>::isFull () const
{
	return size==maxSize;
}

template < typename DataType >
void List<DataType>::gotoBeginning ()
        throw ( logic_error )
{

	try {
		if (size != 0) {
			cursor = 0;
		}
		else if (size == 0) {
			throw 0;
		}
	}
	catch (int z) {
		cout << "error: " << z << "List is not full" << endl;
	}
}

template < typename DataType >
void List<DataType>::gotoEnd ()
        throw ( logic_error )
{

	try {
		if (size != 0) {
			cursor = size - 1;
		}
		else if (size == 0) {
			throw 0;
		}
	}
	catch (int z) {
		cout << "error: " << z << "List is not full" << endl;
	}
}

template < typename DataType >
bool List<DataType>::gotoNext ()
        throw ( logic_error )
{
	try {
		if (size != 0) {
			if (cursor == size - 1) {
				return false;
			}
			else {
				return true;
			}
		}
		else if (size == 0) {
			throw 0;
		}
	}
	catch (int z) {
		cout << "error: " << z << "List is not full" << endl;
	}
}

template < typename DataType >
bool List<DataType>::gotoPrior ()
        throw ( logic_error )
{
	try {
		if (size != 0) {
			if (cursor == 0) {
				return false;
			}
			else {
				return true;
			}
		}
		else if (size == 0) {
			throw 0;
		}
	}
	catch (int z) {
		cout << "error: " << z << "List is not full" << endl;
	}
}

template < typename DataType >
DataType List<DataType>::getCursor () const
        throw ( logic_error )
{
	try {
		if (size == 0) {
			throw 0;
		}
		else {
			return dataItems[cursor];
		}
	}
	catch(int z){
		cout << "error: " << z << "List is not full" << endl;
	}
}

#include "show3.cpp"

template < typename DataType >
void List<DataType>::moveToNth ( int n )
        throw ( logic_error )
{
	try {
		if (size == 0) {
			throw 0;
		}
		else if (n<size || n>size) {
			throw 1;
		}
		else {
			cursor = n;;
		}
	}
	catch (int z) {
		if (z == 1) {
			cout << "error: " << z << "List is not full" << endl;
		}
		else if (z == 0) {
			cout << "error: " << z << "e is off limits" << endl;
		}
	}
}

template < typename DataType >
bool List<DataType>::find ( const DataType& searchDataItem )
        throw ( logic_error )
{
	try {
		if (size == 0) {
			throw 0;
		}
		else {
			bool gotIt = false;
			for (int j = 0; j < size; j++) {
				if (dataItems[j] == searchDataItem) {
					gotIt == true;
				}
			}
			return gotIt;
		}
	}
	catch (int z) {
		cout << "error: " << z << "List is not full" << endl;
	}
}