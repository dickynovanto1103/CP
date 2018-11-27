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

const ll mod = 998244353;

const int maxn = 2e5 + 5;

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2 ==1){return (a*modPow(a,b-1))%mod;}
		else{
			ll temp = modPow(a,b/2);
			return (temp*temp)%mod;
		}
	}
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	string a,b;
	cin>>a>>b;
	if(m > n){
		int selisih = m-n;
		string nol = "";
		for(i=0;i<selisih;i++){nol += '0';}
		a = nol + a;
	}else{
		int selisih = n-m;
		string nol = "";
		for(i=0;i<selisih;i++){nol += '0';}
		b = nol + b;
	}
	// cout<<a<<" "<<b<<endl;
	ll contribute[maxn];
	memset(contribute, 0, sizeof contribute);
	n = a.length();
	for(i=0;i<n;i++){
		if(a[i] == '1'){
			contribute[i] = modPow(2,n-i-1);
			// printf("contribute[%d]: %lld\n",i,contribute[i]);
		}
	}
	for(i=maxn-2;i>=0;i--){
		contribute[i] += contribute[i+1];
		contribute[i] %= mod;
		// printf("contribute[%d] jadi: %lld\n", i,contribute[i]);
	}
	ll ans = 0;
	m = b.length();
	for(i=0;i<m;i++){
		if(b[i] == '1'){
			ans += contribute[i];
			ans %= mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
};