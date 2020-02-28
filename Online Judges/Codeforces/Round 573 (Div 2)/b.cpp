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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct pas {
	int bil;
	char kar;
};

vector<vi> adj;

int main(){
	string s[4];
	int i,j;
	pas a[4];
	adj.assign(34,vi());
	set<string> st;
	map<char,int> mapper;
	mapper['m'] = 0; mapper['s'] = 1; mapper['p'] = 2;
	for(i=0;i<3;i++){
		cin>>s[i];
		st.insert(s[i]);
		a[i].bil = s[i][0] - '0';
		a[i].kar = s[i][1];
		adj[mapper[a[i].kar]].pb(a[i].bil);
	}
	int ans = inf;
	if(st.size() == 1){
		ans = 0;
	}else if(st.size() == 2){
		ans = 1;
	}else{
		ans = 2;
	}
	int maks = 0;
	for(i=0;i<3;i++){
		sort(adj[i].begin(), adj[i].end());
		int cur = -inf;
		bool vis[11];
		memset(vis, false, sizeof vis);
		
		
		for(j=0;j<adj[i].size();j++){
			int bil = adj[i][j];
			vis[bil] = true;
		}
		for(j=0;j<8;j++){
			int cnt = 0;
			for(int k=j;k<j+3;k++){
				if(vis[k]){cnt++;}
			}
			int sisa = 3-cnt;
			ans = min(ans, sisa);
		}
	}
	// ans = min(ans, 3-maks);
	printf("%d\n",ans);

	return 0;
};