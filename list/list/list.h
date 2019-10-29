//list实现双向带头循环链表
namespace czy
{
	template<class T>
	struct _list_node
	{
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _data;

		_list_node(const T& x)//构造函数初始化
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	template<class T,class Ref,class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, Ref, Ptr> Self;//Self的定义方便模板参数的增加

		node *_node;

		_list_iterator(node* node)//构造此迭代器需要节点的指针
			:_node(node)
		{}

		Ref operator*()  
		{
			return _node->_data;
		}

		//_list_iterator<T>换成Self
		Self& operator++()//前置++
		{
			_node = _node->_next;
			return *this;
		}

		//_list_iterator<T>换成Self
		Self& operator++(int)//后置++
		{
			_list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		//it!   可通过比较迭代器指向的节点的指针不同而实现迭代器不等的比较
		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}
	};
	template<class T>
	class list
	{
		typedef _list_node<T> node;//指向头结点的指针

	public:
		typedef _list_iterator<T,T&,T*> iterator;//记得要放到public里面
		typedef _list_iterator<T,const T&,const T*> const_iterator;

		const_iterator begin() const//const对象调const的begin(),返回const迭代器，只能读不能写
		{
			return iterator(_head->_next);//注意：begin指向head的next
		}

		const_iterator end() const
		{
			return iterator(_head);//end指向head
		}

		iterator begin() //普通对象调普通的begin(),返回普通迭代器，对应上面的T&，可读可写
		{
			return iterator(_head->_next);//注意：begin指向head的next
		}

		iterator end() 
		{
			return iterator(_head);//end指向head
		}

		list()
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& x)
		{
			node* tail = _head->_prev;
			node* newnode = new node(x);

			//head ...tail  newnode
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
	private:
		node* _head;
	};

	void print_list(const list<int>& l)//const对象
	{
		list<int>::const_iterator it = l.begin();//begin的定义如果不加const，是const对象调用普通函数，不OK
		while (it != l.end())
		{
			//*it = 10;//普通迭代器可以修改容器内容？const对象应该用const迭代器处理，对此将模板做出了调整，有普通迭代器和const迭代器之分
			//修改后上一行会报错：it不能给常量赋值，因为const迭代器只能读不能写
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list1()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);

		list<int>::iterator it = l.begin();
		while (it != l.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		print_list(1);
	}

}










