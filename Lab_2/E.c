#include<stdio.h>

int Fabich(int n)
{
		if(n<=3)
		return 1;
		return Fabich(n/2-1) +Fabich(n/2)+Fabich(n/2+1);	
}

int main()
{
	int i,j,n,F,T;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&n);
		F=Fabich(n);
		printf("%d\n",F);
	}
	return 0;
}
