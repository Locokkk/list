//listʵ��˫���ͷѭ������
namespace czy
{
	template<class T>
	struct _list_node
	{
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _data;

		_list_node(const T& x)//���캯����ʼ��
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	template<class T,class Ref,class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, Ref, Ptr> Self;//Self�Ķ��巽��ģ�����������

		node *_node;

		_list_iterator(node* node)//����˵�������Ҫ�ڵ��ָ��
			:_node(node)
		{}

		Ref operator*()  
		{
			return _node->_data;
		}

		//_list_iterator<T>����Self
		Self& operator++()//ǰ��++
		{
			_node = _node->_next;
			return *this;
		}

		//_list_iterator<T>����Self
		Self& operator++(int)//����++
		{
			_list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		//it!   ��ͨ���Ƚϵ�����ָ��Ľڵ��ָ�벻ͬ��ʵ�ֵ��������ȵıȽ�
		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}
	};
	template<class T>
	class list
	{
		typedef _list_node<T> node;//ָ��ͷ����ָ��

	public:
		typedef _list_iterator<T,T&,T*> iterator;//�ǵ�Ҫ�ŵ�public����
		typedef _list_iterator<T,const T&,const T*> const_iterator;

		const_iterator begin() const//const�����const��begin(),����const��������ֻ�ܶ�����д
		{
			return iterator(_head->_next);//ע�⣺beginָ��head��next
		}

		const_iterator end() const
		{
			return iterator(_head);//endָ��head
		}

		iterator begin() //��ͨ�������ͨ��begin(),������ͨ����������Ӧ�����T&���ɶ���д
		{
			return iterator(_head->_next);//ע�⣺beginָ��head��next
		}

		iterator end() 
		{
			return iterator(_head);//endָ��head
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

	void print_list(const list<int>& l)//const����
	{
		list<int>::const_iterator it = l.begin();//begin�Ķ����������const����const���������ͨ��������OK
		while (it != l.end())
		{
			//*it = 10;//��ͨ�����������޸��������ݣ�const����Ӧ����const�����������Դ˽�ģ�������˵���������ͨ��������const������֮��
			//�޸ĺ���һ�лᱨ��it���ܸ�������ֵ����Ϊconst������ֻ�ܶ�����д
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










