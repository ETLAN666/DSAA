#include<stdio.h>

int mp[400][400];

 void draw(int a,int b,int c)
 {
 	char ch='.',th='|',gh='/',lh='+',ph='-';
 	int i,j,k=0;
 	for(i=0,k=2*b;i<2*b;i++){
 	for(j=0;j<k;j++)
 	mp[i][j]=ch;
 	k--;
    }
 	for(i=2*c+1,k=0;i<2*c+2*b+1;i++)
 	{
	 for(j=2*a+2*b-k;j<2*a+2*b+1;j++)
	 mp[i][j]=ch;
	 k++;
    }
	for(i=2*b+2-1;i<2*c+2*b+1;i+=2) 
	for(j=2-1;j<2*a+1;j+=2)
	{
	  mp[i][j]=ch;
	  mp[i][j-1]=th; 
	  mp[i-1][j-1]=lh;
	  mp[i-1][j]=ph;
			  }
			  
	for(i=2-1,k=2*b;i<2*b;i+=2) 
	{
	for(j=0;j<2*a;j+=2){
	mp[i][j+k]=ch;
	mp[i][j+k-1]=gh;
	mp[i-1][j+k]=lh;
	mp[i-1][j+k+1]=ph;
    }
	k=k-2;
	}
	for(j=2*a+1,k=0 ;j<2*a+2*b+1;j+=2) {
	for(i=2*b-k;i<2*b+2*c-1-k;i+=2)
		{
		 mp[i][j]=ch;
		 mp[i-1][j]=gh;
		  mp[i-1][j+1]=th;
		 mp[i][j+1]=lh;
	   }
		k=k+2;
	}
 	for(j=0;j<2*a;j+=2)
 	{
 		mp[2*c+2*b][j]=lh;
 		mp[2*c+2*b][j+1]=ph;
	 }
	 mp[2*c+2*b][2*a]=lh;
	 for(i=2*b+2-1;i<2*c+2*b+1;i+=2) {
	 mp[i][2*a]=th;
	 mp[i-1][2*a]=lh;
	 } 
	 for(i=0,j=2*a+2*b;i<2*b-1;i+=2,j=j-2)
	 mp[i][j]=lh;
	 for(i=2*c+2*b-1,j=2*a+1;j<2*a+2*b+1;i=i-2,j=j+2) 
 	mp[i][j]=gh;
 }
 
 void printscreen(int a,int b,int c)
 {
 	int i,j;
 	for( i=0;i<2*c+2*b+1;i++ )
 	{
 		for(j=0;j<2*a+2*b+1;j++)
 		printf("%c",mp[i][j]);
 		printf("\n");
	 }
 }
 
 int main()
 {
 	int i,T,a,b,c;
 	scanf("%d",&T);
 	for(i=0;i<T;i++){
 	scanf("%d%d%d",&a,&b,&c);
 	draw(a,b,c);
 	printscreen(a,b,c);
 	printf("\n");
 }
 	return 0;
 } 
