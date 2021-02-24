#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int BinarySearch(int data[],int n, int low, int high, int k)
{
    while (low<=high)
    {
        int m = (high + low) / 2;
        if (data[m] == k)return m;
        else if (data[m] < k) low = m+ 1;
        else high = m - 1;
    }
    return -1;
}
    int GetNumberOfK(int data[],int n,int low,int high,int k) {
        int KeyIndex=0;
        int len=n;
         
        KeyIndex=BinarySearch(data,n,low,high,k);
       if(KeyIndex==-1) return 0;
        int sumber=1;
        int m=KeyIndex-1;
        int q=KeyIndex+1;
       
       while(m>=0&&data[m]==k)
        {
                m--;sumber++;
            }
        while(q<len&&data[q]==k)
        {
               q++; sumber++;
            }
        return sumber;
    }

int main()
{
	int i,j,k,n,m,t=0,res,r,l,temp,S;
	cin>>n>>S;
	int array[n];
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
	temp=GetNumberOfK(array,n,j+1,n-1,res);
	t=t+temp;
    }
    }
	printf("%d",t);
		
	return 0;
}
