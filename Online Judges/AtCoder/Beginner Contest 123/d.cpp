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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool cmp(ll a, ll b){
	return a > b;
}

int main(){
	int cnt[3],k,i,j;

	scanf("%d %d %d %d",&cnt[0],&cnt[1],&cnt[2],&k);
	ll kali = cnt[0]*cnt[1]*cnt[2];
	ll a[3][1010];
	for(i=0;i<3;i++){
		for(j=0;j<cnt[i];j++){
			scanf("%lld",&a[i][j]);
		}
		sort(a[i],a[i]+cnt[i], cmp);
		// printf("i: %d\n",i );
		// for(j=0;j<cnt[i];j++){
		// 	printf("%lld ",a[i][j]);
		// }
		// printf("\n");
	}
	vi listAns;
	vi jawab;
	
	ll kiri = 3, kanan = 30000000000LL, mid,ans;

	while(kiri <= kanan) {
		listAns.clear();
		mid = (kiri+kanan)/2LL;
		int ukuran = 0;
		for(i=0;i<cnt[0];i++){
			for(j=0;j<cnt[1];j++){
				for(int l=0;l<cnt[2];l++){
					ll sum = a[0][i] + a[1][j] + a[2][l];
					if(sum >= mid){
						
						ukuran++;
						if(ukuran > k){goto here;}
					}else{
						break;
					}
				}
			}
		}
		here:;
		if(ukuran >= k){
			ans = mid;
			kiri = mid+1;
			
		}else{
			kanan = mid-1;
		}
	}
	int ukuran = 0;
	for(i=0;i<cnt[0];i++){
		for(j=0;j<cnt[1];j++){
			for(int l=0;l<cnt[2];l++){
				ll sum = a[0][i] + a[1][j] + a[2][l];
				
				if(sum >= ans){
					jawab.pb(sum);
					// printf("i: %d j: %d l: %d dipush: %lld idx: %d\n",i,j,l,sum,ukuran++);
				}else{
					break;
				}
			}
		}
	}

	sort(jawab.begin(), jawab.end(),cmp);
	
	for(i=0;i<k;i++){
		printf("%lld\n",jawab[i]);
	}

	



	return 0;
};