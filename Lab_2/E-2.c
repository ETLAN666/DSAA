#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,n,F,T;
	int t,array[100];
	for(i=0;i<3;i++)
	array[i]=1;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&n);
		if(n<=3)
		{
		t=1;
		printf("%d\n",t);
	    }
		else if(n>=4)
	   {
	   for(j=4;j<n;j++)
	{
		array[j]=array[j/2-1]+array[j/2]+array[j/2+1];
	}
	    t=array[j];
		printf("%d\n",t);
	}
}
	return 0;
}
