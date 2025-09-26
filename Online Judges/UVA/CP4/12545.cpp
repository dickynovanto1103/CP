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
	string s,t;
	cin>>s>>t;
	int impossibleCnt = 0;
	int canTransformCnt = 0;
	int questionWith1Cnt = 0;
	int questionWith0Cnt = 0;
	int len = s.size();
	int ans=0;
	for(int i=0;i<len;i++){
		if(s[i] == '1' && t[i] == '0') {
			impossibleCnt++;
		}else if(s[i] == '0' && t[i] == '1') {
			canTransformCnt++;
		}else if(s[i] == '?') {
			if(t[i] == '1') {
				questionWith1Cnt++;
			}else{
				questionWith0Cnt++;
			}
		}
	}

	if(impossibleCnt > (canTransformCnt + questionWith1Cnt)) {
		puts("-1");
	}else{
		//swap first
		int minim = min(impossibleCnt, canTransformCnt);
		impossibleCnt -= minim;
		canTransformCnt -= minim;

		ans += minim;

		//then swap using question mark
		ans += 2*impossibleCnt;
		questionWith1Cnt -= impossibleCnt;
		impossibleCnt = 0;

		//then just adjustment
		ans += canTransformCnt + questionWith1Cnt + questionWith0Cnt;
		printf("%d\n", ans);
	}
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	// printf("tc; %d\n", tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case %d: ", tt);
		solve();
	}

	return 0;
};