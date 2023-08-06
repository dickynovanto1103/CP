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

int hitJarak(int cur, int target, int n) {
	return (target - cur + n) % n;
}

int dish[200010];
int cnt[200010];

int main(){
	int n;
	while(scanf("%d", &n) != EOF) {

		for(int i=0;i<n;i++){
			scanf("%d",&dish[i]);
		}

		
		memset(cnt, 0, sizeof cnt);
		//assume dish i is in the area of people i, compute others
		for(int i=0;i<n;i++){
			//focus dish i
			// ada brp banyak langkah yg bs ditempuh supaya orang i bisa happy?
			int pos = dish[i];
			for(int j=-1;j<=1;j++){
				int target = (i - j + n) % n;
				int jarak = hitJarak(pos, target, n);
				cnt[jarak]++;
			}
		}

		int ans = 0;
		for(int i=0;i<n;i++){
			ans = max(ans, cnt[i]);
		}

		printf("%d\n", ans);
	}
	
	
	return 0;
};