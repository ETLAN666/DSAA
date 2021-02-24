#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

void bubble_sort_better(int a[], int n,int *p)//n为数组a的元素个数
{
    int f1=0;
    //最多进行N-1轮比较
    for (int i = 0; i < n - 1; i++)
    {
        bool isSorted = true;
        //每一轮比较前n-1-i个，即已排序好的最后i个不用比较
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
        if (isSorted) break; //如果没有发生交换，说明数组已经排序好了
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