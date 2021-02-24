#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef long long int ll;



void select(ll a[],ll n,ll*p1)
{
	ll i,k,j,f1=0,f2=0,sum=0;
	for(i=0;i<=n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			f1++; 
			if(a[k]>a[j])
			   k=j;
		}
		swap(a[i],a[k]),f2++;		
	}	
	sum=f1+f2;
	*p1=sum;
}

void insert(ll a[],ll n ,ll*p2)
{
	ll i,j,f1=0,f2=0,sum=0;
	for(i=1;i<n;i++)
	{
		for(j=i;j-1>=0;j--)
		{
			f1++;
			if(a[j-1]>a[j])
			swap(a[j-1],a[j]),f2++;
			else
			break;
		}
	}
	sum=f1+f2;
	*p2=sum;
}




void display(ll array[], ll size)
{
	ll i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void compare(ll a, ll b)
{
	if (a < b)
		printf("Insertion Sort wins!\n");
	else
		printf("Selection Sort wins!\n");
}

int main()
{
	ll T,a,b;
	cin >> T;
	while (T--)
	{
		ll i,n,*aa,*bb;
		cin >> n;
		aa = (ll*)calloc(n, sizeof(ll));
	    bb = (ll*)calloc(n, sizeof(ll));
		for (i = 0; i < n; i++)
		{
			cin >> aa[i];
			bb[i] = aa[i];
		}
		insert(aa, n,&a);
		select(bb, n, &b);
		display(aa, n);
		compare(a, b);
	}
	return 0;
	

}
