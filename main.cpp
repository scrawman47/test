#include"List.h"
#include"List.cpp"



int main()
{
	int n1, n2;
	List<int> list1(0),list2(0),list3(0);
	cout << "输入两个链表的元素个数" << endl;
	cin >> n1 >> n2;
	list1.Creat_List(n1);
	list2.Creat_List(n2);
	list1.Show_List();
	list2.Show_List();
	list3.head = Combine(list1, list2);
	list3.Show_List();
}