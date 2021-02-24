/*
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int T,x,y;
	scanf("%d", &T);
	while (T--)
	{
		int cnt = 0;
		scanf("%d%d", &x, &y);
		while (x != y)
		{
			if (x > y)
			{
				x = x / 2;
				cnt++;
			}
			else if (x < y)
			{
				y = y / 2;
				cnt++;
			}		
		}
		printf("%d\n", cnt);
	}
	return 0;
}
*/
