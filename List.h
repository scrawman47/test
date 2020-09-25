#ifndef GUARD_List_h
#define GUARD_List_h

#include<stdio.h>

template<class Type>class List;

template<class Type>
class ListNode {
friend class List <Type>;

public:
	ListNode() { link = NULL; }
	ListNode(Type _data) { data = _data; link = NULL; }
	ListNode * NextNode() { return link; }
private:
	Type data;
	ListNode* link;
};

template<class Type>
class List {
public:
	List(const Type& value) { head = new ListNode<Type>(value); }
	ListNode<Type>* Creat_List(int n);
	void Show_List();
	int Length() const;
	int Insert(Type value, int i);
	int Delete(int i);
	Type* Get(int i);
	ListNode<Type>* Circle();
private:
	ListNode<Type> * head;
};

template<class Type>
ListNode<Type>* Combine(List<Type>& , List<Type>& );

#endif



