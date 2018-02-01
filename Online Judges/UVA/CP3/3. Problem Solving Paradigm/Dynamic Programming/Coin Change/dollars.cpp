#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int coinValue[]={10000,5000,2000,1000,500,200,100,50,20,10,5};//ada 11 koin

ll memo[12][30001];

ll solve(int id, int harga){
	if(harga==0){return 1;}
	if(id==11 || harga<0){return 0;}
	if(memo[id][harga]!=-1){return memo[id][harga];}
	return memo[id][harga] = solve(id+1,harga) + solve(id,harga-coinValue[id]);
}

int banyakDigit(ll n){
	int cnt = 0;
	while(n>0){n/=10; cnt++;}
	return cnt;
}

int main() {
	double harga;
	memset(memo,-1,sizeof memo);
	while(scanf("%lf",&harga)){
		if(fabs(harga)<=eps){break;}
		//printf("%lf\n",harga);
		int total = (int)(harga*100);
		if(total%5==4){total++;}
		//printf("total: %lld\n",total);
		ll ans = solve(0,total);
	
		if(harga>=10.00 && harga<=99.99){printf(" ");}
		else if(harga<10.00){printf("  ");}
		printf("%.2lf",harga);
		//cetak spasi
		int cntDigit = banyakDigit(ans);
		for(int i=0;i<17-cntDigit;i++){printf(" ");}
		printf("%lld\n",ans);
	}
	return 0;
}