#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath> 

using namespace std;

typedef long long int ll; 

void Find_Max(ll array[],ll n,ll *dex)
{
    ll i,max=array[0];
    for(i=0;i<n;i++)
    {
        if(array[i]>max)
        {
            max=array[i];
            *dex=i;
        }
    }
}

int main()
{
	ll i,n, p, q,sum=0,ans=0,temp=0,res;
	scanf("%lld%lld%lld",&n,&p,&q);
	ll *hp,*ak,*a1,*a2;
    ll dex;
	hp = (ll*)calloc(n, sizeof(ll));
	ak = (ll*)calloc(n, sizeof(ll));
	a1 = (ll*)calloc(n, sizeof(ll));
    a2 = (ll*)calloc(n, sizeof(ll));
	for (i = 0; i < n; i++)
	{
		scanf("%lld%lld",&hp[i],&ak[i]);
	}
	for (i = 0; i < n; i++)
	{
		a1[i]=hp[i]*pow(2,p)-ak[i];
		sum+=ak[i];
	}
    Find_Max(a1,n,&dex);
    res=q;
    if(res>0)
    {
        if(a1[dex]>0)
        temp+=a1[dex];
        hp[dex]=0,ak[dex]=0;
        res--;
    }
    for(i=0;i<n;i++)
    {
        a2[i]=hp[i]-ak[i];
        if(a2[i]<0)
        a2[i]=0;
    }
    sort(a2,a2+n);
    for(i=n-1;res>0&&i>=0;i--)
    {
        temp+=a2[i];
        res--;
    }
    for(i=0;i<n;i++)
    {
    	printf("%lld",a2[i]);
	}
    ans=sum+temp;
    cout<<ans;
	return 0;
}
