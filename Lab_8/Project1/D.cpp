
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

typedef long long  ll;


#define INF -10000
#define MAX 20000


#define min(a,b) ((a)<(b)?(a):(b))

int Totall = 1;
struct BTnode
{
	BTnode* left;
	BTnode* right;
	int size;
	ll w;
};

BTnode* Create_BTnode(ll w);

void Insert(BTnode* root, BTnode* s);

BTnode* Find_min(BTnode* root);

BTnode* Find_the_kth(BTnode* root, int k);

ll Alpha(ll n);

void Free_area(BTnode* root);


BTnode* Free_remain(BTnode* root, int k);

int main()
{
	int t, k, s;
	cin >> t >> k >> s;
	int time = t / 100 * 100;
	ll last_ans = s;
	int T, count = 1, MaxTag = 1, MinTag = 1,_count=0;
	BTnode* root = Create_BTnode(Alpha(1 + last_ans));
	
	for (int i = 2; i <= min(k, time); ++i)
	{
		Insert(root, Create_BTnode(Alpha(i + last_ans)));
		if (i % 100 == 0)
		{
			last_ans = Find_min(root)->w;
			printf("%lld ", last_ans);
		}
	}
	
	
	
	for (int i = k + 1; i <= time; ++i)
	{
		Insert(root, Create_BTnode(Alpha(i + last_ans)));
		root = Free_remain(root, k);
		if (i % 100 == 0)
		{
			last_ans = Find_the_kth(root, k)->w;
			printf("%lld ", last_ans);
		}
	}
	return 0;
}

BTnode* Create_BTnode(long long w)
{
	BTnode* res = new BTnode;
	res->left = NULL;
	res->right = NULL;
	res->size = 1;
	res->w = w;
	return res;
}

BTnode* Find_min(BTnode* root)
{
	while (root->left)
	{
		root = root->left;
	}
	return root;
}

BTnode* Free_remain(BTnode* root, int k)
{
	BTnode* root_tmp = root;
	while (root->size > k)
	{
		root_tmp = root;
		root = root->right;
		Free_area(root_tmp->left);
		delete root_tmp;
	}
	return root;
}

void Insert(BTnode* root, BTnode* s)
{
	BTnode* p = root, * q;
	bool left_or_right;
	if (root->w > s->w)
	{
		q = root->left;
		left_or_right = true;
	}
	else
	{
		++root->size;
		q = root->right;
		left_or_right = false;
	}
	while (q)
	{
		p = q;
		if (q->w > s->w)
		{
			q = q->left;
			left_or_right = true;
		}
		else
		{
			++q->size;
			q = q->right;
			left_or_right = false;
		}
	}
	if (left_or_right)
	{
		p->left = s;
	}
	else
	{
		p->right = s;
	}
}

long long Alpha(long long n)
{
	long long res = n;
	while (n)
	{
		res += n % 10;
		n /= 10;
	}
	return res;
}

BTnode* Find_the_kth(BTnode* root, int k)
{
	int cnt = 0;
	while (cnt < k)
	{
		if (root->size > k - cnt)
		{
			root = root->right;
		}
		else if (root->size == k - cnt)
		{
			return root;
		}
		else
		{
			cnt += root->size;
			root = root->left;
		}
	}
	return root;
}
void Free_area(BTnode* root)
{
	if (root != NULL)
	{
		Free_area(root->left);
		Free_area(root->right);
		delete root;
	}
}
