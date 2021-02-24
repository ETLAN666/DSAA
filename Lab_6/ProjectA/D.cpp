
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int MaxSize = 100000 + 100;
int f[MaxSize], m;
char P[MaxSize];
void GA(char* P, int* f);

void Getnext(int next[], string t)
{
    int j = 0, k = -1;
    next[0] = -1;
    while (j < t.length() - 1)
    {
        if (k == -1 || t[j] == t[k])
        {
            j++; k++;
            next[j] = k;
        }
        else k = next[k];
    }
}

int KMP(string s, string t)
{
    int MaxSize = t.length();
    int* next, i = 0, j = 0;
    next = (int*)malloc(MaxSize * sizeof(int));
    Getnext(next, t);
    while (i < s.length() && j < t.length())
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else j = next[j];
    }
    if (j >= t.length())
        return (i - t.length());
    else
        return (-1);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", P);
        m = strlen(P);
        GA(P, f);
        if (f[m] == 0)
        {
            printf("%d\n", m);
            continue;
        }
        if (m % (m - f[m]) == 0) printf("0\n");
        else
        {
            int len1 = m - f[m];
            printf("%d\n", len1 - m % len1);
        }
    }
    return 0;
}

void GA(char* P, int* f)
{
    f[0] = f[1] = 0;
    for (int i = 1; i < m; i++)
    {
        int j = f[i];
        while (j && P[i] != P[j]) j = f[j];
        f[i + 1] = (P[i] == P[j]) ? j + 1 : 0;
    }
}
*/