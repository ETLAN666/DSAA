#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

#define M 26
#define N 100

char DC[M], EC[M];

int mapnext[(int)2e6 + 10];

char  s[2];
char  Link[(int)4e6 + 10];

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

    int T = 0, count = 0, temp,next[N], nextval[N];
    char ch;
    for (int i = 0; i < M; i++)
    {
        scanf("%s", s);
        EC[i] = s[0];
        DC[s[0] - 'a'] = i + 'a';
    }
    for (int i = 0; i < N; i++)
    {
        next[i] = i;
    }
    int count1, count2;
    int res = 0;
    res = count % N;
    scanf("%s", Link);
    T = next[N - 1];
    int lens = strlen(Link);

    for (int i = 0; i < lens; i++)
        Link[i + lens] = EC[Link[i] - 'a'];

    int pos = lens + lens;
    int ans = lens;

    mapnext[0] = -1;
    int nex = -1, index = 0;
    while (index < pos)
    {
        if (nex == -1 || Link[nex] == Link[index])
        {
            index++;
            nex++;
            mapnext[index] = nex;
        }
        else
            nex = mapnext[nex];
        count++;
    }
    if (count == 0)
        temp = ans;
    if (count > N)
        temp = count;

    while (pos > 0 && lens < pos + pos)
        pos = mapnext[pos];

    for (int i = 0; i < N; i++)
    {
        next[i] = i;
    }
    for (int i = 0; i < N; i++)
    {
        nextval[i] = i;
    }

    while (pos > 0)
    {
        int after = lens - pos;
        int before = pos;
        bool Flagsign = true;
        for (int i = 0; i < before; i++)
        {
            if (Link[i + after] != DC[Link[i] - 'a'])
            {
                Flagsign = false;
                break;
            }
        }
        if (Flagsign)
        {
            ans = after;
            break;
        }
        count++;
    }
    if (count == 0)
        T = ans;
    if (count > N)
        T = count;
    printf("%d\n", ans);
    return 0;
}