#include<stdio.h>

long int hanoi( int n)
{
	int i;
	long int t=0;
	for(i=0;i<n;i++)
	{
		t=3*t+2;
		t=t%1000000007;
	}
	return t;
}

int main()
{
	int i,T,n;
	long int temp;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&n);
		temp=hanoi(n);
		printf("%ld\n",temp);
	}
	return 0;
}
