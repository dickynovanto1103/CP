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

const int maxn = 1e5 + 5;
int diff2[maxn];
int diff[maxn];
int a[maxn];

int findLongestSubstring(int n) {
	int ans = 2;
	int curDiff = -2*inf;
	int maks = 2;

	for(int i=0;i<n-1;i++){
		int selisih = a[i+1] - a[i];
		if(selisih == curDiff) {
			ans++;
		}else{
			curDiff = selisih;
			ans = 2;
		}
		maks = max(maks, ans);
	}
	return maks;
}

struct pas{
	int diff;
	int curAns;
};

pas pref[maxn];
pas suff[maxn];

void genPref(int n) {
	pref[0].diff = 0;
	pref[0].curAns = 1;
	pref[1].curAns = 2;
	pref[1].diff = (a[1] - a[0]);
	// printf("asli: %d a[1]: %d a[0]: %d\n", a[1] - a[0], a[1], a[0]);
	// printf("halo diff: %d\n", pref[1].diff);
	// printf("pref[%d]: diff %d diff %d\n",1, pref[1].diff, pref[1].curAns);
	for(int i=2;i<n;i++){
		pref[i].diff = (a[i] - a[i-1]);
		pref[i].curAns = (pref[i].diff == pref[i-1].diff ? pref[i-1].curAns+1 : 2);
		// printf("pref[%d] diff: %d ans: %d\n", i, pref[i].diff, pref[i].curAns);
	}
}

void genSuff(int n) {
	suff[n-1].diff = 0;
	suff[n-1].curAns = 1;
	suff[n-2].diff = (a[n-1] - a[n-2]);
	suff[n-2].curAns = 2;
	for(int i=n-3;i>=0;i--){
		suff[i].diff = (a[i+1] - a[i]);
		suff[i].curAns = (suff[i+1].diff == suff[i].diff ? suff[i+1].curAns+1 : 2);
		// printf("suff[%d] diff: %d ans: %d\n", i, suff[i].diff, suff[i].curAns);
	}
}

int main(){
	int tc,i,j,n;

	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		if(n == 2){
			printf("2\n");
			continue;
		}
		if(n == 3){
			printf("3\n");
			continue;
		}
		//find longest substring if we just don't change anything
		int ans = findLongestSubstring(n);
		genPref(n);
		genSuff(n);

		for(int i=1;i<n-1;i++){
			int selisih2 = a[i+1] - a[i-1];
			int bagi2 = selisih2 / 2;
			int temp = a[i];
			int aBaru = a[i-1] + bagi2;
			if((aBaru - a[i-1]) == (a[i+1] - aBaru)){
				int jawab = pref[i-1].curAns + 1 + suff[i+1].curAns;
				// printf("bs insert, jawab: %d\n", jawab);
				ans = max(ans, jawab);
			} else {
				ans = max(ans, pref[i-1].curAns + 1);
				ans = max(ans, suff[i+1].curAns + 1);
			}
			// printf("i: %d selisih2: %d bagi2: %d\n", i, selisih2, bagi2);
			// if((bagi2 == pref[i-1].diff || i-1 == 0) && (bagi2 == suff[i+1].diff || i+1 == n-1)) {
			// 	int jawab = pref[i-1].curAns + 1 + suff[i+1].curAns;
			// 	// printf("bs insert, jawab: %d\n", jawab);
			// 	ans = max(ans, jawab);
			// }
		}
		for(int i=2;i<n-2;i++){
			ans = max(ans, pref[i-1].curAns+1);
		}
		for(i=n-3;i>=0;i--){
			ans = max(ans, suff[i+1].curAns+1);
		}
		//test ujung
		ans = max(ans, suff[1].curAns+1);
		ans = max(ans, pref[n-2].curAns+1);
		ans = max(ans, 3);

		printf("%d\n",ans);
	}
	
	return 0;
};