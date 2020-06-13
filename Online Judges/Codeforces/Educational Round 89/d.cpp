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

int a[500001];
ii jawab[500001];

const int maxn = 1000000;

bool isprime[maxn + 10];
int prime[78500];

void sieve(int n){
	isprime[0] = isprime[1] = false;
	for(int i=2;i*i<=n;i++){
		if(isprime[i]){
			for(int j=i*i;j<=n;j+=i){
				isprime[j] = false;  
			}
		}
	}
}

vi getPrimeFactors(ll a){
	vi ans;
	ll pf_idx = 0, pf = prime[pf_idx];
	while(pf*pf <= a){
		if(a % pf == 0){
			ans.pb(pf);
			while(a % pf == 0){
				a /= pf;
			}
		}
		pf = prime[++pf_idx];
	}
	if(a != 1){ans.pb(a);}

	return ans;
}

int main(){
	int n,i,j;

	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=2;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt++] = i;
		}
	}
	
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		jawab[i].first = -1;
		jawab[i].second = -1;
		vi pf = getPrimeFactors(a[i]);

		int sz = pf.size();
		if(sz == 1){continue;}
		int ans1 = pf[0], ans2 = 1;
		for(j=1;j<sz;j++){
			ans2 *= pf[j];
		}
		
		jawab[i].first = ans1;
		jawab[i].second = ans2;
	}

	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",jawab[i].first);
	}
	printf("\n");
	
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",jawab[i].second);
	}
	printf("\n");

	return 0;
};