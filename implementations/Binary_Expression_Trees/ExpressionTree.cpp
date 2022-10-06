
#include "ExpressionTree.h"
// build helper float
void ExprTree<float>::buildHelper(ExprTreeNode*& p)
{
    char ch;   // Input operator or number 
    cin >> ch;
    p = new ExprTreeNode(ch, 0, 0);   // Link in node 
    if (!isdigit(ch)) {   // Operator -- construct subtrees

        buildHelper(p->left);    
        buildHelper(p->right);

    } 

}
// build helper bool
void ExprTree<bool>::buildHelper(ExprTreeNode*& p)
{
    char ch;
    cin >> ch;
    while (ch != '\n')
    {
        if (ch == '&'||ch == '|'||ch == '^')
        {
            p = new ExprTreeNode(ch, NULL, NULL);
            buildHelper(p->left);
            buildHelper(p->right);
        }
        else if (isdigit(ch))
        {
            int val = ch - '0';
            if (val == 0 || val == 1)
                p = new ExprTreeNode((bool)(val), NULL, NULL);
        }
    }
}

// copy helper 
template <typename DataType>
void ExprTree<DataType>::copyHelper(ExprTreeNode*& p)
{
    this->root = p;
    copyHelper(p->left);
    copyHelper(p->right);
}
//
template <typename DataType>
ExprTree<DataType>::ExprTreeNode::ExprTreeNode(char nodeDataItem,
    ExprTreeNode* leftPtr,
    ExprTreeNode* rightPtr){
    dataItem = nodeDataItem;
    left = leftPtr;
    right = rightPtr;
}
//
template <typename DataType>
void ExprTree<DataType>::copyHelper
(ExprTreeNode*& p) {
    if (p != 0) {
        p = new ExprTreeNode(p->dataItem, p -> left, p->right);
        copyHelper(p->left);
        copyHelper(p->right);
    }
}

template <typename DataType>
ExprTree<DataType>::ExprTreeNode::ExprTreeNode ( char elem, ExprTreeNode *leftPtr, ExprTreeNode *rightPtr )
{
}

template <typename DataType>
ExprTree<DataType>::ExprTree ()
{
    root = NULL;
}

template <typename DataType>
ExprTree<DataType>::ExprTree(const ExprTree& source)
{
    root = source.root;
    copyHelper(root);
}

template <typename DataType>
ExprTree<DataType>& ExprTree<DataType>::operator=(const ExprTree& source)
{
    if (this == &source) {
        return *this;
    }

    copyHelper(root, source.root);
    return *this;
}

template <typename DataType>
ExprTree<DataType>::~ExprTree ()
{
    clear();
}

template <typename DataType>
void ExprTree<DataType>::build ()
{
    clear();
    buildHelper(root);
}

template <typename DataType>
void ExprTree<DataType>::expression () const
{
    exprHelper(root);
}


template <typename DataType>
void ExprTree<DataType>::exprHelper(ExprTreeNode* p) const {
    if (p != 0) {
        if (!isdigit(p->dataItem)) cout << '(';
        // recursively travel left children 
        cout << p->dataItem;
        // recursively travel right children 
        if (!isdigit(p->dataItem)) cout << ')';
    }
}

template <typename DataType>
DataType ExprTree<DataType>::evaluate() const throw (logic_error)
{
    if (root == NULL)
        throw("ExprTree is empty.");
    return evalHelper(root);
}

template <typename DataType>
DataType ExprTree<DataType>::evalHelper(ExprTreeNode* p) const {
    // define variables for intermediate and final results 
    if (isdigit(p->dataItem))
        result = p->dataItem - '0';      // Convert from char to number 
    else { // evaluate left and right subtrees, and combine results} 
        return result;
    }

template <typename DataType>
void ExprTree<DataType>::clear ()
{
    clearHelper(root);
    root = 0;
}

void ExprTree<DataType>::clearHelper(ExprTreeNode* p) {
    if (p != 0)
    {
        clearHelper(p->left);   //Recursively call left
        clearHelper(p->right);  //Recursively call right
        delete p;   //Delete the node
        p = 0;   //Set to null for dangling pointer
    }
}

template <typename DataType>
void ExprTree<DataType>::commute()
{
    commuteHelper(root);
}

void ExprTree<DataType>::commuteHelper(ExprTreeNode* p) {
    if (p == 0)
        return;
    if (!isdigit(p->dataItem))
    {
        ExprTreeNode* temp = p->left;
        p->left = p->right;
        p->right = temp;
    }
    commuteHelper(p->left);     
    commuteHelper(p->right);   
}

template <typename DataType>
bool ExprTree<DataType>::isEquivalent(const ExprTree& source) const
{
    return isEquivalentHelper(root, source.root);
}

//
bool ExprTree<DataType>::isEquivalentHelper(const ExprTreeNode* x, const
    ExprTreeNode* y) const {
    if (x == NULL && y == NULL)
        return true;
    else if (x != NULL && y != NULL)
    {
        if (x->dataItem == y->dataItem)
        {
            if (isEquivHelper(x->left, y->left) &&
                isEquivHelper(x->right, y->right))
                return true;
            else if (isEquivHelper(x->left, y->right) &&
                isEquivHelper(x->right, y->left))
            {
                if (x->dataItem == '+' || x->dataItem == '*')
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
    }
    return false
}

template <typename DataType>
bool ExprTree<DataType>::isEmpty() const
{
	return false;
}

#include "show8.cpp"