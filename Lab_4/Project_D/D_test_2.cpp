/*
#include <iostream>
#include<cstdio>
#include<cstdlib>

#define MAXSIZE 400000
#define MAXVALUE 400000
typedef long long int ll;
using namespace std;

int bb[300000];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int i, n, begin, counter = 1, count = 0;
        scanf("%d%d", &n, &begin);
        int a[MAXSIZE] = { 0 };
        //printf("%d",begin);
        bb[count] = begin;
        count++;
        a[begin]++;
        int mid = begin;
        if (n % 2 == 1)
            for (int j = 1; j < n; j += 2)
            {
                int a1, a2;
                scanf("%d%d", &a1, &a2);
                a[a1]++;
                a[a2]++;
                if (a1 > mid && a2 > mid)
                    counter++;
                else if (a1 < mid && a2 < mid)
                    counter--;
                while (counter < 1)
                    counter = counter + a[--mid];
                while (counter > a[mid])
                    counter = counter - a[mid++];
                //printf(" %d",mid);
                bb[count] = mid;
                count++;
            }
        else
        {
            if (n == 2)
            {
                int a1, a2;
                scanf("%d", &a1);
            }
            else
            {
                int n2 = n - 1;
                for (int j = 1; j < n2; j += 2)
                {
                    int a1, a2, x;
                    scanf("%d%d", &a1, &a2);
                    if (j == (n - 3))
                        scanf("%d", &x);
                    a[a1]++;
                    a[a2]++;
                    if (a1 > mid && a2 > mid)
                        counter++;
                    else if (a1 < mid && a2 < mid)
                        counter--;
                    while (counter < 1)
                        counter = counter + a[--mid];
                    while (counter > a[mid])
                        counter = counter - a[mid++];
                    //printf(" %d",mid);
                    bb[count] = mid;
                    count++;
                }
            }
        }
        for (i = 0; i < count; i++)
        {
            printf("%d ", bb[i]);
        }
        printf("\n");
    }
}
*/