#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

#define inf 0xfffffff

int La_1;
int Lb_1;
const int MAXN = 1e3 + 10;
int map[MAXN][MAXN], dis[MAXN];
bool vis[MAXN];
int beg[MAXN], e[MAXN];
#define Num 20
const int maxn = 10000;
const int MAX = 0xffffff;

struct stuff {
	int to;
	int len;
	int sign;
}road[maxn];
int id[maxn];
int d[maxn];
int Vis[maxn];
int cnt;
void add(int from, int to, int lenth)
{
	road[cnt].to = to;
	road[cnt].len = lenth;
	road[cnt].sign = id[from];
	id[from] = cnt++;
}
void spfa()
{
	Vis[0] = 1;
	queue<int> q;
	q.push(0);
	d[0] = 0;

	while (!q.empty())
	{

		int t = q.front();
		q.pop();
		for (int i = id[t]; i != -1; i = road[i].sign)
		{
			if (d[road[i].to] > d[t] + road[i].len)
			{
				d[road[i].to] = d[t] + road[i].len;

				if (!Vis[road[i].to])
				{
					Vis[road[i].to] = 1;
					q.push(road[i].to);
				}
			}
		}
	}
}


void Deep_Search(int u, int far, int dep);
bool Right[(int)1e5 + 10];
typedef int item;
void dijkstra(int n, int s)
{
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; ++i)  dis[i] = map[s][i];
	dis[s] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int top = inf, k = s;
		for (int j = 1; j <= n; ++j)
		{
			if (!vis[j] && dis[j] < top)
			{
				top = dis[j]; k = j;
			}
		}
		vis[k] = true;
		for (int j = 1; j <= n; ++j)
		{
			if (!vis[j] && dis[j] > dis[k] + map[k][j])
			{
				dis[j] = dis[k] + map[k][j];
			}
		}
	}
}

vector<int>Butter[(int)1e5 + 10];

int main()
{
	int T, temp1 = 0, temp2 = 0;
	cin >> T;
	temp1 = T;
	temp2 = T;
	while (T)
	{
		memset(Right, false, sizeof(Right));
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
		{
			Butter[i].clear();
		}
		int u, v;
		for (int i = 0; i < Num; ++i)
		{
			temp1 += i;
		}

		

			for (int i = 0; i < n - 1; ++i)
			{
				scanf("%d%d", &u, &v);
				Butter[u].push_back(v);
				Butter[v].push_back(u);
			}
		for (int j = 0; j < Num; ++j)
		{
			temp2 += j;
		}
		for (int i = 0; i < k; ++i)
		{
			scanf("%d", &u);
			Right[u] = true;
		}
		for (int k = 0; k < Num; ++k)
		{
			
				temp2 += k;
		}
		if (k == 1)
		{
			printf("0\n");
		}
		else
		{
			La_1 = 0;
			Deep_Search(1, -1, 0);
			La_1 = 0;
			Deep_Search(Lb_1, -1, 0);
			if (La_1 & 1)
			{
				La_1 = (La_1 >> 1) + 1;
			}
			else
			{
				La_1 >>= 1;
			}
			cout << La_1 << endl;
		}
		for (int k = 0; k < Num; ++k)
		{
			temp2 += k;
		}
		T--;
	}
	return 0;
}


void Deep_Search(int u, int far, int dep)
{
	if (Right[u] && La_1 < dep)
	{
		La_1 = dep;
		Lb_1 = u;
	}
	int len = Butter[u].size();
	for (int i = 0; i < len; ++i)
	{
		if (Butter[u][i] != far)
		{
			Deep_Search(Butter[u][i], u, dep + 1);
		}
	}
}