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

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		bool vis[51];
		int a[51];
		memset(vis, false, sizeof vis);
		int sum = 0;
		int pos = 0, neg = 0;

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i] < 0){
				neg += (-a[i]);
			}else{
				pos += a[i];
			}
			sum += a[i];
		}
		if(sum == 0){
			printf("NO\n");
			continue;
		}
		if(pos > neg) {
			sort(a,a+n, cmp);
		}else{
			sort(a,a+n);	
		}
		
		sum = 0;
		vi ans;

		while(ans.size() < n) {
			int tambah = 0 - sum;
			bool found = false;

			for(i=0;i<n;i++){
				if(!vis[i] && a[i] != tambah) {
					found = true;
					vis[i] = true;
					ans.pb(a[i]);
					sum += a[i];
					break;
				}
			}
			if(!found){break;}
		}
		if(ans.size() < n){
			printf("NO\n");
		}else{
			printf("YES\n");
			for(i=0;i<n;i++){
				if(i){printf(" ");}
				printf("%d",ans[i]);
			}
			printf("\n");
		}
	}
	
	return 0;
};