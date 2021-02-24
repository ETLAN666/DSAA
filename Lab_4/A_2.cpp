#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef long long int ll;
typedef struct node
{
	int data;
	struct node* next;
	int size;
}node,*linklist;

void create_list_tail_do(linklist* l,int *Length,int *kk)
{
	int i,len,K,cur=0;
	linklist p,t,r,p2,t2;
	len = *Length;
	K = *kk;
	(*l) = (node*)malloc(sizeof(node));
	(*l)->next = NULL; 
	(*l)->size = len;
	t = (*l);
	for (i = 1; i <= len; i++)
	{
		p = (node*)malloc(sizeof(node));
		p->data = i;
		t->next = p;
		t = p;
	}
	t->next = (*l)->next;
	r = t;
	i = 1;
	while ((*l)->size != 0)
	{
		if (i == K)
		{
			i = 0;
			t2 = r->next;
			printf("%d ", t2->data);
			r->next = t2->next;
			free(t2);
			t2 = NULL;
			(*l)->size--;
			cur = 1;
		}
		if (cur == 1)
		{
			r = r;
			i++;
			cur = 0;
		}
		else if(cur==0)
		{
			r = r->next;
			i++;
		}
		
		
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
	  int n=0, k=0;
	  cin >> n >> k;
	  linklist l;
	  create_list_tail_do(&l, &n, &k);
	  free(l);
	  l = NULL;
	  printf("\n");
    }
	return 0;
}
