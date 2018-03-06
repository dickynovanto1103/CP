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

const int maxn = 1e5 + 5;

struct pasangan
{
	int bil, banyak;
};

bool cmp(pasangan a, pasangan b){
	return a.bil < b.bil;
}

int main(){
	int tc,n,k, b[maxn];
	int i,j;
	pasangan pas[maxn];
	ll prefSum[maxn];
	scanf("%d",&tc);
	while(tc--){
		memset(prefSum,0,sizeof prefSum);
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%d",&pas[i].bil);
		}
		for(i=0;i<n;i++){
			scanf("%d",&pas[i].banyak);

		}
		sort(pas,pas+n,cmp);

		ll awal = 0, akhir = -1;
		for(i=0;i<n;i++){
			akhir+=pas[i].banyak;
			if(i==0){prefSum[i] = pas[i].banyak-1;}
			else{prefSum[i] = prefSum[i-1] + pas[i].banyak;}
		}
		for(i=0;i<k;i++){
			ll banyak;
			scanf("%lld",&banyak);
			// printf("banyak: %lld\n",banyak);
			if(i%2==0){
				awal = akhir-banyak+1;
				// printf("awal jadi: %lld akhir: %lld\n",awal,akhir);
			}else{
				akhir = awal+banyak-1;
				// printf("aw/al: %lld akhir jadi: %lld\n",awal,akhir);
			}
		}
		// printf("awal: %lld akhir: %lld\n",awal,akhir);
		// printf("prefSum\n");
		// for(i=0;i<n;i++){
		// 	if(i){printf(" ");}
		// 	printf("%lld",prefSum[i]);
		// }
		// printf("\n");
		ll sum = 0;
		int idx = lower_bound(prefSum,prefSum+n,awal) - prefSum;
		// printf("idx: %d\n", idx);
		sum = (ll)pas[idx].bil*(ll)(prefSum[idx] - awal + 1LL);
		// printf("sum awal: %lld\n",sum);
		if(akhir<prefSum[idx]){
			sum -= (ll)pas[idx].bil*(ll)(prefSum[idx]-akhir);
			printf("%lld\n",sum); continue;
		}
		for(i=idx+1;i<n;i++){
			// printf("i: %d prefSum: %lld\n",i, prefSum[i]);
			if(prefSum[i]<=akhir){
				sum+=((ll)pas[i].bil*(ll)(prefSum[i] - prefSum[i-1]));
			}else{
				// printf("masuk sini\n");
				sum+=((ll)pas[i].bil*(ll)(akhir - prefSum[i-1]));
				break;
			}
		}
		//mulai hitung dari awal

		printf("%lld\n",sum);
		
	}
	return 0;
};