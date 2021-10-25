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
	int ans[200010];
	while(tc--){
		scanf("%d",&n);
		vii a;
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			a.pb(ii(bil, i));
		}
		sort(a.begin(), a.end());

		int ansIdx = 0;
		for(i=0;i<n;i++){
			int idx = a[i].second;
			ans[idx] = min(ansIdx, a[i].first - 1);
			if(i < n-1) {
				ansIdx = min(ansIdx + 1, a[i+1].first - 1);	
			}
			
		}
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		puts("");
	}
	
	return 0;
};