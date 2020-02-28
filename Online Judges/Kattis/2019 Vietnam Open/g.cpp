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

const int maxn =1e5 + 5;

ll compute(const vi& a, int mid) {
	ll tot = 0;
	for(int bil: a) {
		ll jarak1 = abs(bil), jarak2 = abs(bil - mid);
		tot += min(jarak1, jarak2);
	}
	return tot;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	ll totNeg = 0, totPos = 0;
	vi listNeg, listPos;	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i] < 0){totNeg += -a[i]; listNeg.pb(a[i]);}
		else if(a[i] > 0){totPos += a[i]; listPos.pb(a[i]);}
	}

	int kiri = -inf, kanan = -1, mid;
	ll ans = (ll)inf*inf;
	if(totNeg == 0){goto hell;}
	
	while(kanan - kiri > 1){
		mid = (kiri+kanan)/2;
		ll jarak2 = compute(listNeg, mid+1);
		ll jarak3 = compute(listNeg, mid);
		if(jarak3 > jarak2) {
			ans = min(jarak2 + totPos, ans);
			kiri = mid;
		}else{
			kanan = mid;
		}
	}
	ans = min(ans, compute(listNeg, kiri + 1) + totPos);
	ans = min(ans, compute(listNeg, kanan-1) + totPos);
	hell:;
	kiri = 1, kanan = inf;
	if(totPos == 0){goto heaven;}
	while(kanan - kiri > 1) {
		mid = (kiri+kanan)/2;
		ll jarak2 = compute(listPos, mid+1);
		ll jarak3 = compute(listPos, mid);
		if(jarak3 > jarak2){
			ans = min(jarak2 + totNeg, ans);
			// printf("ans jd: %lld totNeg: %lld mid: %d jarak3: %lld\n",ans, totNeg, mid, jarak3);
			kiri = mid;
		}else{
			kanan = mid;
		}	
	}
	ans = min(ans, compute(listPos, kiri+1) + totNeg);
	ans = min(ans, compute(listPos, kanan-1) + totNeg);
	heaven:;

	printf("%lld\n",ans);

	return 0;
};
