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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll jawab;
ll n, l,r;

ll solve(ll bil){
	// printf("bil: %lld\n",bil);
	if(bil == 0 || bil == 1){
		return 1;
	}else{
		return 2LL*solve(bil/2) + 1LL;
	}
	
}

void add(ll awal, ll akhir, ll bil){
	if(awal > r || akhir < l){return;} //out of range
	if(awal == akhir){
		if(bil == 1){
			jawab++;
		}
	}else{
		ll banyakBagi2 = solve(bil/2);
		add(awal, awal + banyakBagi2 - 1, bil/2);
		add(awal + banyakBagi2, awal + banyakBagi2, bil%2);
		add(awal + banyakBagi2 + 1, awal + banyakBagi2 + banyakBagi2, bil/2);
	}
}



int main(){
	
	scanf("%lld %lld %lld",&n,&l,&r);
	l--; r--;
	ll ans = solve(n);
	add(0,ans-1,n);
	printf("%lld\n",jawab);
	// int cnt = 0;
	// for(int i=l;i<=r;i++){
	// 	if(ans[i] == 1){
	// 		cnt++;
	// 	}
	// }
	// printf("%d\n",cnt);
	return 0;
};