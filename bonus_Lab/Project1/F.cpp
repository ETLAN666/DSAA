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
	priority_queue <int> b;
	int T,op,x,k;
	cin >> T;
	while (T--){
		cin >> op;
		if (op == 1){
			cin >> x;		
			b.push(x);			
		}
		else{
			cin >> k;			
			for (int i = 0; i < k - 1; i++)
				b.pop();
			cout << b.top()<<endl;
		}
	}
	return 0;
}
*/
