#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;


vector<int>e[(int)4e5 + 10];

int order[(int)2e5 + 10], ind[(int)2e5 + 10], cnt, n, m;
typedef char vertextype;
typedef int edgetype;
#define maxvex 100
#define infinity 1000
#include<queue>
int visited[100];

class MGraph {

public:
	vertextype vexs[maxvex];
	edgetype arc[maxvex][maxvex];
	int numvertexs, numedges;
	MGraph(const int& v, const int& e) :numvertexs(v), numedges(e) {}
	void creategraph();
	void displaygraph();
	void DFS(int i);
	void DFSTraverse();
	void BFSTraverse();



};
void MGraph::creategraph()
{
	
	for (int i = 0; i < numvertexs; ++i)
	{
		cin >> vexs[i];
	}
	cin.clear();
	
	for (int i = 0; i < numvertexs; ++i)
	{
		for (int j = 0; j < numvertexs; ++j)
		{
			cin >> arc[i][j];
		}
	}


}
void MGraph::displaygraph()
{
	
	for (int i = 0; i < numvertexs; ++i)
	{
		cout << vexs[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < numvertexs; ++i)
	{
		for (int j = 0; j < numvertexs; ++j)
		{
			cout << arc[i][j] << '\t';
		}
		cout << endl;
	}
}
void MGraph::DFS(int i)
{
	int j;
	visited[i] = true;
	
	for (j = 0; j < numvertexs; ++j)
	{
		if (arc[i][j] == 1 && !visited[j])
			DFS(j);
	}
}
void MGraph::DFSTraverse()
{
	int i;
	for (i = 0; i < numvertexs; ++i)
	{
		visited[i] = 0;
	}
	for (i = 0; i < numvertexs; ++i)
	{
		if (!visited[i])
			DFS(i);
	}
}
void MGraph::BFSTraverse()
{
	int i, j;
	queue<int> q;
	for (i = 0; i < numvertexs; ++i)
		visited[numvertexs] = 0;
	for (i = 0; i < numvertexs; ++i)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			
			q.push(i);
			while (!q.empty())
			{
				int k;
				k = q.front();
				q.pop();
				for (j = 0; j < numvertexs; ++j)
				{
					if (arc[i][j] == 1 && !visited[j])
					{
						visited[j] = 1;
						
						q.push(j);
					}
				}
			}
		}


	}

}
void BFS();

int main()
{
	
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
		{
			ind[i] = 0, e[i].clear();
			
		}
		int i, numvertexs=100;
		for (i = 0; i < numvertexs; ++i)
		{
			visited[i] = 0;
		}
		int u, v;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d", &u, &v);
			e[v].push_back(u);
			ind[u]++;
		}
		for (i = 0; i < numvertexs; ++i)
		{
			visited[i] = 0;
		}
		cnt = 0;
		BFS();
		for (int i = cnt - 1; i >= 0; --i)
		{
			printf("%d ", order[i]);
		}
	
	return 0;
}

void BFS()
{
	priority_queue<int, vector<int>, less<int> >q;
	for (int i = 1; i <= n; ++i)
	{
		if (!ind[i])
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int u = q.top();
		q.pop();
		order[cnt++] = u;
		int len = e[u].size();
		for (int i = 0; i < len; ++i)
		{
			--ind[e[u][i]];
			if (!ind[e[u][i]])
			{
				q.push(e[u][i]);
			}
		}
	}
}