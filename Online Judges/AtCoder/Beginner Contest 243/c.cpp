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
typedef pair<int,char> ic;
typedef vector<ic> vic;

ii koor[200010];
map<int, vic> mapper;
map<int, vic>::iterator it;

int main(){
	int n,i,j;
	while(scanf("%d",&n) != EOF) {
		mapper.clear();
		string s;
		for(i=0;i<n;i++){
			scanf("%d %d",&koor[i].first, &koor[i].second);
		}
		cin>>s;
		for(i=0;i<n;i++){
			mapper[koor[i].second].pb(ii(koor[i].first, s[i]));
		}

		bool tabrakan = false;
		for(it=mapper.begin();it!=mapper.end();it++) {
			vic sorted = it->second;
			sort(sorted.begin(), sorted.end());
			// printf("key: %d\n", it->first);
			int idxR = inf, idxL = -1;
			for(int i=0;i<sorted.size();i++) {
				ic pas = sorted[i];
				// printf("(%d, %c) ", pas.first, pas.second);
				if(pas.second == 'R' && idxR == inf) {
					idxR = i;
				}
				if(pas.second == 'L') {
					idxL = i;
				}
			}
			if(idxR < idxL) {
				tabrakan = true;
				break;
			}
			// puts("");
		}
		tabrakan ? puts("Yes") : puts("No");
	}

		
	
	return 0;
};