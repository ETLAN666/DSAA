/*
#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>

using namespace std;
#define INF 0x3f3f3f3f
typedef long long int ll;
typedef struct Node
{
	ll brightness;
	ll order;
	ll parent;
}Node;

bool cmp(Node a, Node b)
{
	return a.brightness < b.brightness;
}

bool cmp_2(Node a, Node b)
{
	return a.order < b.order;
}


int main()
{
	ll N, cnt = 0;
	cin >> N;
	vector<Node> a;
	for (ll i = 0; i < N; i++)
	{
		Node t;
		cin >> t.brightness;
		t.order = i;
		a.push_back(t);
	}
	if (a[0].brightness != 0)
	{
		a[0].brightness = 0;
		cnt++;
	}


	for (ll i = 1; i < N; i++)
	{
		if (a[i].brightness == 0)
		{
			a[i].brightness = INF;
		}
	}
	for (ll i = 1; i < N; i++)
	{
		for (ll j = 1, key = 0, t = 0, max = 0; j < N; j++)
		{
			if (a[j].brightness == i)
			{
				t = 1;
				break;
			}
			if (a[j].brightness >= max)
			{
				max = a[j].brightness;
				key = j;
			}
			if (j == N - 1)
			{
				a[key].brightness = i;
				cnt++;
			}
		}
	}


	sort(a.begin(), a.end(), cmp);

	a[0].parent = 0;
	for (ll i = 1; i < N; i++)
	{
		a[i].parent = a[i - 1].order + 1;
	}
	sort(a.begin(), a.end(), cmp_2);
	cout << cnt << endl;
	for (ll i = 1; i < N; i++)
	{
		cout << a[i].parent << " ";
	}

	return 0;
}
*/