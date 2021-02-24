
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int pa[1200], qb[1200], p1[1200], q2[1200];

typedef struct PolyNode
{
	int coef;
	int expn;
	PolyNode* next;
}PolyNode, * Linklist;

int Compare(int a, int b)
{
	if (a < b)
		return -1;
	if (a == b)
		return 0;
	if (a > b)
		return 1;

}

/*void InitList(Linklist* L)
{
	(*L)= (PolyNode*)malloc(sizeof(PolyNode));
	(*L)->next = NULL;
}*/

/*void InsertNode(Linklist* L, int c, int e, int i)
{
	Linklist p, q;
	q = (PolyNode*)malloc(sizeof(PolyNode));
	q->coef = c;
	q->expn = e;
	q->next = NULL;
	p = (*L);
	int j = 1;
	while (j < i)
	{
		p = p->next;
		++j;
	}
	q->next = p->next;
	p->next = q;
}*/
void CreateListTail(Linklist* L, int C[], int E[], int n)
{
	Linklist p, r;
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
/*void CreateList(Linklist* L, int C[], int E[], int n)
{
	int i;
	InitList(L);
	for (i = 0; i < n; i++)
	{
		InsertNode(L, C[i], E[i], i + 1);
	}
}*/

void PolyAdd(Linklist* La, Linklist* Lb)
{
	int sum = 0;
	Linklist p1, p2, front, tc;
	p1 = (*La)->next;
	p2 = (*Lb)->next;
	front = (*Lb);
	while (p1 && p2)
	{
		if (p1->expn < p2->expn)
		{
			(*La)->next = p1->next;
			front->next = p1;
			p1->next = p2;
			p1 = (*La)->next;
			front = front->next;
		}
		else if (p1->expn == p2->expn)
		{
			p2->coef = p2->coef + p1->coef;
			tc = p1;
			(*La)->next = p1->next;
			p1 = p1->next;
			p2 = p2->next;
			front = front->next;
			if (!p2)
			{
				front->next = p1;
			}

			tc->next = NULL;
			free(tc);
		}
		else if (p1->expn > p2->expn)
		{
			while ((p1->expn > p2->expn) && p2->next)
			{
				p2 = p2->next;
				front = front->next;
			}
			if (!(p2->next))
			{

				if (p1->expn == p2->expn)
				{
					p2->coef = p2->coef + p1->coef;
					tc = p1;
					(*La)->next = p1->next;
					p1 = p1->next;
					tc->next = NULL;
					p2->next = p1;
					p1 = NULL;
					free(tc);
				}
				else
					p2->next = (*La)->next;
			}
			else if (p1->expn < p2->expn)
			{
				(*La)->next = p1->next;
				front->next = p1;
				p1->next = p2;
				p1 = (*La)->next;
				front = front->next;
			}
			else if (p1->expn == p2->expn)
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
		}
	}
}
void Do(Linklist* L)
{
	Linklist p, q;
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

void Delete(Linklist* L)
{
	Linklist p, q;
	p = (*L);
	while (!p)
	{
		q = p;
		p = p->next;
		free(q);
	}
}


int main()
{
	int i, T;
	scanf("%d", &T);
	while (T--)
	{
		Linklist La, Lb;
		int n, flag1 = 1, flag2 = 1;
		scanf("%d", &n);
		if (n == 0)
		{
			flag1 = 0;
		}
		else

		{
			/*int* pa, * qb;
			pa = (int*)malloc(n * sizeof(int));
			qb = (int*)malloc(n * sizeof(int));*/
			for (i = 0; i < n; i++)
			{
				scanf("%d%d", &pa[i], &qb[i]);
			}
			CreateListTail(&La, pa, qb, n);
		}
		int m;
		scanf("%d", &m);
		if (m == 0)
		{
			flag2 = 0;
		}
		else
		{
			/*int* p1, * q2;
			p1 = (int*)malloc(m * sizeof(int));
			q2 = (int*)malloc(m * sizeof(int));*/
			for (i = 0; i < m; i++)
			{
				scanf("%d%d", &p1[i], &q2[i]);
			}
			CreateListTail(&Lb, p1, q2, m);
		}
		if (flag1 == 0 && flag2 == 1)
		{
			Print(Lb);
			Delete(&Lb);
			free(Lb);
		}
		else if (flag1 == 1 && flag2 == 0)
		{
			Print(La);
			Delete(&Lb);
			free(La);
		}
		else if (flag1 == 0 && flag2 == 0)
			printf("%d\n", 0);
		else if (flag1 == 1 && flag2 == 1)
		{
			PolyAdd(&La, &Lb);
			Do(&Lb);
			if (!(Lb->next))
				printf("%d\n", 0);
			else
			{
				Print(Lb);
			}
			Delete(&La);
			Delete(&Lb);
		}
	}
	return  0;
}


