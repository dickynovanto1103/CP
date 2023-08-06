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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc;
	scanf("%d",&tc);
	int a[200010];
	while(tc--){
		int n;
		scanf("%d",&n);
		vi pos;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i] != 0) {
				pos.pb(i);
			}
		}

		if(pos.size() % 2 == 1) {puts("-1"); continue;}
		vii v;
		if(pos.size() == 0) {
			for(int i=0;i<n;i++){
				v.pb(ii(i, i));
			}

		}else{
			int lastPos = 0;
			for(int i=0;i<(int)pos.size() - 1;i+=2){
				while(lastPos < pos[i]) {
					v.pb(ii(lastPos, lastPos));
					lastPos++;
				}
				if(a[pos[i]] != a[pos[i+1]]) {
					for(int j=pos[i];j<=pos[i+1];j++){
						v.pb(ii(j,j));
					}
				}else{
					int curPos = pos[i];
					for(int j=pos[i];j<=pos[i+1] - 2;j++){
						v.pb(ii(j,j));
					}

					v.pb(ii(pos[i+1] - 1, pos[i+1]));
				}
				lastPos = pos[i+1] + 1;
			}

			while(lastPos < n) {
				v.pb(ii(lastPos, lastPos));
				lastPos++;
			}
		}
		

		printf("%d\n", v.size());
		for(ii pas: v) {
			printf("%d %d\n", pas.first + 1, pas.second + 1);
		}
	}
	
	return 0;
};