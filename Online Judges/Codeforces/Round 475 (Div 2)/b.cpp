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

int main(){
	ll n,i,j,a,b,c,t;
	ll waktu[1011];
	int cnt[1011];
	memset(cnt,0,sizeof cnt);
	scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&t);
	ll ans = a*n;

	for(i=0;i<n;i++){
		scanf("%lld",&waktu[i]);
		cnt[waktu[i]]++;
	}
	int jumlahBukuSekarang = 0;
	ll profit = 0, rugi = 0;
	for(i=1;i<=t;i++){
		profit+=((ll)jumlahBukuSekarang*c);
		rugi+=((ll)jumlahBukuSekarang*b);
		jumlahBukuSekarang+=cnt[i];
	}
	// printf("profit: %lld rugi: %lld\n",profit, rugi);
	
	if(profit>=rugi){
		ans+=profit;
		ans-=rugi;
	}
	printf("%lld\n",ans);

	return 0;
};