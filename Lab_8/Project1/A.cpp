


#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int inf = 0x3f3f3f3f;
vector<int>g[(int)1e5 + 10];
int value[(int)1e5 + 10];
bool is_bt, in_deg[(int)1e5 + 10];


int main()
{
	int T, count = 1;
	cin >> T;
	while (T--)
	{
		int n, x, y, MaxTag = 1, MinTag = 1;
		cin >> n;
		int* p = new int[n + 1];
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i];
			g[i].clear();
			in_deg[i] = false;
		}
		for (int i = 1; i <= n - 1; i++)
		{
			cin >> x >> y;
			g[x].push_back(y);
			in_deg[y] = true;
			if (p[x] > p[y])
				MinTag = 0;
			if (p[x] < p[y])
				MaxTag = 0;
		}
		if (MinTag || MaxTag)
			cout << "Case #" << count << ":" << " YES" << endl;
		else
			cout << "Case #" << count << ":" << " NO" << endl;
		count++;
		delete[] p;
		p = NULL;
	}
	return 0;
}
