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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int av[maxn];

ll k;
ll n,a,b;

ll hitung(int awal, int akhir) {
	int kanan = upper_bound(av, av+k, akhir) - av;
	int kiri = lower_bound(av, av+k, awal) - av;
	return kanan - kiri;
}

ll hitungJawab(int awal, int akhir, ll banyakAv) {
	ll ans;
	if(banyakAv == 0){ans = a;}
	else{ans = b*banyakAv*(ll)(akhir-awal+1);}
	return ans;
}

ll solve(int awal, int akhir) {
	ll banyakAv = hitung(awal, akhir);
	if(awal == akhir){

		return hitungJawab(awal, akhir, banyakAv);
	}else{
		
		ll ans1 = hitungJawab(awal, akhir, banyakAv);
		if(banyakAv == 0){
			return ans1;
		}
		int mid = (awal + akhir)/2;
		ll ans = solve(awal, mid) + solve(mid+1, akhir);

		// printf("awal: %d akhir: %d ans: %lld ans1: %lld\n",awal, akhir, ans, ans1);
		return min(ans, ans1);
	}
}

int main(){
	
	int i,j;
	scanf("%lld %lld %lld %lld",&n,&k,&a,&b);
	
	for(i=0;i<k;i++){
		scanf("%d",&av[i]);
	}
	sort(av, av+k);
	ll ans = solve(1,1<<n);
	printf("%lld\n",ans);
	return 0;
};