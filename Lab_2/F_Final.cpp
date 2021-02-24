#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;

typedef long long int ll;

long long int N=10000000000000000;

ll FAB(ll a,ll b) {
	ll t;
	if(a>=b)
	t=a-b;
	else
	t=b-a;
	return t;
}


ll Distance( char str[],ll t,ll length,ll xr,ll yr,ll xc,ll yc,ll sx,ll sy){
	 ll sum,i,temp,time=0,Dis,x,y,res;
	 if(t<=length){
	 for(i=0;i<t;i++)
	 {
	 	 if(str[i]=='D')
       --yr;
       else if(str[i]=='U')
       ++yr;
       else if(str[i]=='L')
       --xr;
       else if(str[i]=='R')
       ++xr;
	   }
       x=FAB(xr,xc),y=FAB(yr,yc);
       Dis=x+y;
       return Dis;
                  }
	 else if(t>length){
	         temp=t/length;
             res=t%length;
             xr+=temp*sx,yr+=temp*sy;
             for(i=0;i<res;i++)
             {
             	 if(str[i]=='D')
                     --yr;
                 else if(str[i]=='U')
                     ++yr;
                 else if(str[i]=='L')
                     --xr;
                 else if(str[i]=='R')
                     ++xr;
			 }
			 x=labs(xr-xc),y=labs(yr-yc);
             Dis=x+y;
	          return Dis;
                      }
		
	}

ll solve(char str[],ll length,ll xr,ll yr,ll xc,ll yc,ll sx,ll sy){
	ll lb=0,ub=N,dis,mid;
	while(lb<ub)
	{
		mid=lb+(ub-lb)/2;
		dis=Distance(str, mid, length, xr, yr, xc, yc, sx, sy);
		if(dis==mid){
                ub=mid;
                
            }else {
                if(mid<dis){
                    lb=mid+1;
                }
                if(mid>dis){
                    ub=mid;
                }
            }
        }
        if(lb==N)return -1;
        return lb;
    }
    
int main()
{
    ll xr,yr,xc,yc,x,y,Dis,ans,t,temp,res,sx=0,sy=0;
    cin>>xr>>yr>>xc>>yc;
    ll i,length;
    cin>>length;
    char str[100000];
    for(i=0;i<length;i++)
    {
        cin>>str[i];
        if(str[i]=='\n')
        break;
    }
    for(i=0;i<length;i++)
    {
        
        if(str[i]=='D')
       --sy;
       else if(str[i]=='U')
       ++sy;
       else if(str[i]=='L')
       --sx;
       else if(str[i]=='R')
       ++sx;
    }
    ans=solve( str, length, xr, yr, xc, yc, sx, sy);
    printf("%lld",ans);
    return 0;
}
