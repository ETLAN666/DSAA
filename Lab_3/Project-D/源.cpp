#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

void bubble_sort_better(int a[], int n,int *p)//nΪ����a��Ԫ�ظ���
{
    int f1=0;
    //������N-1�ֱȽ�
    for (int i = 0; i < n - 1; i++)
    {
        bool isSorted = true;
        //ÿһ�ֱȽ�ǰn-1-i������������õ����i�����ñȽ�
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                isSorted = false;
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                f1++;

            }
        }
        if (isSorted) break; //���û�з���������˵�������Ѿ��������
    }
    *p = f1;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int i,n,*aa,b;
		cin >> n;
		aa = (int*)calloc(n, sizeof(int));
		for (i = 0; i < n; i++)
		{
			cin >> aa[i];
		}
        bubble_sort_better(aa, n, &b);
        cout << b;
	}
	return 0;
}