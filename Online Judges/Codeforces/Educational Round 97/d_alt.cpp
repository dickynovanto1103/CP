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

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[400010];
	
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int slot[n + 6];
		memset(slot, 0, sizeof slot);
		int height = 0;
		slot[0] = 1;

		int minim = -1;
		int ans = 1;
		for(i=1;i<n;i++){ 
			// printf("a[%d]: %d\n",i, a[i]);
			if(a[i] > minim){
				slot[height+1]++;
				ans = max(ans, height+1);
				// printf("tambah slot[%d] jadi: %d ans jd: %d\n",height+1, slot[height+1], ans);
				minim = a[i];
			} else {
				ans = max(ans, height);
				slot[height]--;
				// printf("slot[%d] berkurang jadi: %d ans jd: %d\n", height, slot[height], ans);
				if(slot[height] == 0){
					// printf("slot[%d] habis, height jadi: %d\n",height, height + 1);
					//move to next level
					height++;
					ans = max(ans, height);
					minim = -1;
					i--;
					continue;
				}else {
					slot[height+1]++;
					ans = max(ans, height+1);
				}
				minim = a[i];
			}
		}
		printf("%d\n",ans);
		// for(i=0;i<=n+2;i++){
		// 	slot[i] = 0;
		// }
		
	}
	
	return 0;
};