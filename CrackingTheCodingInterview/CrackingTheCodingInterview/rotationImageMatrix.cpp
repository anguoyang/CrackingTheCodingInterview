#include <iostream>
#include <cstring>

using namespace std;

void swap (int *a, int *b)
{
	*a = (*a) ^ (*b);
	*b = (*a) ^ (*b);
	*a = (*a) ^ (*b);

}
void rotationImageMatrix(int a[4][4])
{
	int i, j;
	//�Խ����Ȼ���
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 4; j++)
		{
				swap(&(a[i][j]), &(a[j][i]));
		}
	}
	//1,4�л�����2,3�л���
	for (j = 0; j < 4; j ++)
	{
		//�������4 * 4�������д��һ��ʽ��
		swap(&(a[0][j]), &(a[3][j]));
		swap(&(a[1][j]), &(a[2][j]));
	}
}
int main()
{
	int c = 12, b = 12;
	int a[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16} };
	
	rotationImageMatrix(a);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << a[i][j] << " ";
			
		}
		cout << endl;
	}
	return 0;
}