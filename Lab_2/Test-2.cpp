#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
int a[3010];
signed main(){
    int i,j,k,l,r,n,m,t,S,ans=0;
    scanf("%lld%lld",&n,&S);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=0;i<n-2;i++){
        for(j=i+1;j<n-1;j++){
            l=lower_bound(a+j+1,a+n,S-a[i]-a[j])-a;
            r=upper_bound(a+j+1,a+n,S-a[i]-a[j])-a;
            if(a[l]==S-a[i]-a[j]){
                ans+=r-l;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
