#include<stdio.h>

int main()
{
	int i,m,n,T;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d%d",&m,&n);
		if(n==1&&m==1)
		printf("Bob\n");
		else if(n==2&&m>=3)
		printf("Bob\n");
		else if(m==2&&n>=3)
		printf("Bob\n");
		else
		printf("Alice\n");	
	}
	return 0;
 } 
