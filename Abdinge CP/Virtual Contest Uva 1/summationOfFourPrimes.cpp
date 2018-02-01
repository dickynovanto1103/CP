#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const ll maxn = 1e7;
bool isprime[maxn+5];
int prime[664580];
void sieve(ll n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*2;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

ii findNumber(ll a){
	for(ll i=2;i*i<=maxn;i++){
		if(isprime[a-i] && isprime[i]){return ii(i,a-i);}
	}
}

int main() {
	ll a;
	int i;
	memset(isprime,true,sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=0;i<=maxn;i++){
		if(isprime[i]){prime[cnt] = i; cnt++;}
	}

	while(scanf("%lld",&a)!=EOF){
		if(a<8){printf("Impossible.\n");}
		else{
			if(a%2==0){
				a-=4;
				ii bil = findNumber(a);
				printf("2 2 %lld %lld\n",bil.first,bil.second);
			}else{
				a-=5;
				ii bil = findNumber(a);
				printf("2 3 %lld %lld\n",bil.first,bil.second);
			}
		}
	}
	return 0;
}