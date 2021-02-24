/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>

using namespace std;

vector<string> datas = {".-","-...","-.-.","-..","."
,"..-.","--.","....","..",".---","-.-",".-..","--"
,"-.","---",".--.","--.-",".-.","...","-","..-","...-",
".--","-..-","-.--","--..",".----","..---","...--","....-"
,".....","-....","--...","---..","----.","-----"
};


string tras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		string str;
		cin >> n;
		vector<char> ans;
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			for (int j = 0; j < 36; j++)
			{
				if (!str.compare(datas[j]))
				{
					ans.push_back(tras[j]);
					break;
				}
			}
		}

		for (int i = 1; i <=n/2; i++)
		{
			int tmp = 0;
			if (ans[i - 1] >= '0' && ans[i - 1] <= '9')
			{
				tmp = ans[i - 1] - '0';
				cout << tmp;
			}
			else
			{
				cout << ans[i - 1];
			}
			if (ans[i - 1 + (n / 2)] >= '0' && ans[i - 1 + (n / 2)] <= '9')
			{
				tmp = ans[i - 1 + (n / 2)] - '0';
				cout << tmp;
			}
			else
			{
				cout << ans[i - 1 + (n / 2)];
			}			
		}
		cout << endl;

	}
	return 0;
}
*/