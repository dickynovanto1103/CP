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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	int n,x;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&x);
		ll ans = (ll)inf*(ll)inf;
		int d[101], h[101];
		int maks = 0;
		for(i=0;i<n;i++){
			// int d,h;
			scanf("%d %d",&d[i],&h[i]);
			maks = max(maks, d[i]);
		}
		// if(x <= maks){
		// 	printf("1\n");
		// 	continue;
		// }
		for(i=0;i<n;i++){
			if(d[i] >= x){
				ans = 1;
			}else{
				if(d[i] <= h[i]){
					continue;
				}

				int selisih = x-maks;
				ll loop = ((ll)selisih+(ll)d[i]-h[i]-1) / (d[i]-h[i]);
				// printf("selisih: %d d-h: %d\n",selisih,d-h);
				// printf("loop: %lld\n",loop);
				loop++;

				ans = min(ans, (ll)loop);
			}
		}
		if(ans == (ll)inf*inf){printf("-1\n");}
		else{
			// printf("ans: %lld\n",ans);
			assert(ans > 0);
			printf("%lld\n",ans);
		}
	}
	return 0;
};