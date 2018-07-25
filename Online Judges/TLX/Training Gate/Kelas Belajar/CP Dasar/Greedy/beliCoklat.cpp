#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct pas{
	ll harga,banyak;
};

bool cmp(pas a, pas b){return a.harga < b.harga;}

int main() {
	ll budget;
	pas pasangan[100010];
	int n,i;
	scanf("%d %lld",&n,&budget);
	for(i=0;i<n;i++){
		scanf("%lld %lld",&pasangan[i].harga,&pasangan[i].banyak);
	}
	sort(pasangan,pasangan+n, cmp);
	/*for(i=0;i<n;i++){
		printf("%lld %lld\n",pasangan[i].harga,pasangan[i].banyak);
	}*/
	ll cnt = 0;
	for(i=0;i<n;i++){
		ll harga = pasangan[i].harga, banyak = pasangan[i].banyak;
		//ll total = harga*banyak;
		if(budget/banyak>=harga){
			cnt+=banyak;
			while(banyak>0){budget-=harga; banyak--;}
			//printf("membeli sebanyak %lld tipe %d budget sisa: %lld\n",banyak,i,budget);
		}else{
			ll counter = budget/harga;//sisa uang dibagi sama harga
			cnt = cnt+counter;
			budget= budget - (counter*harga);
			//printf("membeli sebanyak %lld tipe %d budget sisa: %lld\n",counter,i,budget);
		}
	}
	printf("%lld\n",cnt);


	return 0;
}