#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int pa[1000],qb[1000];
int p1[1000],q2[1000];

typedef struct PolyNode
{
	int coef;
	int expn;
	PolyNode* next;
}PolyNode ,*Linklist;

int Compare(int a, int b)
{
	if (a < b)
		return -1;
	if (a == b)
		return 0;
	if (a > b)
		return 1;

}


void CreateListTail(Linklist* L, int C[], int E[], int n)
{
	Linklist p,r;
	int i;
	(*L) = (PolyNode*)malloc(sizeof(PolyNode));
	r = (*L);
	for (i = 0; i < n; i++)
	{
		p = (PolyNode*)malloc(sizeof(PolyNode));
		p->coef = C[i];
		p->expn = E[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}


void PolyAdd(Linklist *La, Linklist *Lb)
{
	int sum = 0;
	Linklist p1,p2,front,tc;
	p1 = (*La)->next;
	p2 = (*Lb)->next;
	front = (*Lb);
	while(p1&&p2)
		switch (Compare(p1->expn, p2->expn)) {
		case -1:
			(*La)->next = p1->next;
			front->next = p1;
			p1->next = p2;
			p1 = (*La)->next;
			front = front->next;
			break;
		case 0:
			p2->coef = p2->coef + p1->coef;
			tc = p1;
			(*La)->next = p1->next;
			p1 = p1->next;
			p2 = p2->next;
			front = front->next;
			tc->next = NULL;
			free(tc);
			break;
		case 1:
			while ((Compare(p1->expn, p2->expn) == 1)&&p2->next)
			{
				p2 = p2->next;
				front = front->next;
			}
			if (!(p2->next))
			{
				p2->next = (*La)->next;
			}
			if ((Compare(p1->expn, p2->expn) )== -1)
			{
				(*La)->next = p1->next;
				front->next = p1;
				p1->next = p2;
				p1 = (*La)->next;
				front = front->next;
			}
			if ((Compare(p1->expn, p2->expn)) == 0)
			{
				p2->coef = p2->coef + p1->coef;
				tc = p1;
				(*La)->next = p1->next;
				p1 = p1->next;
				p2 = p2->next;
				front = front->next;
				tc->next = NULL;
				free(tc);
			}
			break;
		}
}

void Do(Linklist* L)
{
	Linklist p,q;
	q = (*L);
	p = (*L)->next;
	while (p)
	{
		if (p->coef == 0)
		{
			q->next = p->next;
			p->next = NULL;
			free(p);
			p = q->next;
		}
		else
		{
			q = q->next;
			p = p->next;
		}		
	}
}
void Print(Linklist L)
{
	Linklist p;
	p = L->next;
	if (p->coef == -1)
	{
		if (p->expn == 0)
			printf("%d", -1);
		else
		{
			if(p->expn == 1)
				printf("-x");
			else
				printf("-x^%d", p->expn);
		}
		p = p->next;
	}
	else if (p->coef == 0)
	{
		p = p->next;
	}
	else if (p->coef == 1)
	{
		if (p->expn == 0)
			printf("%d", 1);
		else
		{
			if (p->expn == 1)
				printf("x");
			else
				printf("x^%d", p->expn);
		}
		p = p->next;
	}
	else
	{
		if (p->expn == 1)
			printf("%dx", p->coef);
		else if (p->expn == 0)
			printf("%d", p->coef);
		else
			printf("%dx^%d", p->coef, p->expn);
		p = p->next;
	}
	while (p)
	{
		if (p->coef == -1)
		{
			if (p->expn == 0)
				printf("%d", -1);
			else
			{
				if (p->expn == 1)
					printf("-x");
				else
					printf("-x^%d", p->expn);
			}
			p = p->next;
		}
		else if (p->coef == 0)
		{
			p = p->next;
		}
		else if (p->coef == 1)
		{
			if (p->expn == 0)
				printf("+%d", 1);
			else
			{
				if (p->expn == 1)
					printf("+x");
				else
					printf("+x^%d", p->expn);
			}
			p = p->next;
		}
		else
		{
			if (p->coef < -1)
			{
				if (p->expn == 0)
					printf("%d", p->coef);
				else if (p->expn == 1)
					printf("%dx", p->coef);
				else
				    printf("%dx^%d", p->coef, p->expn);
				p = p->next;
			}
			else if (p->coef > 1)
			{
				if (p->expn == 0)
					printf("+%d", p->coef);
				else if (p->expn == 1)
					printf("+%dx", p->coef);
				else
					printf("+%dx^%d", p->coef, p->expn);
				p = p->next;
			}
		}	
	}
	printf("\n");
}

void Delete(Linklist *L)
{
	Linklist p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		p->next = NULL;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
}


int main()
{
	int i,T;
	scanf("%d", &T);
	while (T--)
	{
		Linklist La, Lb;
		int n;
		scanf("%d",&n);
		//int* pa, * qb;
		//pa = (int*)malloc(n * sizeof(int));
		//qb = (int*)malloc(n * sizeof(int));
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &pa[i], &qb[i]);
		}
		CreateListTail(&La, pa, qb, n);
		int m;
		scanf("%d", &m);
		//int* p1, * q2;
		//p1 = (int*)malloc(m * sizeof(int));
		//q2 = (int*)malloc(m * sizeof(int));
		for (i = 0; i < m; i++)
		{
			scanf("%d%d", &p1[i], &q2[i]);
		}
		CreateListTail(&Lb, p1, q2,m);
		PolyAdd(&La, &Lb);
		Do(&Lb);
		Print(Lb);
		Delete(&La);
		Delete(&Lb);
		free(La);
		free(Lb);
		//free(pa);
		//free(qb);
		//free(p1);
		//free(q2);
	}
	return  0;
}
