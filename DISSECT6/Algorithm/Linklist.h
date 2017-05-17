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
    void insert(const DT &element);  //在链表的头部之前插入  
    void insert_end(const DT &element);  //在链表的尾部插入  
    bool first(DT &listEl);     //得到对头的数据  
    inline bool getNext(DT &listEl);   //得到当前指针所指的下一个数据  
    bool find(const DT &element);    //查找一个数据  
    bool retrieve(DT &element);       //检索一个数据  
    bool replace(const DT &newElement);    //更改一个数据  
    bool remove(DT &element);  
    bool isEmpty() const;  
    void makeEmpty();  
private:  
    Node<DT> *start;   //指向头结点  
    Node<DT> *current;    //指向当前的结点  
    inline void deepCopy(const LinkedList<DT> &original);   //"深复制"  
};  

#endif // !defined(AFX_LINKLIST_H__5B86BF88_5BEB_428B_8409_FF17C20944C6__INCLUDED_)
