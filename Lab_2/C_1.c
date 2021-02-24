#include<stdio.h> 

int Find(long int A[],int n,int m,int key)
{
 	int i,j,low=m,high=n-1,mid,temp=0,dex=0,up=-1,down=-1;
 	if(A[low]>key)
 	    return 0;//情况1 
 	else if(A[low]==key&&A[high]>key)
 	    {
  		
   			mid=(low+high)/2;
   			if(A[mid]==key)
   			{
    				for(i=mid;i<n;i++)
    				{
    					if(A[i]>key)
    					{
    					dex=i-1;
						break;
    				    }
					}
    		}
						
   			else if(A[mid]>key)
    		{
    			     for(i=mid;i>0;i--)
    			     {
    			     	if(A[i]==key)
    			     	{					
    			     	dex=i;
						break;
					    }
					 }
    					
			}	
 	     	return  (dex-m+1);
		}//情况2 
 	else if(A[low]==key&&A[high]==key)
  		return (high-low+1);//情况3 
 	else if(A[low]<key&&A[high]>key)
 	    { 
  		
   			mid=(low+high)/2;
   			if(A[mid]==key)
   			{
    				for(i=mid;i<n;i++)
    				{
    					if(A[i]>key)
    					{
    					up=i-1;
						break;
					    }
					}
					for(j=mid;j>0;j--)
					{
						if(A[j]<key)
						{
						down=j+1;
						break;
					    }
					}
					if(up==-1)
   			        return 0;
   			        else 
					return (up-down+1);		
    		}
						
   			else if(A[mid]>key)
    		{
    			     for(i=mid;i>0;i--)
    				{
    					if(A[i]==key)
    					{
    					up=i;
						break;
    				    }
					}
					for(j=mid;j>0;j--)
					{
						if(A[j]<key)
						{
						down=j+1;
						break;
					    }
					}	
    				if(up==-1)
   			        return 0;
   			        else 
					return (up-down+1);	
			}	
   			
		}//情况4 
	else if(A[low]<key&&A[high]==key)
	{
  		
   			mid=(low+high)/2;
   			if(A[mid]==key)
   			{
    				for(i=mid;i>0;i--)
    				{
    					if(A[i]<key)
    					{
    					dex=i+1;
						break;
    				    }
					}
    		}
						
   			else if(A[mid]<key)
    		{
    			     for(i=mid;i<n;i++)
    			     {
    			     	if(A[i]==key)
    			     	{					
    			     	dex=i;
						break;
					    }
					 }
    					
			}	
 	     	return  (n-dex);
		}//情况5 
 	
 	else if(A[high]<key)
 	     return 0;//情况6 
 	
}

int main()
{
	int i,j,k,n,m,t=0,res,r,S;
	scanf("%d%d",&n,&S);
	long int array[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	for(i=0;i<=n-3;i++) 
	{
	for(j=i+1;j<=n-2;j++)
	{
	res=S-array[i]-array[j];
	m=j+1;
	r=Find(array,n,m,res);
	t=t+r;
    }
    }
	printf("%d",t);
	
	return 0;
}
