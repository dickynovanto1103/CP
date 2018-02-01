#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	ll n,m,a[10001],i;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld",&n,&m);
		ll sum = 0, minim = inf, maks = -inf;
		for(i=0;i<n;i++){scanf("%lld",&a[i]); sum+=a[i]; minim = min(minim, a[i]); maks = max(maks, a[i]);}
		if(sum<=m){printf("-1\n");}
		else{
			ll ans = inf;
			ll kiri = 0, kanan = maks, mid;
			while(kiri<=kanan){
				mid = (kiri+kanan)/2;
				ll total = 0;
				for(i=0;i<n;i++){
					if(a[i]>mid){total+=mid;}
					else{total+=a[i];}
				}
				if(total<=m){ans = mid; kiri = mid+1;}
				else{kanan = mid-1;}
			}
			//if(ans==inf){printf("-1\n");}
			printf("%lld\n",ans);
			
		}
	}
	return 0;
}