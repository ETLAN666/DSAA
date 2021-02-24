#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef long long int ll;

ll MergeArray(ll arry[],ll start,ll mid,ll end,ll temp[])
{
	//����Ĺ鲢����
	ll i=mid;
	ll j=end;
    ll k=0;//��ʱ����ĩβ����
    ll count=0;
    //�趨����ָ��ij�ֱ�ָ���������������ͷԪ�أ���С����һ�����뵽��ʱ������ȥ��
    while(i>=start&&j>mid){
        if(arry[i]>arry[j]){
            temp[k++]=arry[i--];//����ʱ��������һ��λ�ÿ�ʼ����
            count+=j-mid;      
        }
        else
            temp[k++]=arry[j--];
    }
    while(i>=start)//��ʾǰ��������л���Ԫ��δ������ʱ����
	{
        temp[k++]=arry[i--];
    }
    while(j>mid){
        temp[k++]=arry[j--];
    }
    for(i=0;i<k;i++){
    	arry[end-i]=temp[i];//����ʱ�����е�Ԫ��д�ص�ԭ���鵱��ȥ��
    }
    return count;
}
ll InversePairsCore(ll arry[],ll start,ll end,ll temp[])
{
    ll inversions = 0;  
    if(start<end){
        ll mid=(start+end)/2;
        inversions+=InversePairsCore(arry,start,mid,temp);//�����ε��������Ŀ
        inversions+=InversePairsCore(arry,mid+1,end,temp);//���Ұ�ε��������Ŀ
        inversions+=MergeArray(arry,start,mid,end,temp);//������֮�������ԡ���С�������ֻ��һ��Ԫ��
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
