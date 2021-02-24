#include<stdio.h>

int main()
{
	int i,T;
	long long int j,n,F,Out;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%lld",&n);
		j=(n*(n+1)/2)%(7+1000000000);
		F=j*j;
		Out=F%(7+1000000000);	
		printf("%lld\n",Out);
	}
	return 0;
 } 
