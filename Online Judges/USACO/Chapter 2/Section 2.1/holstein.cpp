/*
ID: dickyno1
LANG: C++14
TASK: holstein
*/

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

int need[26];
bool isFulfilled(vi v) {
	for(int i=0;i<v.size();i++){
		if(v[i] < need[i]){
			return false;
		}
	}

	return true;
}

int main(){
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);

	int n,i,j;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&need[i]);
	}

	int g;
	scanf("%d",&g);
	int feeds[16][30];
	for(i=0;i<g;i++){
		for(j=0;j<n;j++){
			scanf("%d",&feeds[i][j]);
		}
	}

	vi ans;

	int minim = inf;
	for(i=0;i<(1<<g);i++){
		int cnt = 0;
		vi v(n);
		for(j=0;j<g;j++){
			if((1<<j) & i) {
				cnt++;
				for(int k=0;k<n;k++){
					v[k] += feeds[j][k];	
				}
			}
		}

		if(isFulfilled(v)){
			if(minim > cnt) {
				minim = cnt;
				ans.clear();
				for(j=0;j<g;j++){
					if((1<<j) & i) {
						ans.pb(j);
					}
				}
			}
		}
	}

	printf("%d", minim);
	for(i=0;i<minim;i++){
		printf(" %d",ans[i] + 1);
	}
	puts("");

	
	return 0;
};