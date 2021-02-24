#include<stdio.h>

int main(){
	int i,t,T,a,b,n;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
	scanf("%d%d%d",&a,&b,&n);
	
    if(n%3==1)
    printf("%d",b);
   else if(n%3==2)
	{
	 t=a^b;
	 printf("%d",t);
    }
    else if(n%3==0)
    printf("%d",a);	
    printf("\n");
	}
	return 0;
 } 
