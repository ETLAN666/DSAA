/*
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>

using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}


int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int cnt = n;
	int cut = 0,temp=0;
	int c[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
	}
	sort(c, c + n,cmp);
	for (int i = 0; i < n; i++)
	{
		if (cnt >= m)
			break;
		if (c[i] > 3)
		{
			temp = c[i] / 2;
			cnt = cnt + temp - 1;
			cut = cut + temp;	
		}	
		if (cnt > m)
		{
			temp = cnt - m;
			cut = cut - temp;
		}
			
	}
	if (cnt >= m)
		printf("%d",cut);
	else
		printf("impossible");

	return 0;
}
*/