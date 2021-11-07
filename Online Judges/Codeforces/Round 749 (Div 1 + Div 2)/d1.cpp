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

int ask(vi v) {
	printf("?");
	for(int x: v){
		printf(" %d", x);
	}
	puts("");
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	vi next(n+1);
	fill(next.begin(), next.end(), -1);
	for(i=1;i<=n;i++){
		vi v;
		//find next[idx] value such that p[next[idx]] = p[idx] + 1
		//first query with all 1 except 1 num of 2...this is to find the next[idx] in the left side of idx;
		for(j=1;j<=n;j++){
			i == j ? v.pb(2): v.pb(1);
		}

		int ans = ask(v);
		if(ans == 0 || ans == i) {
			//it's inconclusive
		}else{
			next[i] = ans;
		}
	}

	//then query with all 2 except 1 num of 1...to find the next[idx] in the right side of idx
	for(i=1;i<=n;i++){
		vi v;
		for(j=1;j<=n;j++){
			i == j ? v.pb(1): v.pb(2);
		}

		int ans = ask(v);
		if(ans == 0 || ans == i) {

		}else{
			next[ans] = i;
		}
	}
	
	vi indegree(n+1);
	for(i=1;i<=n;i++){
		int ne = next[i];
		if(ne == -1){continue;}
		indegree[ne]++;
	}
	vi ans(n+1);
	int idx1 = 0;
	for(i=1;i<=n;i++){
		if(indegree[i] == 0) {
			idx1 = i;
			ans[i] = 1;
		}
	}

	assert(idx1 != 0);	
	for(i=2;i<=n;i++){
		int ne = next[idx1];
		assert(ne > 0);
		ans[ne] = i;
		idx1 = ne;
	}

	printf("!");
	for(i=1;i<=n;i++){
		printf(" %d", ans[i]);
	}
	puts("");
	fflush(stdout);
	return 0;
};