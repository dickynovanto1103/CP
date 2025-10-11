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

int diff(int hNow, int mNow, int h, int m) {
	int minuteNow = hNow * 60 + mNow;
	int minuteLater = h * 60 + m;
	if(minuteLater < minuteNow) {
		minuteLater += 24 * 60;
	}

	return minuteLater - minuteNow;
}

void solve(){
	int n;
	int hNow, mNow;
	scanf("%d %d:%d",&n, &hNow, &mNow);
	int minDur = inf;
	for(int i=0;i<n;i++){
		int h,m, dur;
		scanf("%d:%d %d",&h, &m, &dur);
		minDur = min(minDur, diff(hNow, mNow, h, m) + dur);
	}

	printf("%d\n", minDur);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case %d: ", tt);
		solve();
	}

	return 0;
};