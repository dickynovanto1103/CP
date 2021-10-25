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
	scanf("%d %d",&tc,&n);
	while(tc--){
		for(int i=1;i<=n-1;i++){
			printf("M %d %d\n", i, n);
			fflush(stdout);
			// cerr<<"M "<<i<<" "<<n<<endl;
			// fflush(stdout);
			int ans;
			scanf("%d",&ans);
			// cerr<<"ans: "<<ans<<endl;
			// fflush(stdout);
			if(ans == i){
				continue;
			}
			assert(i < ans);

			printf("S %d %d\n", i, ans);
			fflush(stdout);
			scanf("%d",&ans);
		}
		printf("D\n");
		fflush(stdout);
		int ans;
		scanf("%d",&ans);
		if(ans == -1){
			return 0;
		}
	}
	
	return 0;
};