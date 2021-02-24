/*
#include<cstdio>
#include<algorithm>

using namespace std;
int cnt = 0;
long long ans = 0;
int visist[10100];
struct node
{
    int u;
    int v;
    int w;
    bool operator<(const node& r)const
    {
        return w < r.w;
    }
};
node pathes[10010];
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

    for (int& i : visist) {
        i = -1;
    }

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &pathes[tol].u, &pathes[tol].v, &pathes[tol].w);
        tol += 1;
    }

    sort(pathes, pathes + tol);
    for (node i : pathes)
    {
        int xx = Search(i.u);
        int yy = Search(i.v);
        if (xx != yy)
        {
            ans = ans + i.w;
            visist[yy] = xx;
            cnt += 1;
        }
        if (cnt == n - 1)
            break;
    }
    printf("%lld\n", ans);
    return 0;
}
*/