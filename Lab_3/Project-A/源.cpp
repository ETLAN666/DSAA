#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
typedef long long int ll;

 int merge(ll* a, int m, ll* b, int n, ll* c)
{
	int i = 0, j = 0, k = 0;
	

	while (i < m && j < n) {
		if (a[i] < b[j]) {
			c[k++] = a[i++];
		}
		else {
			c[k++] = b[j++];
		}
	}

	while (i < m) {
		c[k++] = a[i++];
	}
	while (j < n) {
		c[k++] = b[j++];
	}
	return 0;
}


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int i,n, m;
		cin >> n >> m;
		ll* aa, * bb,*cc;
		aa = (ll*)calloc(n, sizeof(ll));
		bb = (ll*)calloc(m, sizeof(ll));
		cc = (ll*)calloc(m + n, sizeof(ll));
		for (i = 0; i < n; i++)
			cin >> aa[i];
		for (i = 0; i < m; i++)
			cin >> bb[i];
		merge(aa, n, bb, m, cc);
		for (i = 0; i < m + n; i++)
			cout<<cc[i]<<" ";
			printf("\n");
		free(aa);
		free(bb);
		free(cc);

	}
	return 0;
}
