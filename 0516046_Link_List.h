#ifndef _0516046_LINK_LIST
#define _0516046_LINK_LIST

#include <iostream>
using namespace std;

template <typename T>
struct Int_Node
{
    T value;
	Int_Node<T> *pre, *next;
};
template <typename T>
class Link_List
{
	friend ostream &operator<<(ostream &out, const Link_List<T> &list)
    {
        for(int i=0;i<list.size;i++)
        {
            //cout  << list.size <<endl;
            out << list[i] << " ";
        }
        return out;
    }// print all integers in the list
	friend istream &operator>>(istream &in, Link_List<T> &list)
    {
        T x;
        in >> x;
        list.insert_node(x);
        return in;
    }// input a value at the back of the list, like insert_node(val);

public:
	Link_List();										// default constructor
	Link_List(const Link_List &);						// copy constructor
	~Link_List();
	int getSize() const;
	
	const Link_List &operator=(const Link_List &);      // assignment operator
	bool operator==(const Link_List &) const;			// equality operator
	bool operator!=(const Link_List &right) const		// inequality operator
	{
		return !(*this == right);
	}
	T &operator[](int index);							// subscript operator for non-const objects
	T operator[](int index) const;					// subscript operator for const objects
	bool insert_node(T value);						// insert an integer at the back of link list
	bool delete_node();                                 // delete the last node
	bool insert_node(int index, T value);				// insert an integer after the i_th position
	bool delete_node(int index);						// delete the i_th node

private:
	int size;
	Int_Node<T> *head, *tail;								// pointer to the first and the last element of Link_List
};

template <typename T>
const Link_List<T> &Link_List<T>::operator=(const Link_List<T> &a)
{
    Link_List<T> tmp(a);
    this->head=tmp.head;
    this->tail=tmp.tail;
    this->size=tmp.size;
    
    return *this;
    
}
template <typename T>
bool Link_List<T>::operator==(const Link_List &list) const
{
    if(this->getSize()!=list.getSize())
        return false;
    Int_Node<T> *tmp1=this->head,*tmp2=list.head;
    while(tmp1)
    {
        if(tmp1->value!=tmp2->value)
            return false;
        tmp1=tmp1->next;
        tmp2=tmp2->next;
    }
    return true;
}
template <typename T>
T &Link_List<T>::operator[](int n)
{
    Int_Node<T> *tmp=head;
    for(;n>0;n--)
    {
        tmp=tmp->next;
    }
    return tmp->value;
}
template <typename T>
T Link_List<T>::operator[](int n) const
{
    Int_Node<T> *tmp=head;
    for(;n>0;n--)
    {
        tmp=tmp->next;
    }
    return tmp->value;
    
}
template <typename T>
Link_List<T>::Link_List()
{
    head=NULL;
    tail=NULL;
    size=0;
}
template <typename T>
Link_List<T>::Link_List(const Link_List &in)
{
    head=NULL;
    tail=NULL;
    for(int i=0;i<in.size;i++)
    {
        insert_node(in[i]);
    }
    
}
template <typename T>
Link_List<T>::~Link_List()
{
    while(delete_node());
}
template <typename T>
int Link_List<T>::getSize() const
{
    return size;
}
template <typename T>
bool Link_List<T>::insert_node(T in)
{
    Int_Node<T> *newNode;
    newNode = new Int_Node<T>;
    newNode->next=NULL;
    newNode->pre=NULL;
    
    if(head==NULL)
        head=newNode;
    newNode->value = in;
    newNode->next = NULL;
    newNode->pre=tail;
    if(tail!=NULL)
        tail->next=newNode;
    tail=newNode;
    size++;
    return true;
}
template <typename T>
bool Link_List<T>::delete_node()
{
    Int_Node<T> *pre=tail;
    if(pre)
    {
        tail=tail->pre;
        delete pre;
        if(tail)
            tail->next=NULL;
        else
            head=NULL;
        size--;
        return true;
    }
    else
        return false;
    
}
template <typename T>
bool Link_List<T>::insert_node(int p, T in)
{
    if(p<0 || p>size)
    {
        return false;
    }
    else
    {
        Int_Node<T> *tmp=head;
        for(;p>0;p--)
        {
            tmp=tmp->next;
        }
        Int_Node<T> *newNode=new Int_Node<T>;
        newNode->next=tmp->next;
        newNode->value=in;
        newNode->pre=tmp;
        tmp->next=newNode;
        newNode->next->pre=newNode;
        size++;
        return true;
    }
}
template <typename T>
bool Link_List<T>::delete_node(int p)
{
    if(p<0 || p>size)
    {
        return false;
    }
    else
    {
        Int_Node<T> *tmp=head;
        for(;p>0;p--)
        {
            tmp=tmp->next;
        }
        if(tmp->pre)
            tmp->pre->next=tmp->next;
        if(tmp->next!=NULL)
            tmp->next->pre=tmp->pre;
        delete tmp;
        size--;
        return true;
    }
}


#endif // LINK_LIST
