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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

const ll mod = 1e9 + 7;

ll mul(ll a, ll b){
	return a*b%mod;
}

ll fac[maxn], invFac[maxn];
ll ans[maxn];

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b % 2 == 1){return a*modPow(a, b-1) % mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

void sub(ll &a, ll b){
	a -= b;
	if(a < 0){a += mod;}
}

void preprocess() {
	fac[0] = invFac[0] = 1;
	for(int i=1;i<maxn;i++){
		fac[i] = mul(fac[i-1], i);
		invFac[i] = modPow(fac[i], mod-2);
	}
}

bool cmp(ii a, ii b){
	if(a.first == b.first){return a.second < b.second;}
	return a.first < b.first;
}

ll findWays(ii a, ii b){
	if(a.first <= b.first && a.second <= b.second){
		int selisihX = b.first - a.first;
		int selisihY = b.second - a.second;
		return mul(fac[selisihY + selisihX], mul(invFac[selisihX], invFac[selisihY]));	
	}else{
		return 0;
	}
}

int main(){
	int h,w,n,i,j;
	preprocess();
	scanf("%d %d %d",&h,&w,&n);
	vector<ii> p(n);
	for(i=0;i<n;i++){
		scanf("%d %d",&p[i].first,&p[i].second);
	}
	p.pb(ii(h,w));

	for(i=0;i<n+1;i++){
		ans[i] = findWays(ii(1,1), p[i]);
	}

	//ga bs kalo ga disort nanti pengurangannya tidak bs tertarur, harusnya dikurangi oleh a, malah dikurangi sama yang lebih besar dr a..jd salah
	
	for(i=0;i<n+1;i++){
		for(j=0;j<n+1;j++){
			if(j == i){continue;}
			ll pengurangan = mul(ans[i], findWays(p[i], p[j]));
			assert(pengurangan >= 0);
			sub(ans[j], pengurangan);
		}
	}
	printf("%lld\n",ans[p.size() - 1]);
	return 0;
};