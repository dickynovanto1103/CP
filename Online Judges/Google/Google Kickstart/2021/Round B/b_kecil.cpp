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
		//find longest substring if we just don't change anything
		int ans = findLongestSubstring(n);
		for(i=1;i<n-1;i++){
			int selisih2 = a[i+1] - a[i-1];
			int bagi2 = selisih2 / 2;
			int tempA = a[i];
			a[i] = a[i-1] + bagi2;
			// printf("a[%d]: %d\n",i,a[i]);
			ans = max(ans, findLongestSubstring(n));
			// printf("i: %d ans jd: %d\n",i, ans);
			a[i] = tempA;
		}
		for(i=2;i<n-2;i++){
			int selisih = a[i-1] - a[i-2];
			int temp = a[i];
			a[i] = a[i-1] + selisih;
			ans = max(ans, findLongestSubstring(n));
			a[i] = temp;
		}

		for(i=n-3;i>=0;i--){
			int selisih = a[i+2] - a[i+1];
			int temp = a[i];
			a[i] = a[i+1] - selisih;
			ans = max(ans, findLongestSubstring(n));
			a[i] = temp;
		}
		// genPref(n);
		// genSuff(n);

		// for(int i=1;i<n-1;i++){
		// 	int selisih2 = a[i+1] - a[i-1];
		// 	if(selisih2 % 2 != 0){continue;}
		// 	int bagi2 = selisih2 / 2;
		// 	// printf("i: %d selisih2: %d bagi2: %d\n", i, selisih2, bagi2);
		// 	if((bagi2 == pref[i-1].diff || i-1 == 0) && (bagi2 == suff[i+1].diff || i+1 == n-1)) {
		// 		int jawab = pref[i-1].curAns + 1 + suff[i+1].curAns;
		// 		// printf("bs insert, jawab: %d\n", jawab);
		// 		ans = max(ans, jawab);
		// 	}
		// }
		//test ujung
		int selisihPertama = a[2] - a[1];
		int tempA = a[0];
		a[0] = a[1] - selisihPertama;
		ans = max(ans, findLongestSubstring(n));
		// printf("pertama ans jd: %d\n", ans);
		a[0] = tempA;

		int selisihAkhir = a[n-2] - a[n-3];
		tempA = a[n-1];
		a[n-1] = a[n-2] + selisihAkhir;
		ans = max(ans, findLongestSubstring(n));
		// printf("akhir ans jd: %d\n", ans);
		a[n-1] = tempA;
		ans = max(ans, 3);

		printf("%d\n",ans);
	}
	
	return 0;
};