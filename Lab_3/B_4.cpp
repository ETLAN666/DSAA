#include<iostream>
#include<cstdio>
#include<cstdlib>
 
using namespace std;
 
 int partion1(int A[],int low,int high)
{
	int pivot = A[low];
	while(low < high)
	{
		while(low < high && A[high] >= pivot)
			--high;
		A[low] = A[high];
		while(low < high&&A[low] <= pivot)
			++low;
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}

int find_k_small(int A[], int low, int high,int k)
{
	if(low <=high)
	{
		int pivot_pos = partion1(A, low, high);
		if(pivot_pos + 1 == k)
			return A[pivot_pos];
		else if(pivot_pos + 1 > k)
			find_k_small(A, low, pivot_pos - 1, k);
		else
			find_k_small(A, pivot_pos + 1, high, k);
	}
	else
		return -1;
	
}
 
int main()
{
	int i,n, k,ans,*aa,*bb;
	cin >> n >> k;
	aa = (int*)calloc(n, sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d",&aa[i]);	
	ans=find_k_small(aa, 0, n-1,k);
	cout << ans << endl;
	free(aa);
	return 0;
}
