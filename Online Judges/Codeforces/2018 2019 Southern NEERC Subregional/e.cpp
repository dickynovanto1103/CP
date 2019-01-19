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
ll n,m,t;

int coba(int batas) {
	ll waktu = 0;
	int cnt = 0;
	ll tot = 0;
	for(i=0;i<n;i++){
		if(a[i] > batas){continue;}
		waktu += a[i];
		if(waktu >= t){break;}
		tot += a[i];
		cnt++;
		if(cnt == m) {
			waktu += tot;
			cnt = 0;
			tot = 0;
			if(waktu >= t){break;}
		}
	}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	ll a[maxn];
	while(tc--){
		
		scanf("%d %d %d",&n,&m,&t);
		int minim = inf, maks = -inf;
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
			minim = min(minim, a[i]);
			maks = max(maks, a[i]);
		}
		
		int kiri = minim, kanan = maks, l,r;
		while(kiri <= kanan) {
			int selisih = kanan - kiri;
			l = kiri + selisih/3;
			r = kiri + 2*selisih/3;

		}

		//reset
		for(i=0;i<n;i++){
			update(a[i],-1);
		}
	}
	return 0;
};