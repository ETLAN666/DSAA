#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef long long int ll;

vector<Edge>edge[(int)5e4 + 10];
int query[(int)5e4 + 10];
ll ans[(int)5e4 + 10];
priority_queue<Road>pr_queue;

#define MAX_VERTEX  60  
typedef char DataType;
typedef struct
{
	int vertexNum, edgeNum;
	DataType vertexArr[MAX_VERTEX];       	 
	int edgeArr[MAX_VERTEX][MAX_VERTEX]; 

}ArrayGraph;

typedef struct Edge
{
	int v, w;
	bool operator<(const Edge& b)const
	{
		return w < b.w;
	}
};
int t;
int visit[MAX_VERTEX];
typedef struct Road
{
	int s, last_t, t, ind;
	ll w;
	bool operator<(const Road& b)const
	{
		return w > b.w;
	}
};

int main()
{

	for (int i = 0; i < MAX_VERTEX; i++)
	{
		visit[MAX_VERTEX] = 0;
	}
	cin >> t;
	
	while (t--)
	{
		while (!pr_queue.empty())
		{
			pr_queue.pop();
		}
		int n, m, q;
		scanf("%d%d%d", &n, &m, &q);
		for (int i = 1; i <= n; ++i)
		{
			edge[i].clear();
		}
		Edge edge_tmp;
		for (int i = 0; i < m; ++i)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			edge_tmp.v = v;
			edge_tmp.w = w;
			edge[u].push_back(edge_tmp);
		}
		for (int i = 1; i <= n; ++i)
		{
			sort(edge[i].begin(), edge[i].end());
		}
		int max_query = 0;
		for (int i = 0; i < q; ++i)
		{
			scanf("%d", &query[i]);
			max_query = max(query[i], max_query);
		}
		for (int i = 0; i < MAX_VERTEX; i++)
		{
			visit[MAX_VERTEX] = 0;
		}
		Road road_tmp;
		for (int i = 1; i <= n; ++i)
		{
			if (edge[i].size())
			{
				road_tmp.s = road_tmp.last_t = i;
				road_tmp.t = edge[i][0].v;
				road_tmp.ind = 0;
				road_tmp.w = edge[i][0].w;
				pr_queue.push(road_tmp);
			}
		}
		for (int i = 0; i < MAX_VERTEX; i++)
		{
			visit[MAX_VERTEX] = 0;
		}
		int current = 1;
		int s, t, last_t, ind;
		long long w;
		Road next;
		for (int i = 0; i < MAX_VERTEX; i++)
		{
			visit[MAX_VERTEX] = 0;
		}
		while (current <= max_query)
		{
			ans[current] = pr_queue.top().w;
			s = pr_queue.top().s;
			t = pr_queue.top().t;
			last_t = pr_queue.top().last_t;
			ind = pr_queue.top().ind;
			w = pr_queue.top().w;
			if (ind < edge[last_t].size() - 1)
			{
				next.s = s;
				next.last_t = last_t;
				next.ind = ind + 1;
				next.t = edge[last_t][next.ind].v;
				next.w = w - edge[last_t][ind].w + edge[last_t][next.ind].w;
				pr_queue.push(next);
			}
			if (edge[t].size())
			{
				next.s = s;
				next.last_t = t;
				next.ind = 0;
				next.t = edge[t][next.ind].v;
				next.w = w + edge[t][next.ind].w;
				pr_queue.push(next);
			}
			pr_queue.pop();
			++current;
		}
		for (int i = 0; i < q; ++i)
		{
			printf("%lld\n", ans[query[i]]);
		}
	}
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		visit[MAX_VERTEX] = 0;
	}
	return 0;
}