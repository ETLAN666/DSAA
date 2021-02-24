#include <iostream>
#include <algorithm>
#include <cmath>
#include<cstdio>

using namespace std;

typedef long long int ll;

typedef struct Orcs{
    ll HP;
    ll ATK;
    ll Biggest;
}Orcs;

bool cmp(Orcs a,Orcs b)
{
     return (a.HP - a.ATK) > (b.HP - b.ATK);
}


int main() {
    ll n, p ,q,i,dex=0;
    scanf("%lld%lld%lld",&n,&p,&q);
    ll Mix = pow(2,p);
    ll answer=0;
    Orcs a[n];
    for ( i = 0; i < n; ++i)
    {
        scanf("%lld%lld", &a[i].HP, &a[i].ATK);
        answer+=a[i].ATK,a[i].Biggest = Mix*a[i].HP-a[i].ATK;
    }
    if (q==0)
       cout<<answer;
    else if(q>0)
    {
        sort(a, a + n, cmp);
        ll x = answer, y;
        for (; dex < q; ++dex)
        {
            if (a[dex].ATK >= a[dex].HP) 
            {
                break;
            }
            x += a[dex].HP - a[dex].ATK;
        }
        ll dif = a[dex-1].HP - a[dex-1].ATK;
        for ( i = 0; i < n; ++i) 
        {
            if (i < dex) 
            {
                
                y = max(x, x + a[i].Biggest - (a[i].HP - a[i].ATK));
            } 
            else 
            {
                
                if (dex>=q)
                    y = max(x,x + a[i].Biggest - dif);
                else
                    y = max(x,x+a[i].Biggest);
            }
            answer = max(answer,y);
        }
        cout<<answer;
    }
    return 0;
}

