#include <bits/stdc++.h>
using namespace std;

long long int splitArray(long long int* nums,long long int numsSize,long long int m){
    long long int max = nums[0];
    long long int sum = nums[0];
    long long int i;
    for ( i = 1; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
        sum += nums[i];
    }
    
    long long int left = max;
    long long int right = sum;
    
    while (left < right) {
        long long int mid = left + (right - left) / 2;
        long long int cnt = 1;  
        long long int tmp = 0;
        for ( i = 0; i < numsSize; i++) {
            tmp += nums[i];
            if (tmp > mid) {
                tmp = nums[i];
                cnt++;
            }
        }
        
        if (cnt > m) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}


int main()
{
	long long int i,ans,n,m,L;
	cin>>n>>m>>L;
	long long int array[n];
	for(i=0;i<n;i++)
	cin>>array[i];
	ans=splitArray(array,n, m);
	cout<<ans;
	return 0;
}

