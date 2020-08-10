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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll fac[1000001];
ll duaPangkat[1000001];
const ll mod = 1e9 + 7;

int main(){
	int n,i,j;
	scanf("%d",&n);
	fac[0] = 1;
	for(i=1;i<=n;i++){
		fac[i] = (ll)i*fac[i-1];
		fac[i] %= mod;
		// printf("%d\n",fac[i]);
	}
	duaPangkat[0] = 1;
	for(i=1;i<=n;i++){
		duaPangkat[i] = 2LL * duaPangkat[i-1];
		duaPangkat[i] %= mod;
		// printf("%d\n",duaPangkat[i]);
	}
	ll ans = fac[n]-duaPangkat[n-1];
	ans %= mod;
	if(ans < 0){ans += mod;
	}
	printf("%lld\n",ans);

	// fac[]
	// vi a;
	// for(i=1;i<=n;i++){
	// 	a.pb(i);
	// }
	// int noCycle = 0;
	// do{
	// 	for(i=0;i<n;i++){
	// 		printf("%d ",a[i]);	
	// 	}
	// 	printf("\n");

	// 	int cnt = 0;
		
	// 	for(i=0;i<n;i++){
	// 		for(j=i-1;j>=0;j--){
	// 			if(a[j] > a[i]){printf("%d %d\n",j,i);cnt++; break;}
	// 		}
	// 		for(j=i+1;j<n;j++){
	// 			if(a[j] > a[i]){printf("%d %d\n",i,j);cnt++; break;}
	// 		}
	// 	}
	// 	if(cnt == (n-1)){noCycle++;}
	// 	printf("\n");
	// }while(next_permutation(a.begin(), a.end()));
	// printf("noCycle %d\n",noCycle);
	
	return 0;
};