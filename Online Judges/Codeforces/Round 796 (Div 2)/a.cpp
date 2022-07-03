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
	while(tc--){
		int n;
		scanf("%d",&n);
		int ans = n & -n;
		if(ans ^ n) {
			printf("%d\n", ans);
			continue;
		}
		
		for(int i=0;i<30;i++){
			if(!((1<<i) & ans)) {
				ans |= (1<<i);
				break;
			}
		}

		printf("%d\n", ans);
	}
	
	return 0;
};