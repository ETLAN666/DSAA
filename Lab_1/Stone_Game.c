#include<stdio.h> 
#include<math.h>
int main ()
{
    int i,j,n,qs,t,T;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {    
        t=0; 
    	scanf("%d",&n);
    	for(j=0;j<n;j++)
    	{
    		scanf("%d",&qs);
    		t^=qs;
		}
		if(t==0)
		printf("%d\n",0);
		else
		printf("%d\n",1);
	}
    return 0; 
}
