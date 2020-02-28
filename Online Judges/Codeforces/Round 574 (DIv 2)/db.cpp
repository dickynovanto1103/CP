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

vector<vi> adj;

const int maxn = 1e5 + 5;

const ll mod = 998244353;

int parse(int n, int idx){
	int cnt = 0;
	while(n){
		int mod = n%10;
		adj[idx].pb(mod);
		n/=10;
		cnt++;
	}
	return cnt;
}

ll modPow(ll a, ll b) {
	if(b == 0){
		return 1;
	}else{
		if(b%2 == 1){
			return a*modPow(a, b-1)%mod;
		}else{
			ll temp = modPow(a, b/2);
			return temp*temp%mod;
		}
	}
}

int cntPanjang[20];
int sepuluh[25];

int main(){
	int n,i,j;
	scanf("%d",&n);
	adj.assign(n+1, vi());
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		int pjg = parse(a[i], i);
		cntPanjang[pjg]++;
	}
	// for(i=0;i<20;i++){
	// 	if(cntPanjang[i]){
	// 		printf("cntPanjang[%d]: %d\n",i,cntPanjang[i]);
	// 	}
	// }
	ll ans = 0;

	for(i=0;i<n;i++){
		for(j=0;j<adj[i].size();j++){
			int bil = adj[i][j];
			int idx = j;
			for(int k=0;k<20;k++){
				if(cntPanjang[k]){
					//hitung kalo bil di kiri dan di kanan
					//di kiri
					// printf("bil: %d idx: %d maksNormal: %d k: %d\n",bil, idx, idx+1,k);
					int maksNormal = idx+1;
					if(k >= maksNormal){
						// printf("lebih ditambah %d di %d\n",bil*cntPanjang[k], idx*2+1);
						sepuluh[idx*2 + 1] += (bil*cntPanjang[k]);
						sepuluh[idx*2 + 1] %= mod;
					}else{
						// printf("kurang ditambah %d di %d\n",bil*cntPanjang[k], idx + k);
						sepuluh[idx + k] += (bil*cntPanjang[k]);
						sepuluh[idx + k] %= mod;
					}
					maksNormal = idx;
					// printf("maksNormal; %d\n",maksNormal);
					//di kanan
					if(k >= maksNormal){
						// printf("lebih ditambah %d di %d\n",bil*cntPanjang[k], idx*2);
						sepuluh[idx*2] += (bil*cntPanjang[k]);
						sepuluh[idx*2] %= mod;
					}else{
						// printf("kurang ditambah %d di %d\n",bil*cntPanjang[k], idx + k);
						sepuluh[idx + k] += (bil*cntPanjang[k]);
						sepuluh[idx + k] %= mod;
					}					
				}
			}
			// int pangkat1 = j*2, pangkat2 = j*2 + 1;
			// ll temp = bil*n*modPow(10, pangkat1)%mod;
			// ll temp2 = bil*n*modPow(10, pangkat2)%mod;
			// ans += temp; ans%=mod;
			// ans += temp2; ans%=mod;
		}
	}
	for(i=0;i<22;i++){
		// printf("sepuluh[%d]: %d\n",i, sepuluh[i]);
		ll temp = sepuluh[i] * modPow(10, i)%mod;
		ans += temp; ans %= mod;
	}
	printf("%lld\n",ans);
	return 0;
};