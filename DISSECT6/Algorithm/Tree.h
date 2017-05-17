// Tree.h: interface for the Tree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREE_H__67774782_DAFA_49EC_8BDB_73DD3DAABD88__INCLUDED_)
#define AFX_TREE_H__67774782_DAFA_49EC_8BDB_73DD3DAABD88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//class<CString> BinaryTree;


template <class T>  
class BinaryTree  
{  
protected:  
	//node structure
    struct TNode  
    {  
        T val;  
        TNode* parent;  
        TNode* left;  
        TNode* right;  
        TNode(T t, TNode* p = NULL, TNode* l = NULL, TNode* r = NULL):val(t), parent(p), left(l), right(r)   
        {  
			//if parent do not exist
            if (!parent) parent = this;  
        }  
    };  
private:  
	//root node pointer
    TNode* _root;  
public:  

	//iterator of tree
    class TIterator  
    {  
        BinaryTree* tree;  
        TNode* node;  
    public:  
        friend class BinaryTree;  

		//constructor
        TIterator():tree(NULL), node(NULL) {}  
        TIterator(const TIterator& it):tree(it.tree), node(it.node) {}  
        TIterator(BinaryTree* t, TNode* n = NULL):tree(t), node(n) {}  
        TIterator& operator = (const TIterator& it)  
        {  
            tree = it.tree;  
            node = it.node;  
            return *this;  
        }  

		//equal, not equal
        bool operator == (const TIterator& it) {return (tree == it.tree && node == it.node);}  
        bool operator != (const TIterator& it) {return !(*this == it);}  
  
		//move iterator
        TIterator& operator ++ ()   
        {  
            node = preorderSuccessor(node);  
            return *this;  
        }  
        TIterator operator ++ (int)  
        {  
            TIterator it(*this);  
            node = preorderSuccessor(node);  
            return it;  
        }  
  
		//get node value like pointer/ struct
        T& operator *() {return node->val;}  
        TNode* operator ->() {return node;}  
        const T& operator *() const {return node->val;}  
        const TNode* operator ->() const {return node;}
		
		//check if node is null
        bool operator !() {return node == NULL;}  
  
    protected:  
    };  
  
	//construct binary tree
    BinaryTree():_root(NULL) {}  
    BinaryTree(const BinaryTree& b)  
    {  
        _root = clone(b._root, 0);  
    }  
    BinaryTree(const T& t):_root(new TNode(t)) {_root->parent = _root;}  
    BinaryTree(const T& t, const BinaryTree& l, const BinaryTree& r); 
	
	//deconstruct tree
    ~BinaryTree();  
    BinaryTree& operator = (const BinaryTree&);  
    static void clear(TNode*);                //clear node through poster-order  
    static TNode* preorderSuccessor(TNode*);  //return successive node through pre-order  
    static TNode* clone(TNode*, TNode*);      //copy by iterative pre-order 
    TIterator begin();  
    TIterator end();  
    bool empty() const;  
  
    int size() const;             //get size of tree  
    static int getSize(TNode*);   //recursively get size of tree  
  
    int leaves() const;           //get number of leaf  
    static int getLeaf(TNode*);   //recursively get number of leaf     
  
    int height() const;           //get height of tree  
    static int getHeight(TNode*); //recursively get height of tree   
  
    int level(TIterator it) const;//get current level  
    static int getLevel(TNode*);  //recursively get current level   
  
    void reflect();                    //shift lchild with rchild  
    void defoliate();                  //delete all leaf  
    static void deleteNode(TNode* n);  //recursively delete all leaf  
    T& getRoot() const;				   //get root of tree
  
    static bool isRoot(TIterator);         //check if iterator is in root  
    static bool isLeaf(TIterator);         //check if iterator is in leaf 
    static TIterator getParent(TIterator); //get parent node  
           static TIterator leftChild(TIterator); //get lchild  
    static TIterator rightChild(TIterator);//get rchild 
    static TIterator find(TIterator, TIterator, const T&); //find in a range  
   
    friend class TIterator;  
};  
  
//create a binary tree from another tree
template <class T>  
BinaryTree<T>::BinaryTree(const T& t, const BinaryTree& lTree, const BinaryTree& rTree)  
{  
    _root = new TNode(t);  
    _root->left = clone(lTree._root, _root);  
    _root->right = clone(rTree._root, _root);  
}  
  
//delete a tree
template <class T>  
BinaryTree<T>::~BinaryTree()  
{  
    if (_root != NULL)  
    delete _root;  
}  
 
//copy a tree
template <class T>  
BinaryTree<T>& BinaryTree<T>::operator = (const BinaryTree& t)  
{  
    clear(_root);  
    BinaryTree* temp = new BinaryTree(t);  
    _root = temp->_root;  
    return *this;  
}  
  
template <class T>  
void BinaryTree<T>::clear(TNode* n)  
{  
    if (n == NULL) return;  
    clear(n->left);  
    clear(n->right);  
    delete n;  
}  
  
