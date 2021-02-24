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
    int n,count1,count2;
    cin >> n;
    string *p;
    p = NULL;
    p = (string*)malloc(n * sizeof(string));
    if (!p)
        exit(-1);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int q,answer=0;
    cin >> q;
    int temp = q;
    char* ar, * br;
    ar = (char*)malloc(q * sizeof(char));
    br = (char*)malloc(q * sizeof(char));
    ar = NULL;
    br = NULL;
    //if ((!ar) && (!br))
       // exit(-1);
    for(int k=0;k<q;k++)
    {
        int i, j;
        char ch;
        cin >> i >> j >> ch;
        ar[k] = ch;
        if (i == j)
            br[k] = '=';
        else
        {
            int ans,len,len2;
            string temp = p[i];
            len = temp.length();
            while (len)
            {
                ans=KMP(p[j], temp);
                if (ans != -1)
                    break;
                temp.pop_back();
                len--;
            }
            count1 = len;

            temp = p[j];
            len2 = temp.length();
            while (len2)
            {
                ans = KMP(p[i], temp);
                if (ans != -1)
                    break;
                temp.pop_back();
                len2--;
            }
            count2 = len2;
            if (count1 == count2)
                br[k] = '=';
            else if (count1 > count2)
                br[k] = '>';
            else
                br[k] = '<';
        }
        if (ar[k] == br[k])
            answer++;
    }
    cout<<answer;   
    free(p);
    free(ar);
    free(br);
    return 0;
}
*/