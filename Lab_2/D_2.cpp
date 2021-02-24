#include <bits/stdc++.h>
using namespace std;

/*
1.����2�ַ���ܣ����ֵ��M�ĸ������Ǹ���أ��߼���һЩ
2.Guess�����ڲ��߼����ӣ����ദ��ȷ��box��������ÿ��box��װ����Ԫ��
3.����ȫ0���������⴦���
*/

int Guess(int mid, int* nums, int numsSize, int m)
{
	long long sum = 0;
	int cnt = 0;
    bool need = false; // need last 1 box
	for (int i = 0; i < numsSize; i++) {
        if (mid < nums[i]) {
            return 0;
        }
        // to box
        int tmp = sum + nums[i];
        //printf("%d: cnt=%d, sum=%d, nums[i]=%d, mid=%d tmp=%d\n", __LINE__, cnt, sum, nums[i], mid, tmp);
        if (tmp < mid) {
            sum += nums[i];
            need = true; // last one need a new box
        } else if (tmp == mid) {
            cnt++;
            need = false; // last one into last box
            sum = 0;
        } else {
            cnt++;
            need = true; // last one need a new box
            sum = nums[i];
        }
        //printf("%d: cnt=%d, sum=%d, nums[i]=%d, mid=%d tmp=%d\n", __LINE__, cnt, sum, nums[i], mid, tmp);
    }
    //printf("%d: cnt=%d, sum=%d, mid=%d need=%d\n", __LINE__, cnt, sum, mid, need);
    return cnt + need <= m;
}

long long Add(int* nums, int numsSize)
{
	long long sum = 0;
	for (int i = 0; i < numsSize; i++) {
		sum += nums[i];
	}
	return sum;
}

int splitArray(int* nums, int numsSize, int m)
{
	int left = 0;
	long long right = Add(nums, numsSize) + 1;
    if (right == 1) {
        return 0;
    }
	int mid;
	int ret;
	while (left < right) {
		mid = (left + right) / 2;
        int guess = Guess(mid, nums, numsSize, m);
        //printf("%d: left=%d, right=%d, mid=%d, guess=%d\n", __LINE__, left, right, mid, guess);
		if (guess){
			ret = mid;
			right = mid;
            //printf("%d: left=%d, right=%d, mid=%d, ret=%d\n", __LINE__, left, right, mid, ret);
		} else {
			left = mid + 1;
            //printf("%d: left=%d, right=%d, mid=%d\n", __LINE__, left, right, mid);
		}
	}
	return ret;
}


int main()
{
	int i,j,ans,n,m,L;
	cin>>n>>m>>L;
	int array[n];
	for(i=0;i<n;i++)
	cin>>array[i];//��Ҫ�ٽ���һ�������� 
	int berray[n];
	for(j=0;j<n-1;j++)
	berray[j]=array[j+1]-array[j];
	berray[n-1]=L-array[n-1];
	ans=splitArray(berray,n, m);
	cout<<ans;
	return 0;
}

