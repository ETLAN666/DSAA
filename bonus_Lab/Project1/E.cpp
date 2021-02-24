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



int main()
{
	long long int n, q;
	cin >> n >> q;

	vector<long long int> b;

	for (int i = 0; i < n; i++)
	{
		long long int temp;
		cin >> temp;
		b.push_back(temp);
	}

	while (q--)
	{
		vector<long long int> s(b);
		long long int cnt = 0;
		long long int x, y;
		long long int t = 0;
		cin >> x >> y;
		if ((s[0] + s[1]) < x)
		{
			t = x - (s[0] + s[1]);
			s[1] = s[1] + t;
			cnt = cnt + t;
		}
		for (int i = 1; i < n - 1; i++)
		{
			if ((s[i - 1] + s[i] + s[i + 1]) < x)
			{
				t = x - (s[i - 1] + s[i] + s[i + 1]);
				s[i + 1] = s[i + 1] + t;
				cnt = cnt + t;
			}
		}
		if ((s[n - 2] + s[n - 1]) < x)
		{
			t = x - (s[n - 2] + s[n - 1]);
			s[n - 2] = s[n - 2] + t;
			cnt = cnt + t;
		}
		if (cnt > y)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}
*/