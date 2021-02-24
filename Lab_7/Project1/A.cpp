/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

int main()
{
	int T,N,k,x1,x2,x3,j,leaf;
	cin >> T;
	while (T)
	{
		cin >> N >> k;
		j = (N - 1) % k;
		if (j == 0)
			x2 = 0;
		else
			x2 = 1;
		x1 = (N - 1 - j) / k;
		leaf = N - x1 - x2;
		cout << leaf << endl;
		T--;
	}
	return 0;
}
*/