/*
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int pa[1200], qb[1200], p1[1200], q2[1200];

int Compare(int a, int b)
{
    if (a < b)
        return -1;
    if (a == b)
        return 0;
    if (a > b)
        return 1;
}
typedef struct PolyNode
{
    int coef;
    int expn;
    PolyNode* next;
}PolyNode, * Linklist;



typedef struct LNode
{
    int expn;
    int coef;
    struct LNode* next;
}LNode, * Link;

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

typedef struct _List
{
    int length;
    Link head;
    Link tail;
}List;

void Init(List& L)
{
    L.length = 0;
    L.head = (Link)malloc(sizeof(LNode));
    L.head->expn = -1;
    L.head->coef = -1;
    L.head->next = NULL;
    L.tail = NULL;
    return;
}
void OrderMerge(List& La, List& Lb, List& Lc);
void OrderInput(List& L);
inline void OrderInsert(List& L, int f, int e);

void Delete(Link* head)
{
    while (*head)
    {
        Link p = (*head);
        (*head) = (*head)->next;
        free(p);
    }

}
int main()
{
    int T;
    cin >> T;
    int count=0;
    while (T--)
    {
        List La; 

        Init(La);
        OrderInput(La);

        List Lb;

        Init(Lb);
        OrderInput(Lb);

        List Lc;

        Init(Lc);
        OrderMerge(La, Lb, Lc);
        count++;

        Link p = Lc.head->next;
        int point;
        if (Lc.length == 0)
            cout << "0";
        else
        {

            for (; p != NULL; )
            {
                point = 0;
                if (1)
                {
                    if (p->expn == 0)
                        cout << p->coef, point = 1;               
                    if (p->expn == 1 && p->coef != 1 && p->coef != -1)
                        printf("%dx", p->coef), point = 1;
                    if (p->expn == 1 && p->coef == -1)
                        printf("-x"), point = 1;
                    if (p->coef == -1 && p->expn != 1 && p->expn != 0)
                        printf("-x^%d", p->expn), point = 1;
                    if (p->coef == 1 && p->expn != 1 && p->expn != 0)
                        printf("x^%d", p->expn), point = 1;
                    if (p->expn == 1 && p->coef == 1)
                        printf("x"), point = 1;

                    count++;

                }
                if (point == 0)
                    printf("%dx^%d", p->coef, p->expn);
                p = p->next;
                if (p != NULL && p->coef > 0)
                    cout << "+";
            }

        }
        printf("\n");
        Delete(&La.head);
        Delete(&Lb.head);
        Delete(&Lc.head);

    }

    return 0;
}

inline void OrderInsert(List& L, int f, int e)
{
    Link p = (Link)malloc(sizeof(LNode));
    // Link q;
    p->expn = e;
    p->coef = f;
    if (!L.length)
    {
        L.head->next = p;
        L.tail = p;
        p->next = NULL;
    }
    else
    {
        //for (q = L.head; q.next != NULL && (e > q.next.expn); q = q.next);
        p->next = L.tail->next;
        L.tail->next = p;
        L.tail = p;
    }
    L.length++;
    return;
}

void OrderMerge(List& La, List& Lb, List& Lc)
{
    Link pa, pb;
    pa = La.head->next;
    pb = Lb.head->next;
    int i, j;
    for (i = La.length, j = Lb.length; i != 0 && j != 0; )
    {
        if (pa->expn == pb->expn)
        {
            int sum = pa->coef + pb->coef;
            if (sum != 0)
                OrderInsert(Lc, sum, pa->expn);
            pa = pa->next;
            pb = pb->next;
            i--;
            j--;
        }

        else if (pa->expn < pb->expn)
        {
            if (pa->coef != 0)
                OrderInsert(Lc, pa->coef, pa->expn);
            pa = pa->next;
            i--;
        }

        else
        {
            if (pb->coef != 0)
                OrderInsert(Lc, pb->coef, pb->expn);
            pb = pb->next;
            j--;

        }
    }

    while (i)
    {
        if (pa->coef != 0)
            OrderInsert(Lc, pa->coef, pa->expn);
        pa = pa->next;
        i--;
    }
    while (j)
    {
        if (pb->coef != 0)
            OrderInsert(Lc, pb->coef, pb->expn);
        pb = pb->next;
        j--;
    }
}

void OrderInput(List& L)
{
    int n, e, f;
    scanf("%d", &n);
    L.length = n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &f, &e);
        Link p = (Link)malloc(sizeof(LNode));
        Link q;
        p->expn = e;
        p->coef = f;
        if (i == 0)
        {
            L.head->next = p;
            L.tail = p;
            p->next = NULL;
        }
        else
        {
            p->next = L.tail->next;
            L.tail->next = p;
            L.tail = p;
        }

    }
    return;

}
*/



