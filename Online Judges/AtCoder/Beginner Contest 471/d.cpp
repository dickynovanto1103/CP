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
	int q,maxCap;
	while(scanf("%d%d",&q,&maxCap) != EOF) {
		multiset<int> s;
		while(q--){
			int type;
			scanf("%d",&type);
			if(type == 1) {
				int time, w;
				scanf("%d%d",&time,&w);

				s.insert(w - time);
			}else{
				int time;
				scanf("%d",&time);

				if(s.empty()){
					puts("-1");
					continue;
				}

				int temp = *(--s.end());
				printf("%d\n", min(temp + time, maxCap));
				auto it = s.find(temp);
				s.erase(it);
			}
		}
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