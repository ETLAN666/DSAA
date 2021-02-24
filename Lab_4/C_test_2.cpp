#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef struct LNode
{
    int expn;
    int coef;
    struct LNode* next;
}LNode, * Link;
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
void Prin(const List& L)
{
    Link p = L.head->next;
    int flag;
    if (L.length == 0)
        cout << "0";
    //cout << "the length is :" << L.length << endl;
    for (; p != NULL; )
    {
        flag = 0;
        if (1)
        {
            if (p->expn == 0)
                cout << p->coef, flag = 1;
            if (p->expn == 1 && p->coef == 1)
                printf("x"), flag = 1;
            if (p->expn == 1 && p->coef == -1)
                printf("-x"), flag = 1;
            if (p->expn == 1 && p->coef != 1 && p->coef != -1)
                printf("%dx", p->coef), flag = 1;
            if (p->coef == 1 && p->expn != 1 && p->expn != 0)
                printf("x^%d", p->expn), flag = 1;
            if (p->coef == -1 && p->expn != 1 && p->expn != 0)
                printf("-x^%d", p->expn), flag = 1;

        }
        if (flag == 0)
            printf("%dx^%d", p->coef, p->expn);
        p = p->next;
        if (p != NULL && p->coef > 0)
            cout << "+";

    }
    printf("\n");

}

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
    for (int i = 0; i < T; i++)
    {
        List La, Lb, Lc;

        Init(La);
        OrderInput(La);

        Init(Lb);
        OrderInput(Lb);

        Init(Lc);
        OrderMerge(La, Lb, Lc);

        Prin(Lc);



        while (La.head)
        {
            Link temp = La.head;
            La.head = La.head->next;
            free(temp);
        }
        while (Lb.head)
        {
            Link temp = Lb.head;
            Lb.head = Lb.head->next;
            free(temp);
        }
        while (Lc.head)
        {
            Link temp = Lc.head;
            Lc.head = Lc.head->next;
            free(temp);
        }
    }
    return 0;
}




