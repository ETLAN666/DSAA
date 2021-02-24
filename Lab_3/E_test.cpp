#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath> 

using namespace std;

typedef long long int ll;

ll n,sum=0,p,q,*hp,*ak,*a1;

ll Find_Max(ll array[],ll n)
{
    ll i,max=array[0],t=0;
    for(i=0;i<n;i++)
    {
        if(array[i]>max)
        {
            max=array[i];
            t=i;
        }
    }
    return t;
}

void Copy(ll a[],ll b[], ll n)
{
    ll i;
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
    }
}

ll Solve(ll a2[],ll hp2[],ll ak2[],ll dex)
{
    ll k,res,temp=0,ans=0;
    Copy(hp,hp2,n);
    Copy(ak,ak2,n);
    res=q;
    if(res>0)
    {
        if(a1[dex]>0)
        temp+=a1[dex];
        hp2[dex]=0,ak2[dex]=0;
        res--;
    }
    for(k=0;k<n;k++)
    {
        a2[k]=hp2[k]-ak2[k];
        if(a2[k]<0)
        a2[k]=0;
    }
    sort(a2,a2+n);
    for(k=n-1;res>0&&k>=0;k--)
    {
        temp+=a2[k];
        res--;
    }
    ans=sum+temp;
    return ans;
}

int main()
{
	ll i,ans=0,temp=0,res;
	scanf("%lld%lld%lld",&n,&p,&q);
	ll *hp2,*ak2,*a2,*a3;
    ll dex=0;
	hp = (ll*)calloc(n, sizeof(ll));
    hp2 = (ll*)calloc(n, sizeof(ll));
	ak = (ll*)calloc(n, sizeof(ll));
    ak2 = (ll*)calloc(n, sizeof(ll));
	a1 = (ll*)calloc(n, sizeof(ll));
    a2 = (ll*)calloc(n, sizeof(ll));
    a3 = (ll*)calloc(n, sizeof(ll));
	for (i = 0; i < n; i++)
	{
		scanf("%lld%lld",&hp[i],&ak[i]);
	}//初始化赋值输入
	for (i = 0; i < n; i++)
	{
		a1[i]=hp[i]*pow(2,p)-ak[i];
		sum+=ak[i];
	}//通用数组和数据
    for(i=0;i<n;i++)
    {
        a3[i]=Solve(a2,hp2,ak2,i);
    }
    sort(a3,a3+n);
    cout<<a3[n-1];
	return 0;
}
