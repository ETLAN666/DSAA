/*
#include<cstdio>
#include<cstring>
using namespace std;
char decode[26], encode[26], s[2], connect[(int)4e6 + 10];
int nexMap[(int)2e6 + 10];

int main()
{

    int cnt = 26;
    for (int i = 0; i < cnt; i++)
    {
        scanf("%s", s);
        encode[i] = s[0];
        decode[s[0] - 'a'] = i + 'a';
    }

    scanf("%s", connect);
    int lens = strlen(connect);

    for (int i = 0; i < lens; i++)
        connect[i + lens] = encode[connect[i] - 'a'];

    int pos = lens + lens;
    int answer = lens;

    nexMap[0] = -1;
    int nex = -1, index = 0;
    while (index < pos)
    {
        if (nex == -1 || connect[nex] == connect[index])
        {
            index++;
            nex++;
            nexMap[index] = nex;
        }
        else
            nex = nexMap[nex];
    }

    while (pos > 0 && lens < pos + pos)
        pos = nexMap[pos];

    while (pos > 0)
    {
        int after = lens - pos;
        int before = pos;
        bool flag = true;
        for (int i = 0; i < before; i++)
        {
            if (connect[i + after] != decode[connect[i] - 'a'])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            answer = after;
            break;
        }
    }
    printf("%d\n", answer);
    return 0;
}
*/