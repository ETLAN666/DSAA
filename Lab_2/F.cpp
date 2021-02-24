#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;


int main()
{
    int xr,yr,xc,yc,x,y,Dis;
    int L=2,D=2,U=0,R=0;
    cin>>xr>>yr>>xc>>yc;
    printf("\n");
    int i,sum=0,length;
    cin>>length;
    printf("\n");
    char str[100000];
    for(i=0;i<length;i++)
    {
        cin>>str[i];
        if(str[i]=='\n')
        break;
    }

    int a[100000];
    for(i=0;i<length;i++)
    {
        
        if(str[i]=='D'||str[i]=='L')
       a[i]=2;
       else if(str[i]=='U'||str[i]=='R')
       a[i]=0;
    }
    for(i=0;i<length;i++)
    {
        sum+=a[i];
    }
    x=abs(xr-xc),y=abs(yr-yc);
    Dis=x+y;
    if(sum==0)
    printf("%d",-1);
    return 0;
}
