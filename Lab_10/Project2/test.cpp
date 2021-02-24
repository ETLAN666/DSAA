#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include<cmath>
using namespace std;
int n, m, u, v, t, Head[110010], Next[250010], cnt = 1, to[250010], dnf[210010], low[210010], s[210010], top, cir[210010], num, out[210010];
int sum[210010], d[110000];
vector<int> edge[210000];
struct grip
{
    int x, y;
    double V, T;
    bool operator<(const grip& b) const
    {
        return (T == b.T) ? V<b.V : t>b.T;
    }
};
inline void Add(int x, int y);

void Tarjan(int x);
void FCT();

int main()
{
    FCT();
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    FCT();
    for (int i = 1; i <= m; i++)
        scanf("%d", &d[i]);

    for (int i = 1; i <= m; i++)
        for (int j = 0; j < edge[i].size(); j++)
            if (d[i] + 1 == d[edge[i][j]] || abs(d[i] + 1 - d[edge[i][j]]) % t == 0)
                Add(i, edge[i][j]);

    memset(low, 0x3f3f3f3f, sizeof(low));
    cnt = 1;
    FCT();
    for (int i = 1; i <= m; i++)
    {
        if (!dnf[i]) Tarjan(i);
    }
    for (int i = 1; i <= m; i++)
    {
        if (!out[cir[i]])
        {
            for (int j = Head[i]; j; j = Next[j])
            {
                int y = to[j];
                if (cir[y] != cir[i])
                {
                    out[cir[i]]++;
                    break;
                }
            }
        }
    }
    int ans = m;
    for (int i = 1; i <= num; i++)
        if (out[i] == 0)
            ans = min(ans, sum[i]);
    cout << ans;
    FCT();
}

inline void Add(int x, int y)
{
    to[++cnt] = y;
    Next[cnt] = Head[x];
    Head[x] = cnt;
}
void FCT()
{
    int Num = 0;
    for (int i = 0; i < 10; i++)
    {
        Num++;
    }
}

void Tarjan(int x)
{
    low[x] = dnf[x] = cnt++;
    s[++top] = x;
    for (int i = Head[x]; i; i = Next[i])
    {
        int y = to[i];
        if (!dnf[y])
        {
            Tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if (!cir[y])
            low[x] = min(low[x], dnf[y]);
    }
    if (low[x] == dnf[x])
    {
        cir[x] = ++num;
        sum[num]++;
        while (s[top] != x)
        {
            cir[s[top]] = num;
            top--;
            sum[num]++;
        }
        top--;
    }
}