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
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

int p[800001], h[800001];
int dp[2400001][2]

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		vector<viii> adj;

		printf("Case #%d: ",tt);
		scanf("%d",&n);
		adj.assign(3*n+1, viii());
		set<int> s;
		set<int>::iterator it;
		for(i=0;i<n;i++){
			scanf("%d %d",&p[i],&h[i]);
			s.insert(p[i] - h[i]);
			s.insert(p[i]);
			s.insert(p[i] + h[i]);
		}
		map<int,int> mapper;
		int idx = 0;
		vi nodes;
		for(it=s.begin();it!=s.end();it++){
			mapper[*it] = idx++;
			nodes.pb(*it);
		}

		for(i=0;i<n;i++){
			int idx1 = mapper[p[i] - h[i]];
			int idx2 = mapper[p[i]];
			int idx3 = mapper[p[i] + h[i]];

			adj[idx1].pb(iii(ii(idx2, h[i]), i));
			adj[idx2].pb(iii(ii(idx1, h[i]), i));

			adj[idx2].pb(iii(ii(idx3, h[i]), i));
			adj[idx3].pb(iii(ii(idx2, h[i]), i));
		}
		
		int len = nodes.size();

		for(i=0;i<len;i++){

		}

	}
	
	return 0;
};