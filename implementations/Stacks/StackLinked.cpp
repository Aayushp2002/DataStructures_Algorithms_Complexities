// Aayush Patel
#include "StackLinked.h"

template <typename DataType>
StackLinked<DataType>::StackLinked (int maxNumber)
{
	top = NULL;
}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
	(void) operator=(other); // need
}

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
	if (this != &other) 
		return *this;
	clear();				
	if (other.isEmpty()==false) {
		
		top = new StackNode(other.top->dataItem, 0);
		StackNode* ot = other.top->next;
		StackNode* tt = 0, * thisPrevious = top;

		
		while (ot != 0){
			tt = new StackNode(ot->dataItem, 0);
			thisPrevious->next = 0;
			thisPrevious = top->next;
			ot = top;
		}
	}

	return *this;
}

template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
	clear();
}

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
	StackNode* t = new StackNode ( newDataItem, top);
	top = t;
}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
	DataType d = top->dataItem;
	StackNode* t = top;
	top = top->next;
	delete t;
	return d;
}

template <typename DataType>
void StackLinked<DataType>::clear()
{
	StackNode* t;
	while ( top != NULL)
	{
		t = top;
		top = top->next;
		delete t;
	}
}

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
	return (top == NULL);
}

template <typename DataType>
bool StackLinked<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const
{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << "[" << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }

}