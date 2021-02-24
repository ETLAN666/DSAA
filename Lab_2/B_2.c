#include<stdio.h>
#include<string.h>

int search(int A[],int n,int key)
{
 	int low=0,high=n-1,mid;
 	if(A[low]==key)
  		return low;
 	else if(A[high]==key)
  		return high;
 	else
 	{
  		while(low<=high)
  		{
   			mid=(low+high)/2;
   			if(A[mid]==key)
    				return mid;	
   			if(key>A[mid])
    				low=mid+1;	
   			else
    				high=mid-1;	
  		}
 	}
 	return -1;	
}

int Search(int A[],int n,int key)
{
 	int Q,low=0,high=n-1,mid;
 	if(A[low]==key)
  		return low;
 	else if(A[high]==key)
  		return high;
 	else
 	{
  		while(low<=high)
  		{
   			mid=(low+high)/2;
   			if(A[mid]==key)
    				return mid;	
   			if(key>A[mid])
    				low=mid+1;	
   			else
    				high=mid-1;	
  		}
  		if(low>high)
  		Q=high;
  		else 
  		Q=low;
 	}
 	
 	return Q; 
}


int main(){

	
	int i,j,e,N,T,temp,res,dex;
	scanf("%d%d",&N,&T);
	int array[N];
	for(i=0;i<N;i++)
		scanf("%d",&array[i]);
	while(T--)
	{
	scanf("%d",&e);
	temp=search(array,N,e);
	if(temp!=-1)
	printf("Accept\n");
	else if(temp==-1)
	{
		dex=Search(array,N,e);
		res=e-array[dex];
		printf("%d\n",res);
    }   
     }
	return 0;	
}


