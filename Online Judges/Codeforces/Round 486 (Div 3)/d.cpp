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

const int maxn = 2e5 + 5;

int main(){
	int n,i,j;
	ll a[maxn];
	scanf("%d",&n);
	set<int> setBil;
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}

	ll duaPangkat[32];
	set<ll> s;
	duaPangkat[0] = 1;
	s.insert(1);
	for(i=1;i<32;i++){
		duaPangkat[i] = 2LL*duaPangkat[i-1];
		s.insert(duaPangkat[i]);
	}
	// for(i=0;i<32;i++){
	// 	for(j=i+1;j<32;j++){
	// 		ll selisih = duaPangkat[j] - duaPangkat[i];
	// 		if(s.find(selisih) == s.end()) {
	// 			break;
	// 		}else{
	// 			printf("duaPangkat[%d]: %lld - duaPangkat[%d]:%lld -> %lld\n",j,duaPangkat[j],i,duaPangkat[i],duaPangkat[j] - duaPangkat[i]);
	// 		}
	// 	}
	// }

	sort(a,a+n);
	int maks = 1;
	ll ans[3];
	for(i=0;i<n;i++){
		ll bil = a[i];
		for(j=0;j<31;j++){
			ll bil1 = a[i] + duaPangkat[j];
			ll bil2 = a[i] + duaPangkat[j+1];
			if(binary_search(a,a+n,bil1) && binary_search(a,a+n,bil2)) {
				printf("3\n");
				printf("%lld %lld %lld\n",bil,bil1,bil2);
				return 0;
			}else{
				if(binary_search(a,a+n,bil1)){
					maks = 2;
					ans[0] = bil;
					ans[1] = bil1;
				}
				if(binary_search(a,a+n,bil2)) {
					maks = 2;
					ans[0] = bil;
					ans[1] = bil2;
				}
			}

		}
	}

	if(maks==1){
		printf("1\n%lld\n",a[0]);

	}else{
		printf("%d\n",maks );
		for(i=0;i<maks;i++){
			if(i){printf(" ");}
			printf("%lld",ans[i]);
		}
		printf("\n");
	}
	return 0;
};