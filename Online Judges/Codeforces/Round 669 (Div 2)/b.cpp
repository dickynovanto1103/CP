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
	int tc,n,i,j;
	scanf("%d",&tc);
	int a[1001];
	while(tc--){
		scanf("%d",&n);
		int maks = 0, idx = 0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(maks < a[i]){
				maks = a[i];
				idx = i;
			}
		}
		bool vis[1001];
		memset(vis, false, sizeof vis);
		vi ans;
		ans.pb(maks);
		vis[idx] = true;
		int cur = maks;
		for(i=0;i<n-1;i++){
			//find divisors of cur
			vi div;
			for(j=cur;j>=1;j--){
				if(cur % j == 0){
					div.pb(j);
					// printf("div: %d\n",j);
				}
			}
			for(int k=0;k<div.size();k++){
				int nextGcd = div[k];
				// printf("nextGcd: %d\n",nextGcd);
				bool found = false;
				for(j=0;j<n;j++){
					if(vis[j]){continue;}
					int gcd = __gcd(cur, a[j]);
					if(gcd == nextGcd){
						vis[j] = true;
						ans.pb(a[j]);
						// printf("pick\n");
						found = true;
						cur = gcd;
						break;
					}
				}
				if(found){break;}
			}
			
		}

		for(i=0;i<ans.size();i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	
	return 0;
};