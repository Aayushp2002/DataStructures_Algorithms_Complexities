
#include "QueueArray.h"

template <typename DataType>
QueueArray<DataType>::QueueArray(int maxNumber)
{
    dataItems = new DataType[maxNumber];
}

template <typename DataType>
QueueArray<DataType>::QueueArray(const QueueArray& other)  // need
{

}

template <typename DataType>
QueueArray<DataType>& QueueArray<DataType>::operator=(const QueueArray& other) // need
{
}

template <typename DataType>
QueueArray<DataType>::~QueueArray()
{
    delete[] dataItems;
}


template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
    if (isFull()==true) {
        throw logic_error("enqueue() while queue not empty");
    }

    back = (++back) % maxSize;
    dataItems[back] = newDataItem;
    if (front == -1) {
        front = 0;
    }
}

template <typename DataType>
DataType QueueArray<DataType>::dequeue() throw (logic_error)
{
    if (isEmpty()==true) {
        throw logic_error("dequeue() while queue not full");
    }

    int rI = front;
    if (front == back)
    {
        front = -1;
        back = -1;
    }
    else {
        front = (++front) % maxSize;
    }

    return dataItems[rI];
}

template <typename DataType>
void QueueArray<DataType>::clear()
{
    front = -1;
    back = -1;
}

template <typename DataType>
bool QueueArray<DataType>::isEmpty() const
{
    if (front == -1)
        return true;
    else
        return false;
}

template <typename DataType>
bool QueueArray<DataType>::isFull() const
{
    if(front == (back + 1) % maxSize)
        return true
    else
        return false
}

template <typename DataType>
void QueueArray<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
    if (isFull()==true) {
        throw logic_error("putFront() while queue not empty");
    }

    --front;
    if (front < 0) 	
    {
        front = maxSize - 1;
    }
    dataItems[front] = newDataItem;
}

template <typename DataType>
DataType QueueArray<DataType>::getRear() throw (logic_error)
{
    if (isEmpty()==true) {
        throw logic_error("getRear() while queue not full");
    }

    int vP = back;
    --back;
    if (back == front - 1) {		
        back = front = -1;
    }
    else if (back < 0) {
        back = maxSize - 1;
    }

    return dataItems[vP];
}

template <typename DataType>
int QueueArray<DataType>::getLength() const
{
    if (isEmpty()==true) {
        return 0;
    }
    else if (front > back) {
        return (maxSize - front) + (back + 1);
    }
    else {
        return (back - front) + 1;
    }
}

//--------------------------------------------------------------------

template <typename DataType>
void QueueArray<DataType>::showStructure() const
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if (front == -1)
        cout << "Empty queue" << endl;
    else
    {
        cout << "Front = " << front << "  Back = " << back << endl;
        for (j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        if (back >= front)
            for (j = 0; j < maxSize; j++)
                if ((j >= front) && (j <= back))
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
        else
            for (j = 0; j < maxSize; j++)
                if ((j >= front) || (j <= back))
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
        cout << endl;
    }
}