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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> adj;

int nxt[100001][27];

int main(){
	string a,b;
	cin>>a>>b;
	int i,j;
	adj.assign(27, vi());
	int pjgA = a.length(), pjgB = b.length();
	for(i=0;i<pjgA;i++){
		adj[a[i] - 'a'].pb(i);
	}
	memset(nxt, -1, sizeof nxt);
	//precompute next
	for(i=0;i<pjgA;i++){
		for(j=0;j<26;j++){
			int idx = lower_bound(adj[j].begin(), adj[j].end(), i+1) - adj[j].begin();
			if(idx == adj[j].size()){
				continue;
			}
			nxt[i][j] = adj[j][idx];
		}
	}
	ll ans = 0;
	int first, last, prev = -1;
	for(i=0;i<pjgA;i++){
		if(a[i] != b[0]){continue;}
		int idx = i;
		bool valid = true;
		// printf("i: %d\n",i);
		for(j=1;j<pjgB;j++){
			// printf("cari %c\n",b[j]);
			int next = nxt[idx][b[j] - 'a'];
			if(next == -1){valid = false; break;}
			idx = next;
			// printf("next: %d idx: %d\n",next, idx);
		}
		
		if(valid){
			ans += (ll)(i - prev)*(ll)(pjgA - idx);
			prev = i;
		}
	}
	// printf("first: %d last: %d\n",first, last);
	// printf("%d*%d\n",pjgA-last, first+1);
	// ans = (ll)(pjgA - last)*(ll)(first+1);
	printf("%lld\n",ans);
	return 0;
};