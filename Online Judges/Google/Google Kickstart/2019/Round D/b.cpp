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

vector<vii> adj;

int main(){
	int tc,i,j,n,g,m;
	scanf("%d",&tc);
	int ans[100001];
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:",tt);
		scanf("%d %d %d",&n,&g,&m);
		for(i=0;i<g;i++){
			ans[i] = 0;
		}
		adj.assign(n+1, vii());
		for(i=0;i<g;i++){
			int idx;
			char kar;
			scanf("%d %c\n",&idx,&kar);
			idx--;
			adj[idx].pb(ii(0, i));
			// printf("guest: %d\n",	i);
			for(j=1;j<=m;j++){
				if(kar == 'A'){
					idx--;
					if(idx < 0){idx += n;}
				}else{
					idx++;
					if(idx >= n){idx -= n;}
				}
				// printf("idx: %d\n",idx);
				if(adj[idx].size()){
					ii belakang = adj[idx][0];
					if(belakang.first > j){continue;}
					else if(belakang.first == j){
						// printf("push %d %d\n",j,i);
						adj[idx].pb(ii(j, i));
					}else{
						adj[idx].clear();
						adj[idx].pb(ii(j,i));
						// printf("clear dan push %d %d\n",j,i);
					}
				}else{
					// printf("push baru %d %d\n",j,i);
					adj[idx].pb(ii(j,i));
				}
			}
		}
		for(i=0;i<n;i++){
			// printf("tempat %d\n",i);
			int maksWaktu = 0;
			for(j=0;j<adj[i].size();j++){
				ii pas = adj[i][j];
				maksWaktu = max(maksWaktu, pas.first);
			}
			for(j=0;j<adj[i].size();j++){
				ii pas = adj[i][j];
				if(pas.first == maksWaktu){
					// printf("pas %d %d\n",pas.first, pas.second);
					int idx = pas.second;
					ans[idx]++;	
				}
			}
		}
		for(i=0;i<g;i++){
			printf(" %d",ans[i]);
		}
		printf("\n");
	}
	return 0;
};