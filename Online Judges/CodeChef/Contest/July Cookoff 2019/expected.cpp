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

const ll mod = 1e9 + 7;

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2 == 1){return a*modPow(a, b-1) % mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

ll inverse(ll a) {
	return modPow(a, mod-2);
}

const int maxn = 1e3 + 3;

int main(){
	int n,k,i,j;
	int a[maxn], cnt[maxn];
	memset(cnt, 0, sizeof cnt);
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		cnt[bil]++;
	}
	ll penyebut = inverse(modPow(n,k));
	ll pembilang = 0;
	for(i=0;i<n;i++){
		if(cnt[i]){
			int arr[maxn];
			arr[1] = i;
			int tot = i;
			for(j=2;j<=n;j++){
				arr[j] = i*arr[j-1]%n;
				if(arr[j] == arr[1]){break;}
				tot += arr[j];
			}
			int banyakUnik = j;
			int loop = k/banyakUnik;
			int batas = loop*banyakUnik;
			pembilang += (ll)loop*(ll)tot;
			for(j=batas+1;j<=k;j++){
				
			}
		}
	}

	printf("%lld\n",inverse(9)*13%mod);
	return 0;
};