template <class T>  
typename BinaryTree<T>::TNode* BinaryTree<T>::preorderSuccessor(TNode* n)   
{  
    if (n == 0) return n;  
    if (n->left) return n->left;  
    if (n->right) return n->right;  
    while (n->parent != n && (n->parent->right == n ||n->parent->right == 0))  
        n = n->parent;  
    if (n->parent == n) return 0;  
    return n->parent->right;  
}  
  
template <class T>  
typename BinaryTree<T>::TNode* BinaryTree<T>::clone(TNode* root, TNode* parent)   
{  
    if (!root) return 0;  
    TNode* temp = new TNode(root->val,parent);  
    temp->left = clone(root->left, temp);  
    temp->right = clone(root->right, temp);  
    return temp;  
}  
  
template <class T>  
typename BinaryTree<T>::TIterator BinaryTree<T>::begin()  
{  
    return TIterator(this, _root);  
}  
  
template <class T>  
typename BinaryTree<T>::TIterator BinaryTree<T>::end()  
{  
    return TIterator(this, 0);  
}  
  
template <class T>  
bool BinaryTree<T>::empty() const  
{  
    return _root == 0;  
}  
  
template <class T>  
int BinaryTree<T>::getSize(TNode* n) 
{  
    if (!n) return 0;  
    int sizeL = getSize(n->left);  
    int sizeR = getSize(n->right);  
    return 1+sizeL+sizeR;  
}  
  
template <class T>  
int BinaryTree<T>::size() const  
{  
    return getSize(_root);  
}  
  
template <class T>  
int BinaryTree<T>::getLeaf(TNode* n) 
{  
    if (!n) return 0;  
    if (n->left == 0 && n->right == 0) return 1;  
    return getLeaf(n->left)+getLeaf(n->right);  
}  
  
template <class T>  
int BinaryTree<T>::leaves() const  
{  
    return getLeaf(_root);  
}  
  
template <class T>  
int BinaryTree<T>::getHeight(TNode* node) 
{  
    if (!node) return -1;  
    int hl = getHeight(node->left);  
    int hr = getHeight(node->right);  
    int sum = (hl > hr ? hl : hr);  
    return 1+sum;  
}  
  
template <class T>  
int BinaryTree<T>::height() const  
{  
    return getHeight(_root);  
}  
  
template <class T>  
int BinaryTree<T>::getLevel(TNode* node)  
{  
    if(node == node->parent) return 0;  
    int sum = getLevel(node->parent);  
    return sum+1;  
}  
  
template <class T>  
int BinaryTree<T>::level(TIterator it) const  
{  
    return getLevel(it.node);  
}  
  
template <class T>  
void BinaryTree<T>::reflect()  
{  
    for (TIterator it = begin(); it != end(); it ++)  
    {  
        if (it.node->left && it.node->right)  
        {  
            T temp = it.node->left->val;  
            it.node->left->val = it.node->right->val;  
            it.node->right->val = temp;  
        }  
    }  
}  
  
template <class T>  
void BinaryTree<T>::deleteNode(TNode* n)   
{  
    TNode* nodeL = n->left;  
    if (nodeL && (nodeL->left || nodeL->right)) deleteNode(nodeL);  
    else  
    {  
        delete nodeL;  
        n->left = 0;  
    }  
  
    TNode* nodeR = n->right;  
    if (nodeR && (nodeR->left || nodeR->right)) deleteNode(nodeR);  
    else  
    {  
        delete nodeR;  
        n->right = 0;  
    }  
}  
  
template <class T>  
void BinaryTree<T>::defoliate()   
{  
    if (!_root) return ;  
    if (_root->left || _root->right) deleteNode(_root);  
    else clear(_root);  
}  
  
template <class T>  
T& BinaryTree<T>::getRoot() const  
{  
    if (!_root) return T();  
    return _root->val;  
}  
  
template <class T>  
bool BinaryTree<T>::isRoot(TIterator it)  
{  
    return it.node == it.node->parent;  
}  
  
template <class T>  
bool BinaryTree<T>::isLeaf(TIterator it)   
{  
    return !(it.node->left || it.node->right);  
}  
  
template <class T>  
typename BinaryTree<T>::TIterator BinaryTree<T>::getParent(TIterator it)  
{  
    if (!it.node->parent) return TIterator(it.tree, 0);  
    return TIterator(it.tree, it.node->parent);  
}  
  
template <class T>  
typename BinaryTree<T>::TIterator BinaryTree<T>::leftChild(TIterator it)   
{  
    if (!it.node->left) return TIterator(it.tree, 0);  
    return TIterator(it.tree, it.node->left);  
}  
  
template <class T>  
typename BinaryTree<T>::TIterator BinaryTree<T>::rightChild(TIterator it)   
{  
    if (!it.node->right) return TIterator(it.tree, 0);  
    return TIterator(it.tree, it.node->right);  
}  
  
template <class T>  
typename BinaryTree<T>::TIterator BinaryTree<T>::find(TIterator first, TIterator last, const T& t)   
{  
    for (TIterator it(first); it != last; it ++)  
    {  
        if (t == it.node->val)  
        {  
            return it;  
        }  
    }     
    return TIterator(first.tree, 0);  
}  
  


#endif // !defined(AFX_TREE_H__67774782_DAFA_49EC_8BDB_73DD3DAABD88__INCLUDED_)
