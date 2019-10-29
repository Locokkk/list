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
	//l.unique();//ȥ�أ�ǰ�������������ֱ��ȥ����һ��O(n^2)���㷨

	//list<int>::iterator it = l.begin();
	//while (it != l.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	list<int>::iterator pos = find(l.begin(), l.end(), 3);
	l.insert(pos, 30);//��3��ǰ�����30
	l.erase(pos);//list��insert��ʧЧ��eraseʧЧ(�ײ�����ʽ�ṹ)

	*pos = 300;//insertʱposλ�ò�ʧЧ���ɷ��ʿ��޸ģ�eraseʱʧЧ
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