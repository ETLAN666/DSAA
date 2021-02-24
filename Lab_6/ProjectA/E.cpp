/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#define find1(m,n) hash1[m] - hash1[m + n] * xp[n]
#define find2(m,n) hash2[m] - hash2[m + n] * xp[n]
using namespace std;
const int Hashnum = 139;
char s1[(int)1e5 + 10], s2[(int)1e5 + 10];
int Length1, Length2;
unsigned long long hash1[(int)1e5 + 10], hash2[(int)1e5 + 10], xp[(int)1e5 + 10], hashcode[(int)1e5 + 10];

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

int main()
{
    xp[0] = 1;
    for (int i = 1; i < (int)1e5 + 10; i++)
        xp[i] = xp[i - 1] * Hashnum;

    scanf("%s%s", s1, s2);
    Length1 = strlen(s1);
    Length2 = strlen(s2);

    hash1[Length1] = 0;
    hash2[Length2] = 0;

    for (int i = Length1 - 1; i >= 0; i--)
        hash1[i] = hash1[i + 1] * Hashnum + s1[i] - 'A' + 1;
    for (int i = Length2 - 1; i >= 0; i--)
        hash2[i] = hash2[i + 1] * Hashnum + s2[i] - 'A' + 1;

    int low = 0, high = min(Length1, Length2), mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        Change(mid) ? low = mid + 1 : high = mid;
    }
    (!Change(low)) && ([&]() {low--; return 1; }());
    printf("%d\n", low);
    return 0;
}
*/