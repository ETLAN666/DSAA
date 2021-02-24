#include <iostream>
#include <algorithm>
#include <cmath>
#include<cstdio>

using namespace std;

typedef long long int ll;
ll n, x1, x2;

typedef struct lines
{
	ll k;
	ll b;
	ll y1;
	ll y2;
}lines;

bool cmp(lines a,lines b)
{
     return (a.y1) == (b.y1)?a.y2<b.y2:a.y1<b.y1;
}


int main()
{
	ll i,j,mark=0;
	scanf("%lld",&n);
	scanf("%lld%lld", &x1, &x2);
	lines a[n];
	for (i = 0; i <n; i++)
	{
		scanf("%lld%lld", &a[i].k, &a[i].b);
		a[i].y1=a[i].k*x1+a[i].b;
		a[i].y2=a[i].k*x2+a[i].b;	
	}
	sort(a,a+n,cmp);	
	for(i=0;i<n-1;i++) 
	{
		if(a[i].y2>a[i+1].y2)
		{
			//for(j=i;j>0;j--)
			//if(a[j].y1<a[i+1].y1)
			//{
		       mark++;
		       //break;
		   // }
	    }
		if(mark>0)
		   break;		   
	}	
	if (mark >= 1)
		cout << "YES";
	else
		cout << "NO";
		
	return 0;
}
