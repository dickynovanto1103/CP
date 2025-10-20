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

bool isOverlap(ii periodWife, ii periodMeeting) {
	int minimEnd, maksStart;
	minimEnd = min(periodWife.second, periodMeeting.second);
	maksStart = max(periodWife.first, periodMeeting.first);
	return maksStart <= minimEnd;
}

void solve(){
	int hStart, mStart, h, m;
	scanf("%d:%d %d:%d",&hStart,&mStart,&h,&m);
	int minutesStart, minutesEnd;
	minutesStart = hStart * 60 + mStart;
	minutesEnd = h * 60 + m;
	vector<ii> periods;
	if(minutesEnd < minutesStart) {
		periods.pb(ii(minutesStart, 24 * 60 - 1));
		periods.pb(ii(0, minutesEnd));
	}else{
		periods.pb(ii(minutesStart, minutesEnd));
	}


	scanf("%d:%d %d:%d",&hStart,&mStart,&h,&m);
	minutesStart = hStart * 60 + mStart;
	minutesEnd = h * 60 + m;
	vector<ii> periodsMeeting;
	if(minutesEnd < minutesStart) {
		periodsMeeting.pb(ii(minutesStart, 24 * 60 - 1));
		periodsMeeting.pb(ii(0, minutesEnd));
	}else{
		periodsMeeting.pb(ii(minutesStart, minutesEnd));
	}

	bool overlap = false;
	for(ii period: periods) {
		for(int i=0;i<periodsMeeting.size();i++){
			if(isOverlap(period, periodsMeeting[i])) {
				overlap = true;
				break;
			}
		}
		if(overlap) {
			break;
		}
	}

	if(overlap) {
		puts("Mrs Meeting");
	}else{
		puts("Hits Meeting");
	}
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