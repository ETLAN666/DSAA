#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int p;
	int d;
}a[11000];
int n;
int ans;
int maxd;
int pa[11000];
bool cmp(node a,node b){
	return a.p>b.p;
}
int find(int x){
	return x==pa[x]?x:find(pa[x]);
}
int main(){
	int T;
	cin>>T; 
	while(T--){
		cin>>n;
		ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].p);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].d);
		maxd=max(maxd,a[i].d);
	}
	for(int i=1;i<=maxd;i++)
		pa[i]=i;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		int x=find(a[i].d);
		if(pa[x]>0){
			pa[x]--;
			ans+=a[i].p;
		}
	}
	printf("%d\n",ans);
	}
	return 0;
}

