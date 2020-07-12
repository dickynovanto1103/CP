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

int a[10001];
int n;
int dp[10001][5];
const int maxNote = 3;
const int minNote = 0;

int solve(int idx, int note) {
	if(idx == (n-1)){return 0;}
	if(dp[idx][note] != -1){return dp[idx][note];}
	if(a[idx] > a[idx+1]) {
		if(note == minNote){ //coba break dengan note di atas"nya atau note sekarang
			int ans = inf;
			for(int i=note;i<=maxNote;i++){
				ans = min(solve(idx+1, i) + 1, ans);
			}
			return dp[idx][note] = ans;
		}else{
			int ans = inf;
			for(int i=note-1;i>=minNote;i--){
				ans = min(ans, solve(idx+1, i));
			}
			return dp[idx][note] = ans;
		}
	}else if(a[idx] == a[idx+1]) {
		return dp[idx][note] = solve(idx+1, note);
	}else {
		if(note == maxNote) {
			int ans = inf;
			for(int i=note;i>=minNote;i--) {
				ans = min(ans, solve(idx+1, i) + 1);
			}
			return dp[idx][note] = ans;
		}else{
			int ans = inf;
			for(int i=note+1;i<=maxNote;i++){
				ans = min(ans, solve(idx+1, i));
			}
			return dp[idx][note] = ans;
		}
	}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		memset(dp, -1, sizeof dp);
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		int ans = inf;
		for(i=minNote;i<=maxNote;i++){
			ans = min(ans, solve(0, i));
		}
		printf("%d\n",ans);
	}
	
	return 0;
};