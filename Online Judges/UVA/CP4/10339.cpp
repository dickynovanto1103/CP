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

ii calculateTime(ll timeSame) {
	ll seconds = timeSame % 60;
	int carryMinutes = 0;
	if (seconds >= 30){
		carryMinutes++;
	}
	timeSame /= 60;
	ll minutes = (timeSame % 60) + carryMinutes;
	timeSame /= 60;
	int carryHour = 0;
	if(minutes == 60) {
		carryHour = 1;
		minutes = 0;
	}
	ll hours = (timeSame % 12) + carryHour;
	if(hours == 0) {
		hours = 12;
	}


	// printf("%.2lld:%.2lld\n", hours, minutes);
	return ii(hours,minutes);
}

void solve(){
	int a, b;
	while(scanf("%d %d",&a,&b) != EOF) {
		int diff = abs(a-b);
		double numDaysUntilSame = 43200.0 / diff;
		ll time1Same = round(numDaysUntilSame * (86400 - b));
		ii res = calculateTime(time1Same);
		printf("%d %d %.2d:%.2d\n", a,b, res.first, res.second);

		// ll time2Same = floor(numDaysUntilSame * (86400 - a));
		// calculateTime(time2Same);
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