
#include "BSTree.h"

template <typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode ( const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr )
{
	
	left = leftPtr;
	right = rightPtr;
	dataItem = nodeDataItem;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree ()
{
	root = NULL;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree ( const BSTree<DataType,KeyType>& other )
{
	root = NULL;
	copyTreeHelp(root, other.root);
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>:: operator= ( const BSTree<DataType,KeyType>& other )
{
	clearHelp(root);
	copyTreeHelp(root, other.root);
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::~BSTree ()
{
	clearHelp(root);
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::insert ( const DataType& newDataItem )
{
	insertHelp(root, newDataItem);
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::retrieve ( const KeyType& findKey, DataType& findDataItem ) const
{
	return retrieveHelp(root, findKey, findDataItem);
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::remove ( const KeyType& deleteKey )
{
	return removeHelp(root, deleteKey);
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeKeys () const
{
	writeKeysHelp(root);
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::clear ()
{
	clearHelp(root);
	root = NULL;
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::isEmpty () const
{
	return false;
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getHeight () const
{
	return getHeightHelp(root) - 1;
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getCount () const
{
	return getCountHelp(root);
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeLessThan ( const KeyType& searchKey ) const
{
	writeLessThenHelp(root, searchKey);
}

//////////////////////////////////////////////////////////////////////////////////////////////
template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::copyTreeHelp(BSTreeNode*& x, const BSTreeNode* otherPtr)
{
	if (otherPtr == NULL) { 
		return; 
	}
	x = new BSTreeNode(otherPtr->dataItem, NULL, NULL);
	
	copyTreeHelp(x->right, otherPtr->right);
	copyTreeHelp(x->left, otherPtr->left);
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::clearHelp(BSTreeNode* p)
{
	if (p->right != NULL) {
		clearHelp(p->right);
	}
	if (p->left != NULL) {
		clearHelp(p->left);
	}
	delete p;
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::insertHelp(BSTreeNode*& p, const DataType& newDataItem)
{
	if (p == NULL) {
		p = new BSTreeNode(newDataItem, NULL, NULL);
		return;
	}
	KeyType chaviRN = p->dataItem.getKey();
	KeyType chavi = newDataItem.getKey();
	

	if (chavi < chaviRN) {
		insertHelp(p->left, newDataItem);
	}
	else if (chavi > chaviRN) {
		insertHelp(p->right, newDataItem);
	}
	else {
		p->dataItem = newDataItem;
	}
}

template<typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::retrieveHelp(BSTreeNode* p, const KeyType& findKey, DataType& findDataItem) const
{
	if (p == NULL) { 
		return false; 
	}
	KeyType chavi = p->dataItem.getKey();
	if (findKey < chavi) {
		return retrieveHelp(p->left, findKey, findDataItem);
	}
	if (findKey > chavi) {
		return retrieveHelp(p->right, findKey, findDataItem);
	}
	findDataItem = p->dataItem;
	return true;
}

template<typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::removeHelp(BSTreeNode*& p, const KeyType& deleteKey)
{
	if (p == NULL) { 
		return false; 
	}
	KeyType chavi = p->dataItem.getKey();

	if (deleteKey > chavi) {
		return removeHelp(p->right, deleteKey);
	}
	if (deleteKey < chavi) {
		return removeHelp(p->left, deleteKey);
	}

	BSTreeNode* deletePtr = p;
	if (p->right == NULL) {
		p = p->left;
	}
	else if (p->left == NULL) {
		p = p->right;
	}
	else {
		removeAllTheWayToTheRight(p->left, deletePtr);
	}
	delete deletePtr;
	return true;
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::removeAllTheWayToTheRight(BSTreeNode*& X, BSTreeNode*& delPtr)
{
	if (X->right != NULL) {
		removeAllTheWayToTheRight(X->right, delPtr);
	}
	else {
		delPtr->dataItem = X->dataItem;
		delPtr = X;
		X = X->left;
	}
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeKeysHelp(BSTreeNode* p) const
{
	if (p == NULL) { 
		return; 
	}
	writeKeysHelp(p->left);
	cout << p->dataItem.getKey();
	writeKeysHelp(p->right);
}

template<typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getHeightHelp(BSTreeNode* p) const
{
	if (p == NULL) { 
		return 0; 
	}
	return max(getHeightHelp(p->left), getHeightHelp(p->right)) + 1;
}

template<typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getCountHelp(BSTreeNode* p) const
{
	if (p == NULL) { 
		return 0; 
	}
	return getCountHelp(p->left) + getCountHelp(p->right) + 1;
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeLessThenHelp(BSTreeNode* p, const KeyType& searchKey) const
{
	if (p == NULL) { 
		return; 
	}
	KeyType chavi = p->dataItem.getKey();
	writeLessThenHelp(p->left, searchKey);
	if (chavi < searchKey) {
		cout << chavi;
		writeLessThenHelp(p->right, searchKey);
	}
}


#include "show9.cpp"