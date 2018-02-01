#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int main(){
	int n,q,k,i,j;
	ll a[maxn];
	scanf("%d %d %d",&n,&q,&k);
	for(i=1;i<=n;i++){a[i] = 0;}
	while(q--){
		int com, l,r;
		ll v;
		scanf("%d %d %d %lld",&com,&l,&r,&v);
		if(!(k>=l && k<=r)){continue;}
		if(com==1){
			a[k]+=v;
		}else if(com==2){
			a[k] = max(a[k],v);
		}else if(com==3){
			a[k] = min(a[k],v);
		}
	}
	printf("%lld\n",a[k]);
	return 0;
};