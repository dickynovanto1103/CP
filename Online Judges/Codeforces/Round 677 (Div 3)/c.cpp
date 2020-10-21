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
	int a[300001];
	while(tc--){
		scanf("%d",&n);
		int maks = -1;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			maks = max(maks, a[i]);
		}

		bool found = false;
		int ans = -1;
		for(i=0;i<n;i++){
			if(a[i] == maks) {
				if(i == 0) {
					if(a[i+1] < maks) {
						ans = i+1;
						break;	
					}
					
				} else if(i == (n-1)){
					if(a[i-1] < maks) {
						ans = i+1;
						break;	
					}
					
				} else {
					if(a[i+1] < maks || a[i-1] < maks){
						ans = i+1;
						break;
					}
				}
			}
		}
		printf("%d\n",ans);

	}
	
	return 0;
};