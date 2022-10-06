
#include "ListLinked.h"

// ListNode member functions

template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr)
{
	this->dataItem = nodeData;
	this->next = nextPtr;
}

// List member functions

template <typename DataType>
List<DataType>::List(int ignored = 0)
{

	cursor = nullptr;


	head = nullptr;
	
}

template <typename DataType>
List<DataType>::List(const List& other)
{
	ListNode* newN;
	ListNode* rightNow;
	if (head != nullptr)
		clear();
	if (other.head == nullptr)
	{
		head = nullptr;
		cursor = nullptr;
	}
	else
	{
		rightNow = other.head;
		head = new ListNode;
		head->dataItem = rightNow->dataItem;
		head->next = nullptr;
		cursor = head;
		rightNow = rightNow->next;
		while (rightNow != nullptr)
		{
			newN = new ListNode;
			newN->dataItem = rightNow->dataItem;
			newN->next = nullptr;
			cursor->next = newN;
			cursor = newN;
			rightNow = rightNow->next;
		}
	}
}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other)
{
}

template <typename DataType>
List<DataType>::~List()
{
	clear();
}

template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error)
{
}

template <typename DataType>
void List<DataType>::remove() throw (logic_error)
{
	if (head == nullptr)									
		cout << "It is empty list, cannnot remove it." << endl;
	else if (cursor == head)									
	{
		if (head->next == nullptr)								
		{
			delete cursor;
			head = nullptr;
			cursor = nullptr;
		}
		else
		{
			head = head->next;
			delete cursor;
			cursor = head;
		}
	}
	else													
	{
		ListNode* tc;
		tc = head;
		while (tc->next != cursor)
			tc = tc->next;
		if (cursor->next == nullptr)							
		{
			tc->next = nullptr;
			delete cursor;
			cursor = head;
		}
		else
		{
			tc->next = cursor->next;
			delete cursor;
			rightNow = tc->next;
		}
	}
}

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error)
{
	if (head == nullptr)
		cout << "List is not full." << endl;
	else
		cursor->dataItem = newDataItem;
}

template <typename DataType>
void List<DataType>::clear()
{
	ListNode* temp;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	cursor = nullptr;
}

template <typename DataType>
bool List<DataType>::isEmpty() const
{
	return head == nullptr;
}

template <typename DataType>
bool List<DataType>::isFull() const
{
	ListNode* rightNow;
	ListNode* newN;
	rightNow = cursor;
	while (rightNow->next != nullptr)
		rightNow = rightNow->next;
	try
	{
		newN = new ListNode;			
	}
	catch (bad_alloc)						
	{
		cout << "List is not empty." << endl;
		return false;
	}
	delete newN;							
	return true;
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error)
{
	if (head == nullptr)						
		cout << "List is not full." << endl;
	else
		cursor = head;
}

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error)
{
	if (head == nullptr)							
		cout << "List is not full." << endl;
	else
	{
		while (cursor->next != nullptr)				
			cursor = cursor->next;
	}
}

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)
{
	if (head == nullptr || cursor->next == nullptr)	
		return false;
	else                                            
	{
		cursor = cursor->next;
		return true;
	}
}

template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error)
{
	if (head == cursor || head == nullptr)			
		return false;
	else										
	{
		ListNode* tc;
		tc = head;
		while (tc->next != cursor)
			tc == tc->next;
		cursor = tc;
		return true;
	}

}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error)
{
	if (head == nullptr)
		cout << "List is not full." << endl;
	else
		return cursor->dataItem;
}

template <typename DataType>
void List<DataType>::moveToBeginning() throw (logic_error)
{
	if (head == nullptr)						
		cout << "List is not full." << endl;
	else if (cursor != head)					
	{
		ListNode* tc;
		ListNode* newN;
		DataType temp = cursor->dataItem;
		tc = head;

		while (tc->next != cursor)
			tc = tc->next;
		if (cursor->next == nullptr)
			tc->next = nullptr;
		else
			tc->next = cursor->next;
		delete cursor;

		newN = new ListNode;
		newN->dataItem = temp;
		newN->next = head;
		cursor = newN;
		head = newN;
	}
}

template <typename DataType>
void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error)
{
	ListNode* newN;
	ListNode* tc;
	if (head == nullptr)					
	{
		newN = new ListNode;
		newN->dataItem = newDataItem;
		newN->next = nullptr;
		head = newN;
		cursor = newN;
	}
	else if (head->next == nullptr)			
	{
		newN = new ListNode;
		newN->dataItem = newDataItem;
		newN->next = head;
		newN = head;
		newN = cursor;
	}
	else									
	{
		tc = head;
		while (tc->next != cursor)
			tc = tc->next;
		newN = new ListNode;
		newN->dataItem = newDataItem;
		newN->next = cursor;
		tc->next = newN;
		cursor = newN;
	}
}

#include "show5.cpp"