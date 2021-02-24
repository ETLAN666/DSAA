#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	long long int i,j,k,n,m,t=0,res,r,l,temp,S;
	cin>>n>>S;
	long long int array[n];
	for(i=0;i<n;i++)
	{
		cin>>array[i];
	}
	for(i=0;i<=n-3;i++) 
	{
	for(j=i+1;j<=n-2;j++)
	{
	m=j+1;
	res=S-array[i]-array[j];
	if(res<array[j+1]||res>array[n-1])
	{
	temp=0;
	}
	else if(res==array[n-1])
	{
	r=r=lower_bound(array+m,array+n,res)-array;
	l=n;
	temp=l-r;
	}
	else
	{
	r=lower_bound(array+m,array+n,res)-array;
	l=upper_bound(array+m,array+n,res)-array;
	temp=l-r;
    }
	t=t+temp;
    }
    }
	
	printf("%d",t);
		
	return 0;
}
