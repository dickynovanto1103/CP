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

const int maxn = 1e5 + 5;

vector<vi> adj(maxn);

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	int pref[maxn];
	int next[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i == 0){pref[i] = -1; next[i] = i+1;}
		else if(i == n-1){next[i] = -1; pref[i] = i-1;}
		else{
			next[i] = i+1;
			pref[i] = i-1;
		}
		adj[a[i]].pb(i);
	}
	
	int tot = 0;
	for(i=1;i<=10000;i++){
		for(j=0;j<adj[i].size();j++){
			int idx = adj[i][j];
			int minim = inf;
			if(pref[idx] != -1) {
				minim = min(minim, a[pref[idx]]);
			}
			if(next[idx] != -1) {
				minim = min(minim, a[next[idx]]);
			}

			if(minim != inf){
				tot += minim;
				// printf("idx: %d minim: %d tot: %d\n", idx, minim, tot);
			}

			next[pref[idx]] = next[idx];
			pref[next[idx]] = pref[idx];
		}
	}
	printf("%d\n", tot);

	return 0;
};