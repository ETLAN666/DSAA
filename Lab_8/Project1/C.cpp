/*
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
struct node {
	ll p;
	ll d;
}a[110000];
ll n;
ll ans;
ll maxd;
ll pa[110000];
bool cmp(node a, node b) {
	return a.p > b.p;
}
ll find(ll x) {
	return x == pa[x] ? x : find(pa[x]);
}
int main() {
	int T;
	//cin >> T;
	scanf("%d", &T);
	while (T--) {
		//cin >> n;
		scanf("%d", &n);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			//cin >> a[i].p;
			scanf("%lld", &a[i].p);
		}
		for (int i = 1; i <= n; i++) {
			//cin >> a[i].d;
			scanf("%lld", &a[i].d);
			maxd = max(maxd, a[i].d);
		}
		for (int i = 1; i <= maxd; i++)
			pa[i] = i;
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= n; i++) {
			ll x = find(a[i].d);
			if (pa[x] > 0) {
				pa[x]--;
				ans += a[i].p;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
*/
