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
    void insert(const DT &element);  //�������ͷ��֮ǰ����  
    void insert_end(const DT &element);  //�������β������  
    bool first(DT &listEl);     //�õ���ͷ������  
    inline bool getNext(DT &listEl);   //�õ���ǰָ����ָ����һ������  
    bool find(const DT &element);    //����һ������  
    bool retrieve(DT &element);       //����һ������  
    bool replace(const DT &newElement);    //����һ������  
    bool remove(DT &element);  
    bool isEmpty() const;  
    void makeEmpty();  
private:  
    Node<DT> *start;   //ָ��ͷ���  
    Node<DT> *current;    //ָ��ǰ�Ľ��  
    inline void deepCopy(const LinkedList<DT> &original);   //"���"  
};  

#endif // !defined(AFX_LINKLIST_H__5B86BF88_5BEB_428B_8409_FF17C20944C6__INCLUDED_)
