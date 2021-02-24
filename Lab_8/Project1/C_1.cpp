/*
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long
const int inf = 0x3f3f3f3f;
const int maxn = 100010;
#define eps 1e-8

struct node
{
    int p, d;
} a[maxn];

bool cmp(node x, node y)
{
    return x.p > y.p;
}

int n;
int vis[maxn], pre[maxn];

int Find(int x)
{
    return pre[x] == -1 ? x : pre[x] = Find(pre[x]);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
       // cin >> n;
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));
        memset(pre, -1, sizeof(pre));
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i].p);
            //cin >> a[i].p ;

        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i].d);
            //cin >> a[i].d;
        sort(a + 1, a + n + 1, cmp);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int tmp = Find(a[i].d);
            if (tmp > 0)
            {
                ans += a[i].p;
                pre[tmp] = tmp - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
*/
