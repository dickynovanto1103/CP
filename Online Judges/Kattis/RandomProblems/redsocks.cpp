#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint65 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e7;

ll a[maxn];

int main(){
	ll p,q,i;
	ll maks = 0;
	for(i=1;i<maxn;i++){
		a[i] = ((ll)i*(ll)(i+1LL))/2LL;
	}
	maks = a[maxn-1];
	// printf("%lld %lld %lld\n",a[0],a[1],a[2]);
	while(scanf("%lld %lld",&p,&q), (p || q)) {
		// printf("p: %lld q: %lld\n",p,q);
		if(p == 0){printf("0 2\n");}
		else if(p == q){printf("2 0\n");}
		else{
			ll gcd = __gcd(p,q);
			p /= gcd; q /= gcd;
			ll minp = 1, minQ = 1249975000;
			if(minp * q > p*minQ){printf("impossible\n"); continue;}
			bool found = false;
			ll pAwal = p, qAwal = q;
			for(i=2;i<=50000;i++) {
				if((i * (i-1)) % p == 0) {
					// printf("i: %lld\n", i);
					uint65 hasil = ((uint65)i*(uint65)(i-1) / (uint65)p) * (uint65)q;
					uint65 sq = (uint65)sqrtl(hasil);
					if(sq * (sq+1) == hasil){
						if(sq + 1 > 50000){continue;}
						cout<<i<<" "<<sq-i+1<<endl;
						// printf("%lld %lld\n",i,sq-i+1);
						// if(sq + 1 > 50000){assert(false);}
						found = true;
						break;
					}
				}
			}
			if(found){continue;}
			
		}
		printf("impossible\n");
	}
	return 0;
};