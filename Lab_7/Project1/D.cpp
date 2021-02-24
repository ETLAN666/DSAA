/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cstring>

using namespace std;

void postorder(string preorder, string inorder) {
	int len = preorder.length();
	if (len == 0)
		return;
	if (len == 1)
	{
		cout << preorder[0] << " ";
		return;
	}
	int pos = inorder.find(preorder[0]);
	postorder(preorder.substr(1, pos), inorder.substr(0, pos));
	postorder(preorder.substr(pos + 1, len - pos - 1), inorder.substr(pos + 1, len - pos - 1));
	cout << preorder[0]<<" ";
}

int main()
{
	int T;
	cin >> T;
	while (T)
	{
		int N;
		cin >> N;
		char *aa,*bb;
		aa = (char*)malloc((N+1) * sizeof(char));
		bb = (char*)malloc((N+1) * sizeof(char));
		for (int i = 0; i < N; i++)
		{
			cin>>aa[i];
		}		
		aa[N] = '\0';
		for (int i = 0; i < N; i++)
		{
			cin>>bb[i];
		}	
		bb[N] = '\0';
		string s1, s2;
		s1 = aa;
		s2 = bb;
		postorder(s1, s2);
		cout << endl;
		free(aa);
		free(bb);
		T--;
	}
	return 0;
}
*/