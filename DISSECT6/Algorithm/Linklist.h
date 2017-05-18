// Linklist.h: interface for the Linklist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINKLIST_H__5B86BF88_5BEB_428B_8409_FF17C20944C6__INCLUDED_)
#define AFX_LINKLIST_H__5B86BF88_5BEB_428B_8409_FF17C20944C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template<class DT>  
struct Node  
{  
    DT info;  
    Node<DT> *next;  
};  
template<class DT>  
class LinkedList  
{  
public:  
    LinkedList();  
    LinkedList(const LinkedList<DT> &aplist);  
    ~LinkedList();  
    LinkedList<DT>& operator=(const LinkedList<DT> &rlist);  
    void insert(const DT &element);  //insert node before head 
    void insert_end(const DT &element);  //insert node after tail
    bool first(DT &listEl);     //get head element 
    inline bool getNext(DT &listEl);   //get next element of current one  
    bool find(const DT &element);    //search for an element  
    bool retrieve(DT &element);       //  
    bool replace(const DT &newElement);    //update an element
    bool remove(DT &element);  
    bool isEmpty() const;  
    void makeEmpty();  
private:  
    Node<DT> *start;   //head pointer  
    Node<DT> *current;    //tail pointer
    inline void deepCopy(const LinkedList<DT> &original);   //depy copy
};  

#endif // !defined(AFX_LINKLIST_H__5B86BF88_5BEB_428B_8409_FF17C20944C6__INCLUDED_)
