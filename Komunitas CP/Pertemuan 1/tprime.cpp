#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll maxn = 1e6 + 10;
bool isprime[maxn+10];
int prime[80000];
void sieve(ll n){
	ll i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*2;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

int main(){
	memset(isprime,true,sizeof isprime);
	sieve(maxn);
	int i,j;
	int cnt = 0;
	for(i=0;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}
	set<ll> s;
	for(i=0;i<cnt;i++){
		ll prima = (ll)prime[i];
		s.insert(prima*prima);
	}
	int n;
	scanf("%d",&n);
	while(n--){
		ll bil;
		cin>>bil;
		if(s.find(bil)==s.end()){printf("NO\n");}
		else{printf("YES\n");}
	}
	return 0;
};