/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

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
    int MaxSize=t.length ();
    int *next, i = 0, j = 0;
    next = (int*)malloc(MaxSize * sizeof(int));
    Getnext(next,t);
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
	string str;
    cin >> str;
    str += 'A';
    int MaxSize = str.length();
    int* next,*bb;
    next = (int*)malloc(MaxSize * sizeof(int));
    bb = (int*)malloc((MaxSize-1) * sizeof(int));
    Getnext(next, str);
    next[0] = 0;
    for (int i = 0; i < MaxSize-1; i++)
    {
        bb[i] = next[i + 1];
    }
    for (int i = 0; i < MaxSize-2; i++)
    {
        printf("%d\n", bb[i]);
    }
    printf("%d", bb[MaxSize-2]);

	return 0;
}
*/