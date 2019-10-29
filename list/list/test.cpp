#include<iostream>
#include<list>
#include<algorithm>
#include<stdlib.h>
using namespace std;

void test_list2()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	//l.sort();
	//l.unique();//去重，前提是有序，无序的直接去重是一个O(n^2)的算法

	//list<int>::iterator it = l.begin();
	//while (it != l.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	list<int>::iterator pos = find(l.begin(), l.end(), 3);
	l.insert(pos, 30);//在3的前面插入30
	l.erase(pos);//list中insert不失效，erase失效(底层是链式结构)

	*pos = 300;//insert时pos位置不失效，可访问可修改，erase时失效
	cout << *pos << endl;
	
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}

#include"list.h"
int main()
{
	//test_list1();
	czy::test_list1();
	system("pause");
	return 0;
}