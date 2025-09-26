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

void solve(){
	int tt=1;
	char s[1000001];
	while(scanf("%s",s) != EOF) {
		// printf("string: %s\n", s);
		printf("Case %d:\n", tt++);
		int len = strlen(s);
		int pref[len+1];
		pref[0] = s[0] == '1';
		for(int i=1;i<len;i++){
			pref[i] = pref[i-1] + (s[i] == '1'? 1: 0);
		}

		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int a, b;
			scanf("%d %d",&a,&b);
			if(a > b) {swap(a,b);}
			int dist = b - a + 1;
			int sum = pref[b] - (a == 0? 0: pref[a-1]);
			if(sum == dist || sum == 0) {
				puts("Yes");
			}else{
				puts("No");
			}
		}
	}

	
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};