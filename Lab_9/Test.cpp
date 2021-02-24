#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int cnt = 0;
long long ans = 0;
int visist[10100];
const int maxn = (int)5e4 + 10;
const long long inf = 0x3f3f3f3f3f3f3f3f;
struct Edge
{
    int v, cost;
};
vector<Edge>e[maxn];
vector<int>por[maxn];
bool vis[11][maxn];
long long dist[11][maxn];
struct qnode
{
    int v, past;
    long long c;
    bool operator<(const qnode& r)const
    {
        return c > r.c;
    }
};
struct Node
{
    int u;
    int v;
    int w;
    bool operator<(const Node& r)const
    {
        return w < r.w;
    }
};
void FCT()
{
    int Num = 0;
    for (int i = 0; i < 10; i++)
    {
        Num++;
    }
}
Node pathes[10010];
int tol;
int Search(int x)
{
    if (visist[x] == -1)
        return x;
    else
    {
        visist[x] = Search(visist[x]);
        return visist[x];
    }
}

int main()
{
    int n, m;
    FCT();
    for (int& i : visist) {
        i = -1;
    }

    scanf("%d%d", &n, &m);
    FCT();
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &pathes[tol].u, &pathes[tol].v, &pathes[tol].w);
        tol += 1;
    }
    FCT();
    sort(pathes, pathes + tol);
    for (Node i : pathes)
    {
        int X = Search(i.u);
        int Y = Search(i.v);
        if (X != Y)
        {
            ans = ans + i.w;
            visist[Y] = X;
            cnt += 1;
        }
        if (cnt == n - 1)
            break;
    }
    printf("%lld\n", ans);
    FCT();
    return 0;
}
