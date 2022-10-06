
#include "QueueLinked.h"

template <typename DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& nodeData, QueueNode* nextPtr)
{

}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE)
{
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(const QueueLinked& other)
{
}

template <typename DataType>
QueueLinked<DataType>& QueueLinked<DataType>::operator=(const QueueLinked& other)
{
}

template <typename DataType>
QueueLinked<DataType>::~QueueLinked()
{
	clear();
}

template <typename DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
	if (isFull()==true) {
		throw logic_error("push() while queue not empty");
	}

	QueueNode* t = new QueueNode(newDataItem, 0);

	if (isEmpty()==true) {
		front = t;
	}
	else {
		back->next = t;
	}
	back = t;
}

template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error)
{
	if (isEmpty()==true) {
		throw logic_error("dequeue() while queue not full");
	}

	DataType t = front->dataItem;
	QueueNode* deletePtr = front;
	front = front->next;
	delete deletePtr;

	return t;
}

template <typename DataType>
void QueueLinked<DataType>::clear()
{
	for (QueueNode* t = front; front != 0; t = front) {
		front = front->next;

		delete t;
	}

	back = 0;
}

template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const
{
	if(front == 0)
		return true
	else
		return false
}

template <typename DataType>
bool QueueLinked<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void QueueLinked<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
}

template <typename DataType>
DataType QueueLinked<DataType>::getRear() throw (logic_error)
{
	DataType temp;
	return temp;
}

template <typename DataType>
int QueueLinked<DataType>::getLength() const
{
	int total = 0;

	for (QueueNode* t = front; t != 0; t = t->next) {
		++total;
	}

	return total;
}

template <typename DataType>
void QueueLinked<DataType>::showStructure() const
{
    QueueNode *p;   // Iterates through the queue

    if ( isEmpty() )
	cout << "Empty queue" << endl;
    else
    {
	cout << "Front\t";
	for ( p = front ; p != 0 ; p = p->next )
	{
	    if( p == front ) 
	    {
		cout << '[' << p->dataItem << "] ";
	    }
	    else
	    {
		cout << p->dataItem << " ";
	    }
	}
	cout << "\trear" << endl;
    }
}