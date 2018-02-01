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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll cnt[200];

int main(){
	ll n,i,j,k;
	scanf("%lld %lld",&n,&k);
	

	//if(k>n){printf("No\n"); return 0;}
	// if(k==n){
	// 	for(i=0;i<k;i++){
	// 		if(i){printf(" ");}
	// 		printf("0");
	// 	}
	// 	printf("\n");
	// 	return 0;
	// }
	
	ll jumlah1 = 0;
	ll nilai = 0;
	for(i=0;i<63;i++){
		if((1LL<<i)&n){
			// printf("i: %lld nilai: %lld\n",i, 1LL<<i);
			nilai+=(1LL<<i);
			// printf("nilai jd: %lld\n",nilai);
			cnt[i+100] = 1;
			jumlah1++;
		}
	}
	// printf("nilai akhir jd: %lld\n",nilai);
	//if(jumlah1>k){printf("No\n"); return 0;} //kurang bilangan
	for(i=162;i>=100;i--){
		if(cnt[i]==1){break;}
	}
	bool valid = false;
	int idx = i;
	for(i=idx;i>0;i--){
		//printf("i: %lld\n",i);
		if(jumlah1==k){valid = true; break;}
		//printf("cnt[%lld]: %lld\n",i,cnt[i]);
		while(cnt[i]>=1){
			cnt[i]--;
			cnt[i-1]+=2;

			jumlah1--; jumlah1+=2;
			if(jumlah1>k){
				//printf("halo\n");
				valid = false; break;
			}
			if(jumlah1==k){valid = true; break;}
		}
		if(jumlah1>k){break;}
		if(jumlah1==k){valid = true; break;}
	}
	if(!valid){printf("No\n"); return 0;}
	vi listBil;
	nilai = 0;
	for(i=162;i>=0;i--){
		//printf("cnt[%lld]: %lld\n",i-100,cnt[i]);
		nilai+=(cnt[i]*(1LL<<(i-100)));
		//printf("nilai akhir banget jd: %lld\n",nilai);
		if(cnt[i]>=1){
			for(j=0;j<cnt[i];j++){
				//printf("yang dipush: %d\n",i-100);
				listBil.pb(i-100);
			}
		}
	}
	// printf("nilai ujung jd: %lld\n",nilai);
	printf("Yes\n");
	for(i=0;i<listBil.size();i++){
		if(i){printf(" ");}
		printf("%lld",listBil[i]);
	}
	printf("\n");
	return 0;
};