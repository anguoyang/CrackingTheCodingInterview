#include <iostream>
#include <stack>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <functional>       //��仰û�У���������ȼ����У������������Ǵ����
using namespace std;

class sortStack
{
public:
	stack<int> sort1(stack<int> s)
	{
		stack<int> t;
		while (!s.empty())
		{
			int data = s.top();
			s.pop();
			while (!t.empty() && t.top() > data)
			{
				s.push(t.top());
				t.pop();
			}
			t.push(data);
		}
		return t;
	}

	void sort2(stack<int> &s)
	{
		priority_queue<int, vector<int>, greater<int> > q; //��Сֵ���ȶ���
		//priority_queue<int, vector<int>, less<int> > q;
		while (!s.empty())
		{
			q.push(s.top());
			s.pop();
		}
		while (!q.empty())
		{
			s.push(q.top());
			q.pop();
		}
	}
};
int main()
{
    //�����������
	//srand((unsigned)time(0));
	//rand()/(RAND_MAX + 1.0)��������
	//rand() : 0 �� 0x7ffff ����0~32767
	//cout << rand() % 100 << endl;

	const int N = 5;
	int a[N] = {5, 2, 1, 6, 4};
	
	stack<int> st;
	sortStack s;
	
	for (int i = 0; i < N; i++)
	{
		st.push(a[i]);
	}
	//method1
	//st = s.sort1(st);
	
	//method2
	s.sort2(st);
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	
	system("pause");
	return 0;
}