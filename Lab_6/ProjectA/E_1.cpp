/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

#define N 100

const int Hashnum = 139;
char s1[(int)1e5 + 10], s2[(int)1e5 + 10];
int Length1, Length2;
int CMP(string str1, string str2)
{
    int i = 0, j = 0, k = 0, count = 0;
    while (1) {
        if (str1[i++] == str2[j++])
            count++;
        else
            break;
    }
    return count;
}
#define find1(m,n) hash1[m] - hash1[m + n] * xp[n]
unsigned long long hash1[(int)1e5 + 10], hash2[(int)1e5 + 10], xp[(int)1e5 + 10], hashcode[(int)1e5 + 10];
#define find2(m,n) hash2[m] - hash2[m + n] * xp[n]
bool Change(int index);
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
    int T=0, count = 0,next[N],nextval[N];
    xp[0] = 1;
    for (int i = 1; i < (int)1e5 + 10; i++)
        xp[i] = xp[i - 1] * Hashnum;

    scanf("%s", s1);

    scanf("%s", s2);


    Length1 = strlen(s1);

    for (int i = 0; i < N; i++)
    {
        next[i] = i;
    }
    Length2 = strlen(s2);

    hash1[Length1] = 0;
    hash2[Length2] = 0;

    for (int i = Length1 - 1; i >= 0; i--)
        hash1[i] = hash1[i + 1] * Hashnum + s1[i] - 'A' + 1;

    for (int i = 0; i < N; i++)
    {
        nextval[i] = i;
    }
    for (int i = Length2 - 1; i >= 0; i--)
        hash2[i] = hash2[i + 1] * Hashnum + s2[i] - 'A' + 1;

    int low = 0, high = min(Length1, Length2), mid;

    for (int i = 0; i < N; i++)
    {
        nextval[i] = i+1;
    }
    while (low < high)
    {
        mid = (low + high) / 2;
        Change(mid) ? low = mid + 1 : high = mid;
    }
    (!Change(low)) && ([&]() {low--; return 1; }());
    printf("%d\n", low);
    return 0;
}

bool Change(int index)
{
    if (index > Length1 || index > Length2)
        return false;

    for (int i = 0; i < Length1 - index + 1; i++)
        hashcode[i] = find1(i, index);

    sort(hashcode, hashcode + Length1 - index + 1);
    for (int i = 0; i < Length2 - index + 1; i++)
    {
        if (binary_search(hashcode, hashcode + Length1 - index + 1, find2(i, index)))
            return true;
    }
    return false;
}
*/