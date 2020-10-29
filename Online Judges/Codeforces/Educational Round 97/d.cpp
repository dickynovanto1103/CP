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
	int a[200010], h[200010];
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			h[i+1] = 0;
		}
		int idxNow = 0;
		int minim = 0;
		h[a[idxNow]] = 0;
		for(i=1;i<n;i++){
			if(minim < a[i]){
				h[a[i]] = h[a[idxNow]] + 1;
				minim = a[i];
			}else{
				idxNow++;
				h[a[i]] = h[a[idxNow]] + 1;
				minim = a[i];
			}
		}
		int ans = 0;
		for(i=1;i<=n;i++){
			ans = max(ans, h[i]);
		}
		printf("%d\n",ans);

	}
	
	return 0;
};