#include<stdio.h>
#include<string.h>


#define N 100000


int main()
{
	char a[N],b[N],c[N],d[N][N]; 
	memset(c, 0, 80);
	int i,j,m,n,t,k; 
	gets(a); 
	gets(b);
	
	m=strlen(a); 
	n=strlen(b);
 
	int nFlag = 0;
	k = 0;
	int nTemp = 0;
	
	for(i=0;i<m;i++)    
	{
		nFlag = 0;
		t=0; 
		nTemp = i;
		for(j=0;j<n;j++)    
		{        
			if(a[i]==b[j])        
			{      
				nFlag = 1;           
				c[t]=a[i];            
				t=t+1;           
				i=i+1;            
			
			}
			else 
			{
				if (nFlag == 1)
				{
					strcpy(d[k++], c);
					memset(c, 0, 80);
					nFlag = 0;
					t=0;
					i = nTemp;
					j=j-1;
				}
				
			}
		}
		if (nFlag == 1)
		{
			strcpy(d[k++], c);
			memset(c, 0, 80);
			i = nTemp;
		}
	}
	strcpy(c,d[0]);
	for(i=1;i<k-1;i++)    
	{       
		if(strlen(c)<strlen(d[i]))            
			strcpy(c,d[i]);
	}    
	int ans=strlen(c);
	printf("%d",ans);
	return 0; 
}
