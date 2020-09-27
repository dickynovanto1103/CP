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

const int maxn = 3e5 + 5;
int a[maxn];
bool isMax[maxn];
bool isMinim[maxn];

int main(){
	int tc,i,j,n,q;
	scanf("%d",&tc);
	memset(isMinim, false, sizeof isMinim);
	memset(isMax, false, sizeof isMax);
	
	while(tc--){
		scanf("%d %d",&n,&q);
		a[0] = -inf;
		isMax[0] = isMinim[0] = false;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			isMax[i] = false; isMinim[i] = false;
		}
		isMinim[n+1] = isMax[n+1] = false;
		a[n+1] = -inf;
		
		ll ans = 0;
		for(i=1;i<=n;i++){
			if(a[i] > a[i-1] && a[i] > a[i+1]) {
				isMax[i] = true;
				ans += a[i];
			}else if(a[i] < a[i-1] && a[i] < a[i+1]) {
				isMinim[i] = true;
				ans -= a[i];
			}
		}
		printf("%lld\n",ans);
		while(q--){
			int x,y;
			scanf("%d %d",&x,&y);
			//do some reset first
			for(i=x-1;i<=x+1;i++){
				if(isMinim[i]){ans += a[i]; isMinim[i] = false;}
				else if(isMax[i]){
					ans -= a[i]; isMax[i] = false;
					// printf("ans jd: %lld i: %d\n",ans,i);
				}
			}
			for(i=y-1;i<=y+1;i++){
				if(isMinim[i]){ans += a[i]; isMinim[i] = false;}
				else if(isMax[i]){
					// printf("isMax[%d]: %d\n",i, isMax[i]);
					ans -= a[i]; isMax[i] = false;
					// printf("here ans jd: %lld i: %d\n",ans,i);
				}
			}
			
			swap(a[x], a[y]);

			for(i=x-1;i<=x+1;i++){
				if(i >= 1 && i <= n){
					// printf("tinjau x a[%d]: %d\n",i, a[i]);
					if(a[i] > a[i-1] && a[i] > a[i+1]){
						isMax[i] = true;
						ans += a[i];
						// printf("ans jadi: %lld setelah ditambah a[%d]: %d\n",ans, i, a[i]);
					}else if(a[i] < a[i-1] && a[i] < a[i+1]) {
						isMinim[i] = true;
						ans -= a[i];
						// printf("ans jadi: %lld setelah dikurang a[%d]: %d\n",ans, i, a[i]);
					}
				}
			}
			for(i=y-1;i<=y+1;i++){
				if(i >= 1 && i <= n){
					// printf("tinjau y a[%d]: %d\n",i, a[i]);
					if(a[i] > a[i-1] && a[i] > a[i+1] && !isMax[i]){
						isMax[i] = true;
						ans += a[i];
						// printf("ans jadi: %lld setelah ditambah a[%d]: %d\n",ans, i, a[i]);
					}else if(a[i] < a[i-1] && a[i] < a[i+1] && !isMinim[i]) {
						isMinim[i] = true;
						ans -= a[i];
						// printf("ans jadi: %lld setelah dikurang a[%d]: %d\n",ans, i, a[i]);
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	
	return 0;
};