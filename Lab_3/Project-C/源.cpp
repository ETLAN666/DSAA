#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef long long int ll;

void insert(ll a[],ll n,ll *p1)
{
	ll temp;
	ll i,j,f1 = 1, f2 = 0, sum = 0;
	for ( i = 1; i < n; i++)
	{
		j= i;
		temp = a[i];
		for (; temp < a[j - 1] && j >= 1;f1++)
		{
			a[j] = a[j - 1];
			j--;
			f2++;
		}
		a[j] = temp;

		/*while (temp < a[j - 1] && j >= 1)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;*/
		sum = f1 + f2;
		*p1 = sum;

	}
}void SelectSort(ll a[], ll n,ll *p2)
{
	ll i,f1=0,f2=0,sum=0;
	for (i = 0; i < n - 1; i++)
	{
		ll k = i;//记录最小的那个下标的 
		ll j;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[k])
				k = j;
			f1++;
		}
		if (k != i)
		{
			ll t = a[i];
			a[i] = a[k];
			a[k] = t;
			f2++;
		}

	}
	sum = f1 + f2;
	*p2 = sum;
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
		SelectSort(bb, n, &b);
		display(aa, n);
		cout<<a<<" "<<b<<endl;
		compare(a, b);
	}
	return 0;
	

}
