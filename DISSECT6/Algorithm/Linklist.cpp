// Linklist.cpp: implementation of the Linklist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Algorithm.h"
#include "Linklist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "Linklist.h"
template<class DT>  
LinkedList<DT>::LinkedList()  
{  
    start = current = NULL;  
}  
template<class DT>  
LinkedList<DT>::LinkedList(const LinkedList<DT> &aplist)  
{  
    deepCopy(aplist);  
}  
template<class DT>  
LinkedList<DT>::~LinkedList()  
{  
    makeEmpty();  
}  
template<class DT>  
LinkedList<DT>& LinkedList<DT>::operator =(const LinkedList<DT> &rlist)  
{  
    if(this == &rlist)  
        return this;  
    makeEmpty();  
    deepCopy(rlist);  
    return this;  
}  
//������ı�ͷ����DT &element�������û�е�ǰλ��  
template<class DT>  
void LinkedList<DT>::insert(const DT &element)  
{  
    current = NULL;  
    Node<DT> *NNode = new Node<DT>;  
    NNode->info = element;  
    NNode->next = start;  
    start = NNode;  
}  
////�������β������  
template<class DT>  
void LinkedList<DT>::insert_end(const DT &element)  
{  
    current = NULL;  
    Node<DT> *NNode = new Node<DT>;  
    NNode->info = element;  
    NNode->next = NULL;  
    Node<DT> *temp;  
    DT item;  
    if(start == NULL)  
    {  
        start = NNode;  
        temp = start;  
        return;  
    }  
    temp = start;  
    while(temp->next != NULL)  
    {  
        temp = temp->next;  
    }  
    temp->next = NNode;  
}  
//�������еĵ�һ��Ԫ�ش����listEl�У����Ұѵ�һ��Ԫ�ص�λ����Ϊcurrent  
template<class DT>  
bool LinkedList<DT>::first(DT &listEl)  
{  
    if(start == NULL)  
        return false;  
    current = start;  
    listEl = start->info;   
    return true;  
}  
//��������current���¸�Ԫ�ط���listEl�У�currentָ����һ��Ԫ��  
template<class DT>  
bool LinkedList<DT>::getNext(DT &listEl)  
{  
    if(current == NULL)  
        return false;  
    if(current->next == NULL)  
    {  
        current = NULL;  
        return false;  
    }  
    listEl = current->next->info;  
    current = current->next;  
    return true;  
}  
//����ҵ�elment������true,current��getNext()������  
template<class DT>  
bool LinkedList<DT>::find(const DT &element)  
{  
    DT item;  
    if(!first(item))  
        return false;  //����Ƿ�Ϊ��  
    do{  
        if(item == element)  
            return true;  
    }while(getNext(item));  
    return false;  
}  
template<class DT>  
bool LinkedList<DT>::retrieve(DT &element)  
{  
    if(!find(element))  
        return false;  
    element = current->info;  
    return true;  
}  
template<class DT>  
bool LinkedList<DT>::replace(const DT &newElement)  
{  
    if(current == NULL)  
        return false;  
    current->info = newElement;  
    return true;  
}  
template<class DT>  
bool LinkedList<DT>::remove(DT &element)  
{  
    current = NULL;  
    if(start == NULL)  
        return false;  
    Node<DT> *ptr = start;  
    if(start->info == element)  
    {  
        element = start->info;  
        start = ptr->next;  
        delete ptr;  
        return true;  
    }  
    while(ptr->next != NULL){  
        if(ptr->next->info == element)  
        {  
            Node<DT> *tempptr = ptr->next;  
            element = tempptr->info;  
            ptr->next = tempptr->next;  
            delete tempptr;  
            return true;  
        }  
        ptr = ptr->next;  
    }     
    return false;  
}  
template<class DT>  
bool LinkedList<DT>::isEmpty() const  
{  
     return start == NULL;  
}  
template<class DT>  
void LinkedList<DT>::makeEmpty()  
{  
    while(start != NULL)  
    {  
        current = start;  
        start = start->next;  
        delete current;  
    }  
    current = NULL;  
}  
template<class DT>  
void LinkedList<DT>::deepCopy(const LinkedList<DT> &original)  
{  
    start = current = NULL;  
    if(original.start == NULL)  
        return;  
    Node<DT> *copyptr = start = new Node<DT>;  
    Node<DT> *originalptr = original.start;  
    copyptr->info = originalptr->info;  
    if(originalptr == original.current)  
        current = copyptr;  
    while(originalptr->next  != NULL)  
    {  
        copyptr->next = new Node<DT>;  //��һ�����ѶȰ���  
        originalptr = originalptr->next;  
        copyptr = copyptr->next;  
        copyptr->info = originalptr->info;  
        if(originalptr == original.current)  
            current = copyptr;  
    }  
    copyptr->next = NULL;  
}  

