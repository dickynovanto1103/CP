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
		for(int i=3;i<=n-3;i++){
			int ans = i;
			int pos3 = 1, pos2 = n - 1 - ans;
			if(pos2 < ans && pos3 < pos2 && pos2 < ans) {
				printf("%d %d %d\n", pos2, ans, pos3);
				break;
			}

			pos2 = ans - 1, pos3 = n - ans - pos2;
			if(pos3 >= 0 && pos3 < pos2 && pos2 < ans) {
				printf("%d %d %d\n", pos2, ans, pos3);
				break;
			}
		}


	}
	
	return 0;
};