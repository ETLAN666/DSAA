/*
#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
const int inf = 0x3f3f3f3f;
vector<int>g[(int)1e5 + 10];
int element[(int)1e5 + 10];
bool cmp_cbt, in_deg[(int)1e5 + 10];
int Type;
int DFS(int u);
bool BFS(int root);

struct node
{
	node *left;
	node *right;
	int value;
};
bool isCBT(node *head)
{
	if (head == NULL)
		return true;
	bool leaf = false;
	queue < node >q;
	q.push(*head);
	while (!!q.empty())
	{
		node p = q.front();
		q.pop();
		if ((leaf && (p.left != NULL || p.right != NULL)) || (p.left == NULL && p.right != NULL))
			return false;
		if (p.left != NULL)
			q.push(*p.left);
		if (p.right != NULL)
			q.push(*p.right);
		if ((p.left != NULL && p.right == NULL) || (p.left == NULL && p.right == NULL))
			leaf = true;
	}
	return true;
}

int main()
{
	int T, count = 1,MaxTag = 1, MinTag = 1;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int* p = new int[n + 1];
		for (int i = 1; i <= n; ++i)
		{
			g[i].clear();
			in_deg[i] = false;
		}
		for (int i = 1; i <= n; ++i)
		{
			cin>>element[i];
			p[i]= element[i];
		}
		int x, y;
		for (int i = 1; i <=n-1; ++i)
		{
			cin>>x>>y;
			g[x].push_back(y);
			in_deg[y] = true;
			if (p[x] > p[y])
				MinTag = 0;
			if (p[x] < p[y])
				MaxTag = 0;
		}
		cmp_cbt = true;
		int root;
		for (int i = 1; i <= n; ++i)
		{
			if (!in_deg[i])
			{
				root = i;
				break;
			}
		}
		Type = 0;
		DFS(root);
		if (cmp_cbt)
		{
			cmp_cbt = BFS(root);
		}
		if (cmp_cbt)
			cout << "Case #" << count << ":" << " YES" << endl;
		else
			cout << "Case #" << count << ":" << " NO" << endl;
		count++;
		delete[] p;
		p = NULL;
	}
	return 0;
}

int DFS(int u)
{
	if (!cmp_cbt)
	{
		return 0;
	}
	int len = g[u].size();
	if (len > 2)
	{
		cmp_cbt = false;
		return 0;
	}
	int last_len, c_len = inf;
	for (int i = 0; i < len; ++i)
	{
		if (!cmp_cbt)
		{
			return 0;
		}
		if (!Type)
		{
			if (element[g[u][i]] > element[u])
			{
				Type = 1;
			}
			else if (element[g[u][i]] < element[u])
			{
				Type = 2;
			}
		}
		else if (Type == 1)
		{
			if (element[g[u][i]] < element[u])
			{
				cmp_cbt = false;
				return 0;
			}
		}
		else
		{
			if (element[g[u][i]] > element[u])
			{
				cmp_cbt = false;
				return 0;
			}
		}
	}
	return len;
}

bool BFS(int root)
{
	queue<int>q;
	q.push(root);
	int cur = root;
	while (cur)
	{
		int u = q.front();
		q.pop();
		int len = g[u].size();
		if (len == 2)
		{
			q.push(g[u][0]);
			q.push(g[u][1]);
		}
		else if (len == 1)
		{
			q.push(g[u][0]);
			q.push(0);
		}
		else
		{
			q.push(0);
			q.push(0);
		}
		cur = q.front();
	}
	while (!q.empty())
	{
		if (q.front())
		{
			return false;
		}
		q.pop();
	}
	return true;
}
*/