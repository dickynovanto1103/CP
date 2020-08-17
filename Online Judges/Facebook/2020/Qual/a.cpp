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
typedef vector<ii> vii;

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:\n",tt);
		scanf("%d",&n);
		string in, out;
		vector<vi> adj;
		adj.assign(n+1, vi());

		cin>>in>>out;
		for(i=0;i<(n-1);i++){
			if(out[i] == 'Y' && in[i+1] == 'Y'){
				adj[i].pb(i+1);
			}
			if(in[i] == 'Y' && out[i+1] == 'Y'){
				adj[i+1].pb(i);
			}
		}

		bool vis[51][51];
		memset(vis, false, sizeof vis);
		for(i=0;i<n;i++){
			queue<int> q;
			q.push(i);
			vis[i][i] = true;
			while(!q.empty()){
				int front = q.front(); q.pop();
				for(j=0;j<adj[front].size();j++){
					int v = adj[front][j];
					if(vis[i][v]){
						continue;
					}
					vis[i][v] = true;
					q.push(v);
				}
			}
		}

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(vis[i][j]){printf("Y");}
				else{printf("N");}
			}
			printf("\n");
		}
	}
	
	return 0;
};