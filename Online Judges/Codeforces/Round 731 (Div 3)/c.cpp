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

bool isPossible(int totalLine, int request) {
	return request == 0 || totalLine >= request;
}

int main(){
	int tc,i,j,k,n,m;
	scanf("%d",&tc);
	int a[101], b[101];
	while(tc--){
		scanf("%d %d %d",&k,&n,&m);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<m;i++){
			scanf("%d",&b[i]);
		}
		int atas = 0, bawah = 0;
		int totalLine = k;
		vi ans;
		while(atas < n || bawah < m) {
			bool valid = false;
			if(atas < n){
				if(isPossible(totalLine, a[atas])) {
					valid = true;
					ans.pb(a[atas]);
					if(a[atas] == 0) {
						totalLine++;
					}
					atas++;
					continue;
				}
			}
			if(bawah < m) {
				if(isPossible(totalLine, b[bawah])) {
					valid = true;
					ans.pb(b[bawah]);
					if(b[bawah] == 0){
						totalLine++;
					}
					bawah++;
					continue;
				}
			}
			if(!valid) {
				break;
			}
		}
		if(ans.size() < (n + m)) {
			printf("-1\n");
			continue;
		}
		for(i=0;i<ans.size();i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	
	return 0;
};