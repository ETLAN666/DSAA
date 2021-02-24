#include<stdio.h>
#include<string.h>

#define MAXN 1000000

int F[MAXN];
int fib(int n){
	if (n==1) return F[1]=1;
	if (n==2) return F[2]=1;
	if (n==3) return F[3]=1;
	if(F[n]>=0) return F[n];
	else return F[n]=fib(n/2-1)+fib(n/2)+fib(n/2+1);
}

int main(){
	memset(F,-1,sizeof(F)); 
	
	int n,T,ans;
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	 ans=fib(n);
	printf("%d\n",ans);
          }
	return 0;
} 

