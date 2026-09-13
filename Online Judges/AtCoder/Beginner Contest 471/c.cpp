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
	int n;
	while(scanf("%d",&n) != EOF) {
		set<int> s;
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			s.insert(a);
		}
		s.insert(0);
		auto it = s.find(0);
		auto it2 = s.find(0);
		int lastPos = 0;

		ll ans = 0;
		for(int i=0;i<n;i++){
			int jarakPrev = INT_MAX;
			int numPrev;
			// printf("i: %d\n", i);
			if(it != s.begin()) {
				it--;
				numPrev = *it;
				jarakPrev = min(jarakPrev, lastPos - numPrev);
				// printf("numPrev: %d jarakPrev: %d\n", numPrev, jarakPrev);
			}

			int jarakNext = INT_MAX;
			int numNext;
			if(++it2 != s.end()) {
				numNext = *it2;
				jarakNext = min(jarakNext, numNext - lastPos);
				// printf("numNext: %d jarakNext: %d\n", numNext, jarakNext);
			}

			
			int minJarak = min(jarakPrev, jarakNext);
			// printf("minJarak: %d\n", minJarak);
			if(minJarak == INT_MAX) {
				break;
			}else{
				ans += minJarak;
				// printf("ans become: %lld\n", ans);
				s.erase(lastPos);
				if(minJarak == jarakPrev) {
					lastPos = numPrev;
					// printf("assinging last pos with prev: %d\n", lastPos);
				}else{
					lastPos = numNext;
					// printf("assinging last pos with next: %d\n", lastPos);
				}
				it = s.find(lastPos);
				it2 = s.find(lastPos);
			}
		}

		printf("%lld\n", ans);
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