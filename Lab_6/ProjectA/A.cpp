/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

int CMP(string str1, string str2)
{
	int i=0, j=0, k=0,count=0;
	while (1) {
		if (str1[i++] == str2[j++])
			count++;
		else
			break;
	}
	return count;
}

int main()
{
	int i,n,product,pre=1000,suf=1000;
	scanf("%d",&n);
	string* p = new string[n];
	for (i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (i = 0; i < n - 1; i++) {
		pre=min(CMP(p[i], p[i + 1]),pre);
	}
	for (i = 0; i < n; i++) {
		reverse(p[i].begin(), p[i].end());
	}
	for (i = 0; i < n - 1; i++) {
		suf = min(CMP(p[i],p[i + 1]), suf);
	}
	product = suf * pre;
	printf("%d", product);
	//delete[] p;
	return 0;
}
*/

