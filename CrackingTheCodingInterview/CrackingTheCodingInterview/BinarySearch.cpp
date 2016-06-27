#include <iostream>
using namespace std;

/*���ַ�˼�룺1����һ���������� 
2�����Ǻ������м�����Ƚϣ���������������ұߣ��������С��������ߵģ�������ҵ���
*/
//�ݹ�ķ���
int BinarySearch1(int a[], int low, int high, int key) 
{
	int mid = (low + high) / 2;
	if (low > high)
	{
		return -1;
	}
	if (key > a[mid])
	{
		return BinarySearch1(a, mid+1, high, key);
	}
	else if(key < a[mid])
	{
		return BinarySearch1(a, low, mid - 1, key);
	}
	else
	{
		return mid;
	}
}

//�ǵݹ�ķ���
int BinarySearch2(int a[], int aSize, int key)
{
	int low = 0;
	int high = aSize - 1;
	int mid;
	//int mid = (low + high) / 2;
	
	while (low < high)
	{
		mid = (low + high) / 2;
		if (key > a[mid])
		{
			low = mid + 1;
		}
		if (key < a[mid])
		{
			high = high - 1;
		}
		if (key == a[mid])
		{
			return mid;
		}
	}
}	
int main()
{
	int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	int key; //Ҫ��������

	cin >> key;

	cout << "The position of key is��" << BinarySearch1(a, 0, 7, key) << endl;
	cout << "The position of key is: " << BinarySearch2(a, 8, key) << endl;
	
	system("pause");
	return 0;

}