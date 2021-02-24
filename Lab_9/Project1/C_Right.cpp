#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#define maxn 100010
using namespace std;
inline int read() {
	int x = 0, f = 0; char ch = getchar();
	while (ch > '9' || ch < '0')f |= ch == '-', ch = getchar();
	while (ch >= '0' && ch <= '9')x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}
int n, m, i, in[maxn];
priority_queue<int, vector<int>, greater<int> >q;
vector<int>e[maxn], p;
void init() {
	for (int i = 1; i <= n; ++i)e[i].clear(), in[i] = 0;
	while (!q.empty())q.pop();
	p.clear();
}
void topo() {
	for (i = 1; i <= n; ++i)if (in[i] == 0) q.push(i);
	while (!q.empty()) {
		int now = q.top(); q.pop();
		p.push_back(now);
		for (i = 0; i < e[now].size(); ++i)
			if (--in[e[now][i]] == 0) q.push(e[now][i]);
	}
	for (i = 0; i < p.size() - 1; ++i)printf("%d ", p[i]);
	printf("%d\n", p[p.size() - 1]);
}

int main()
{
	cin >> n >> m;
	init();
	while (m--) {
		int u = read(), v = read();
		e[u].push_back(v);
		++in[v];
	}
	topo();
	return 0;
}
