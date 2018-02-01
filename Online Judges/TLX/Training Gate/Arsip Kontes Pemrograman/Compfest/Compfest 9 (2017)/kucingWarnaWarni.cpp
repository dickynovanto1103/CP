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

const int maxn = 5e4 + 3;

void printImpossible(ll n){
	ll i;
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("-1");
	}
	printf("\n");
}

int main(){
	int tc;
	ll n,m,i,j;
	ll k;
	scanf("%d",&tc);
	ll a[maxn];
	while(tc--){
		scanf("%lld %lld %lld",&n,&m,&k);
		//cek tidak mungkin
		if(k<n){
			printImpossible(n);
			continue;
		}
		ll maks = 0;
		for(i=1;i<=n;i++){
			maks += (ll)min(i,m);
		}
		// printf("maks: %lld\n",maks);
		if(k>maks){
			printImpossible(n);
			continue;
		}
		ll lastBil;
		for(i=1;i<=n;i++){
			if((min(i,m) + (n-i))<k){
				a[i] = (i%m + 1);
				lastBil = a[i];
				k-=(min(i,m));
			}else{
				break;
			}
		}
		
		ll idx = i;

		
		ll sisa = k-(n-idx);

		
		ll selisih = idx - sisa;
		if(selisih==0){
			lastBil++;
			lastBil%=m;
			if(lastBil==0){lastBil = m;}
			a[idx]=lastBil;
		}else{
			ll angkaSeharusnya = a[selisih];
			
			a[idx] = angkaSeharusnya;
		}
		for(i=idx+1;i<=n;i++){a[i] = a[i-1];}
		for(i=1;i<=n;i++){
			if(i>1){printf(" ");}
			printf("%lld",a[i]);
		}
		printf("\n");
	}
	return 0;
};