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

void solve(int tt){
	printf("Case %d: ", tt);
	int n;
	scanf("%d",&n);
	int mileCost = 0, juiceCost = 0;

	while(n--){
		int dur;
		scanf("%d",&dur);
		// printf("dur: %d\n", dur);
		mileCost += (dur / 30 + 1) * 10;
		juiceCost += (dur / 60 + 1) * 15;
		// printf("curMileCost: %d, curJuiceCost: %d\n", mileCost, juiceCost);
	}
	if(mileCost == juiceCost) {
		printf("Mile Juice %d\n",mileCost);
	}else if(mileCost < juiceCost){
		printf("Mile %d\n", mileCost);
	}else{
		printf("Juice %d\n", juiceCost);
	}
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		solve(tt);
	}

	return 0;
};