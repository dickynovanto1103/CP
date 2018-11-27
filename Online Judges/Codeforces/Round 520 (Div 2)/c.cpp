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

const ll mod = 1e9 + 7;

ll modPow(ll a, ll b){
	if(b == 0){
		return 1;
	}else{
		if(b%2 == 1){return ((a%mod)*(modPow(a,b-1)%mod))%mod;}
		else{
			ll temp = modPow(a,b/2);
			return ((temp%mod)*(temp%mod))%mod;
		}
	}
}

const int maxn = 1e5 + 5;
int pref1[maxn], pref0[maxn];

int main(){
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	string kata;
	cin>>kata;

	for(i=0;i<n;i++){
		if(kata[i] == '0'){pref0[i]++;}
		else{pref1[i]++;}
	}
	for(i=1;i<n;i++){
		pref0[i] += pref0[i-1];
		pref1[i] += pref1[i-1];
	}
	ll sum = 0;
	while(q--){
		int a,b;
		scanf("%d %d",&a,&b);
		a--; b--;
		int banyak0, banyak1;
		if(a == 0){
			banyak0 = pref0[b];	
		}else{
			banyak0 = pref0[b] - pref0[a-1];	
		}
		if(b == 0){
			banyak1 = pref1[b];
		}else{
			banyak1 = pref1[b] - pref1[a-1];
		}

		sum = modPow(2,banyak1) - 1;
		if(sum < 0){sum += mod;}
		ll suku2 = sum;
		ll sum2 = modPow(2, banyak0) - 1;
		if(sum2 < 0){sum2+=mod;}
		sum2 *= suku2;
		sum2 %= mod;
		sum += sum2;
		sum %= mod;
		printf("%lld\n",sum);
	}
	return 0;
};