#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

typedef long long int ll; 

int main()
{
	ll i,n, p, q,sum=0,ans=0,temp=0,res,r;
	scanf("%lld%lld%lld",&n,&p,&q);
	ll* hp, * ak,*a1,*a2;
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
		a1[i]=hp[i]-ak[i];
		a2[i]=2*hp[i]-ak[i];
		sum+=ak[i];
	}
	
	for (i = 0; i < n; i++)
	{
		if(a1[i]<0)
		   a1[i]=0;
		if(a2[i]<0)
		   a2[i]=0;
	}
	sort(a1,a1+n);
	sort(a2,a2+n);
	if(p<=q)
	{
		res=q-p;
		r=p;
	   for (i =n-1; i >=0&&p>0; i--)
	  {
	        temp+=a2[i];
	        p--;
	  }
	  for(i=n-1-r;i>=0&&res>0;i--)
	  {
	  	    temp+=a1[i];
	  	    res--;
	  }
    }
	else if(p>q)
	{
		res=p-q;
		r=q;
	   for (i =n-1; i >=0&&q>0; i--)
	  {
	        temp+=a2[i];
	        q--;
	  }
    }
	ans=sum+temp;
	cout<<ans;	
	return 0;
}
