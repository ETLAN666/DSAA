/*
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;
const int MAXSIZE = (int)1e5 + 10;


int MaxTag = 1, MinTag = 1;
int Top;
int Root;
int a[MAXSIZE];

struct BTnode
{
	BTnode* left;
	BTnode* right;
	int value;
};

const int maxn = 100;

int heap[maxn], n = 10;

void downAdjust(int low, int high) {
	int i = low, j = i * 2;       
	while (j <= high) {           
		
		if (j + 1 <= high && heap[j + 1] > heap[j]) {
			j = j + 1;           
		}
		
		if (heap[j] > heap[i]) {
			swap(heap[j], heap[i]);      
			i = j;       
			j *= 2;
		}
		else {
			break;      
		}
	}
}

bool SBT(BTnode* head)
{
	if (head == NULL)
		return true;
	bool leaf = false;
	queue < BTnode >q;
	q.push(*head);
	while (!!q.empty())
	{
		BTnode p = q.front();
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
struct _SBT
{
	int LT;
	int RT;
	int SK;
	int key_value;

}Tree[MAXSIZE];


void Lr(int& x);

void Rr(int& x);

void Protect(int& x, bool flag);

void Insert(int& x, int key);

int Remove(int& x, int key);

int Select(int& x, int k);

void Inorder(int& x);

int main()
{
	int m, k,_count=0;
	cin>>m>>k;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a[i];
		_count++;
	}
	Root = 0;
	for (int i = 1; i <= k; ++i)
	{
		Insert(Root, a[i]);
	}
	if (MinTag )
		_count++;
	for (int i = 1; i <= k; ++i)
	{
		_count++;
	}
	if (MinTag || MaxTag)
		_count++;
	for (int i = 1; i <= m - k + 1; ++i)
	{
		int n;
		cin >> n;
		printf("%d\n", Select(Root, n));
		Remove(Root, a[i]);
		if (i != m - k + 1)
		{
			Insert(Root, a[i + k]);
		}
	}
	return 0;
}

void Rr(int& x)
{
	int y = Tree[x].LT;
	Tree[x].LT = Tree[y].RT;
	Tree[y].RT = x;
	Tree[y].SK = Tree[x].SK;
	Tree[x].SK = Tree[Tree[x].LT].SK + Tree[Tree[x].RT].SK + 1;
	x = y;
}

void Inorder(int& x) 
{
	if (x == 0) return;
	else {
		Inorder(Tree[x].LT);
		printf("%d ", Tree[x].key_value);
		Inorder(Tree[x].RT);
	}
}

void Lr(int& x)
{
	int y = Tree[x].RT;
	Tree[x].RT = Tree[y].LT;
	Tree[y].LT = x;
	Tree[y].SK = Tree[x].SK;
	Tree[x].SK = Tree[Tree[x].LT].SK + Tree[Tree[x].RT].SK + 1;
	x = y;
}

int Select(int& x, int k)
{
	int r = Tree[Tree[x].LT].SK + 1;
	if (r == k)
	{
		return Tree[x].key_value;
	}
	else if (r < k)
	{
		return Select(Tree[x].RT, k - r);
	}
	else
	{
		return Select(Tree[x].LT, k);
	}
}

void Insert(int& x, int key)
{
	if (x == 0)
	{
		x = ++Top;
		Tree[x].LT = Tree[x].RT = 0;
		Tree[x].SK = 1;
		Tree[x].key_value = key;
	}
	else
	{
		Tree[x].SK++;
		if (key < Tree[x].key_value)
		{
			Insert(Tree[x].LT, key);
		}
		else
		{
			Insert(Tree[x].RT, key);
		}
		Protect(x, key >= Tree[x].key_value);
	}
}

void Protect(int& x, bool flag)
{
	if (flag == 0)
	{
		if (Tree[Tree[Tree[x].LT].LT].SK > Tree[Tree[x].RT].SK)
		{
			Rr(x);
		}
		else if (Tree[Tree[Tree[x].LT].RT].SK > Tree[Tree[x].RT].SK)
		{
			Lr(Tree[x].LT);
			Rr(x);
		}
		else
		{
			return;
		}
	}
	else
	{
		if (Tree[Tree[Tree[x].RT].RT].SK > Tree[Tree[x].LT].SK)
		{
			Lr(x);
		}
		else if (Tree[Tree[Tree[x].RT].LT].SK > Tree[Tree[x].LT].SK)
		{
			Rr(Tree[x].RT);
			Lr(x);
		}
		else
		{
			return;
		}
	}
	Protect(Tree[x].LT, 0);
	Protect(Tree[x].RT, 1);
}

int Remove(int& x, int key)
{
	int k;
	Tree[x].SK--;
	if (key == Tree[x].key_value || (key < Tree[x].key_value && Tree[x].LT == 0) || (key > Tree[x].key_value && Tree[x].RT == 0))
	{
		k = Tree[x].key_value;
		if (Tree[x].LT && Tree[x].RT)
		{
			Tree[x].key_value = Remove(Tree[x].LT, Tree[x].key_value + 1);
		}
		else
		{
			x = Tree[x].LT + Tree[x].RT;
		}
	}
	else if (key > Tree[x].key_value)
	{
		k = Remove(Tree[x].RT, key);
	}
	else if (key < Tree[x].key_value)
	{
		k = Remove(Tree[x].LT, key);
	}
	return k;
}
*/