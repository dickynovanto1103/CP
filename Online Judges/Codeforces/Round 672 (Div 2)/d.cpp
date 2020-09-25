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

bool isOverlap(int x, int y, int x1, int y1) {
	return max(x, x1) <= min(y, y1);
}

const int maxn = 3e5 + 5;
const ll mod = 998244353;
ll fac[maxn], invFac[maxn];

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b % 2 == 1){
			return a * modPow(a, b-1) % mod;
		}else{
			ll temp = modPow(a, b/2);
			return temp*temp%mod;
		}
	}
}

void preprocess(){
	int i,j;
	fac[0] = invFac[0] = 1;
	for(i=1;i<maxn;i++){
		fac[i] = (ll)i * fac[i-1];
		fac[i] %= mod;
		invFac[i] = modPow(fac[i], mod-2);
	}
}

ll comb(int a, int b){
	ll num = fac[a];
	ll num1 = invFac[b];
	ll num2 = invFac[a - b];
	ll kali = num1 * num2 % mod;
	kali *= num;
	kali %= mod;
	return kali;
}

struct vec
{
	int node, isOpen;
};



bool cmp(vec a, vec b){
	if(a.node == b.node){
		return a.isOpen > b.isOpen;
	}
	return a.node < b.node;
}

ll combJadi[maxn];

void process(int bawah){
	for(int i=bawah;i<maxn;i++){
		combJadi[i] = comb(i, bawah);
	}
}

int main(){
	int n,k,i,j;
	ii a[300001];
	preprocess();
	while(scanf("%d %d",&n,&k) != EOF){
		vector<vec> v;
		for(i=0;i<n;i++){
			scanf("%d %d",&a[i].first, &a[i].second);
			vec ve;
			ve.node = a[i].first, ve.isOpen = true;
			v.pb(ve);

			ve.node = a[i].second, ve.isOpen = false;
			v.pb(ve);
		}
		if(k == 1){printf("%d\n",n); continue;}
		process(k);

		sort(v.begin(), v.end(), cmp);

		ll ans = 0;
		int sz = v.size();
		ll cnt = 0;
		for(i=0;i<sz;i++){
			vec ve = v[i];
			int node = ve.node, isOpen = ve.isOpen;
			if(isOpen) {
				cnt++;
				if(cnt == k){
					ans++;
					ans %= mod;
				}else if(cnt > k){
					ll selisih = combJadi[cnt] - combJadi[cnt-1];
					selisih %= mod;
					if(selisih < mod){selisih+=mod;}
					ans += selisih;
					ans %= mod;
				}
			}else{
				cnt--;
			}
		}
		// for(i=0;i<n;i++){
		// 	int x = a[i].first, y = a[i].second;
		// 	int kiri = i, kanan = n-1, mid, answer;
		// 	while(kiri <= kanan){
		// 		mid = (kiri + kanan)/2;
		// 		ii el = a[mid];
		// 		if(isOverlap(x, y, el.first, el.second)) {
		// 			answer = mid;
		// 			kiri = mid+1;
		// 		}else{
		// 			kanan = mid-1;
		// 		}
		// 	}
		// 	int selisih = answer - i + 1;
		// 	printf("i: %d ans: %d\n",i, answer);
		// 	if(selisih >= k){
		// 		ans += comb(selisih-1, k-1);
		// 		printf("%s\n", );
		// 		ans %= mod;
		// 	}
		// }
		printf("%lld\n",ans);
	}
	
	return 0;
};