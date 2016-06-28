#include <iostream>
#include <stack>
using namespace std;

/*
���⣺������stack���ݽṹʵ��Queue
������blog���ߵ�д��1
*/
template <typename T>

class MyQueue
{
public:
	MyQueue()
	{
	}
	
	~MyQueue()
	{
	}

	void push(T val)
	{
		//�����ú����滻�ظ�Ҫ�õ�����䣬��
		move(sout, sin);
		sin.push(val);
	}
	
	void pop()
	{
		move(sin, sout);
		sout.pop();
	}

	T front()
	{
		move(sin, sout);
		return sout.top();
	}
	T back()
	{
		move(sout, sin);
		return sin.top();
	}

	int size()
	{
		return sin.size() + sout.size();
	}
	bool empty()
	{
		return (sin.empty() && sout.empty());
	}
	
	void move(stack<T> &src, stack<T> &dst)
	{
		while (!src.empty())
		{
			dst.push(src.top());
			src.pop();
		}
	}

private:
	stack<T> sin, sout;
};

int main()
{
	MyQueue<int> q;
	for (int i = 0; i < 10; i++)
	{
		q.push(i);
	}

	cout << q.front() << " " << q.back() << endl;
	cout << endl;
	
	q.pop();
	q.push(10);
	cout << q.front() << " " << q.back() << endl;
	cout << endl;

	cout << q.size() << " " << q.empty() << endl;

	system("pause");
	return 0;
}