#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
 
const int M=2e5+5;
const int inf=1e9+5;
const int mod=1e9+7;
 
int x[100000];
 
int main() {
    int k,i,n,ans,now,T;
    cin>>T;
    for(k=0;k<T;k++){
            cin>>n;
            now=0;
        for( i=0; i<n; i++) {
            scanf("%d",&x[i]);
            now^=x[i];
        }
            ans=0;
        for( i=0; i<n; i++) {
            if( (now^x[i]) < x[i])
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
   
