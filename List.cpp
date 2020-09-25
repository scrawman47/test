#include"List.h"
#include<iostream>
#include<vector>

using namespace std;

template<class Type>
ListNode<Type>* List<Type>::Creat_List(int n)
{
	ListNode<Type>* p, * q;
	if (n == 0)
		return NULL;
	head = new ListNode<Type>(NULL);
	p = head;
	cout << "请输入链表" << endl;
	for (int i = 1;i < n;i++)
	{
		cin >> p->data;
		q = new ListNode<Type>(NULL);
		p->link = q;
		p = q;
	}
	cin >> p->data;
	p->link = NULL;
	return head;

}

/*template<class Type>
int List<Type>::Insert(Type x, int i)
{
	ListNode<Type>* p, * q;
	int j = 0;
	p = head;
	q = new ListNode<Type>(x, NULL);
	while (p != NULL && j < i - 1)
	{
		p = p->link;
		j++;
	}
	if (p == NULL && head != NULL)
	{
		cout << "Invalid\n";
		return 0;
	}
	if (head == NULL || i == 0)
	{
		q->link = head;
		if (head == NULL)
			tail = q;
		head = q;
	}
	else {
		q->link = p->link;
		if (p->link == NULL)
			tail = q;
		p->link = q;
	}
	return 1;
}

template<class Type>
int List<Type>::Delete(int i)
{
	ListNode<Type>* p, * q;
	int j = 0;
	p = head;
	q = new ListNode<Type>(NULL);
	while (p != NULL && j < i - 1)
	{
		p = p->link;
		j++;
	}
	if (p == NULL && head != NULL)
	{
		cout << "Invalid\n";
		return 0;
	}
	if (i == 0)
	{
		q = head;
		p = head = head->link;
	}
	else {
		q = p->link;
		p->link = q->link;
	}
	if (q == tail)
		tail = p;
	delete q;
	return 1;
}
*/
template<class Type>
void List<Type>::Show_List()
{
	ListNode<Type>* p;
	p = head;

	if (p == NULL)
	{
		cout << "Invalid\n";
	}

	while (p != NULL )
	{
		cout << (*p).data<<" ";
		p = p->link;
	}
	cout << endl;
	delete p;
}

template<class Type>
int  List<Type>::Length() const
{
	ListNode<Type>* p;
	int sum = 0;
	p = head;

	if (p == NULL)
	{
		return 0;
	}

	while (p != NULL)
	{
		sum++;
		p = p->link;
	}
	delete p;
	return sum;
}

template<class Type>
ListNode<Type>* Combine(List<Type>& list1, List<Type>& list2)
{
	ListNode<Type>* p, * q, * head = new ListNode<Type>(NULL), * tail= new ListNode<Type>(NULL);
	
	int n1 = list1.Length();
	int n2 = list2.Length();
	p = list1.head;
	q = list2.head;
	for (int i = 1;i < n1;i++)
		p = p->link;
	for (int j = 1;j < n2;j++)
		q = q->link;
	if (p->data < q->data)
	{
		head = q;
		tail = q;
		n2--;
	}
	else
	{
		head = p;
		tail = p;
		n1--;
	}
	while (n1 != 0 && n2 != 0)
	{
		p = list1.head;
		q = list2.head;
		for (int i = 1;i < n1;i++)
			p = p->link;
		for (int j = 1;j < n2;j++)
			q = q->link;
		if (p->data < q->data)
		{
			q->link = NULL;
			tail->link = q;
			tail = q;
			n2--;
		}
		else
		{
			p->link = NULL;
			tail->link = p;
			tail = p;
			n1--;
		}

	}
	if(n1==0)
		while (n2 != 0)
		{
			q = list2.head;
			for (int j = 1;j < n2;j++)
				q = q->link;
			q->link = NULL;
			tail->link = q;
			tail = q;
			n2--;
		}
	if (n2 == 0)
		while (n1 != 0)
		{
			q = list1.head;
			for (int j = 1;j < n2;j++)
				q = q->link;
			q->link = NULL;
			tail->link = q;
			tail = q;
			n1--;
		}
	
	return head;
}

template<class Type>
ListNode<Type>* List<Type>::Circle()
{
	int flag = 0;
	ListNode<Type>* p = head;
	vector<ListNode<Type>*> a;
	a.push_back(p);
	p = p->link;
	while (p != NULL)
	{
		for(vector<ListNode<Type>*>::const_iterator iter =a.begin();iter!=a.end();iter++)
			if (p == *iter) { flag = 1;break; }
		if (flag == 1) break;
		p = p->link;
	}
	if (p == NULL) { cout << "没有环" << endl; }
	else{ cout << "有环" << endl; }
	return p;
}