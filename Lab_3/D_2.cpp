#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef long long int ll;

ll MergeArray(ll arry[],ll start,ll mid,ll end,ll temp[])
{
	//数组的归并操作
	ll i=mid;
	ll j=end;
    ll k=0;//临时数组末尾坐标
    ll count=0;
    //设定两个指针ij分别指向两段有序数组的头元素，将小的那一个放入到临时数组中去。
    while(i>=start&&j>mid){
        if(arry[i]>arry[j]){
            temp[k++]=arry[i--];//从临时数组的最后一个位置开始排序
            count+=j-mid;      
        }
        else
            temp[k++]=arry[j--];
    }
    while(i>=start)//表示前半段数组中还有元素未放入临时数组
	{
        temp[k++]=arry[i--];
    }
    while(j>mid){
        temp[k++]=arry[j--];
    }
    for(i=0;i<k;i++){
    	arry[end-i]=temp[i];//将临时数组中的元素写回到原数组当中去。
    }
    return count;
}
ll InversePairsCore(ll arry[],ll start,ll end,ll temp[])
{
    ll inversions = 0;  
    if(start<end){
        ll mid=(start+end)/2;
        inversions+=InversePairsCore(arry,start,mid,temp);//找左半段的逆序对数目
        inversions+=InversePairsCore(arry,mid+1,end,temp);//找右半段的逆序对数目
        inversions+=MergeArray(arry,start,mid,end,temp);//找两段之间的逆序对。最小的逆序段只有一个元素
    }    
    return inversions;
}
ll InversePairs(ll arry[],ll len)
{
    ll *temp;
    temp = (ll*)calloc(len, sizeof(ll));
    
    ll count=InversePairsCore(arry,0,len-1,temp);
    free(temp);
    return count;
}


int main()
{
	ll count,T;
	scanf("%lld",&T);
	while (T--)
	{
		ll i,n,*aa;
		scanf("%lld",&n);
		aa = (ll*)calloc(n, sizeof(ll));
		for (i = 0; i < n; i++)
		{
			scanf("%lld",&aa[i]);
		}
		count=InversePairs(aa,n);
        
        cout << count<<endl;
	}
	return 0;
}
