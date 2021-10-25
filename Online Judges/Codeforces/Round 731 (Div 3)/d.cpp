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
	int a[200001];
	while(tc--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		vi ans;
		ans.pb(0);
		int pref = a[0];
		for(i=1;i<n;i++){
			int now = a[i];
			int jawab = 0;
			for(j=0;j<30;j++){
				int isUp = pref & (1<<j);
				int nowIsUp = now & (1<<j);
				if(isUp && !nowIsUp) {
					now |= (1<<j);
					jawab |= (1<<j);
				}
			}
			pref = now;
			ans.pb(jawab);
		}
		for(i=0;i<ans.size();i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	
	return 0;
};