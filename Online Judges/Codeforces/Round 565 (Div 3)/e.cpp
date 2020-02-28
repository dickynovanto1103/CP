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

vector<vi> AdjList;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n,m;
		scanf("%d %d",&n,&m);
		vi dist(n+1);
		AdjList.assign(n+1,vi());
		for(i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			AdjList[a].pb(b); AdjList[b].pb(a);
		}
		for(i=1;i<=n;i++){
			dist[i] = inf;
		}
		dist[1] = 0;
		queue<int> q;
		q.push(1);
		while(!q.empty()){
			int front = q.front(); q.pop();
			for(i=0;i<AdjList[front].size();i++){
				int v = AdjList[front][i];
				if(dist[v] == inf){
					dist[v] = dist[front] + 1;
					q.push(v);
				}
			}
		}
		int cnt[2] = {0};
		for(i=1;i<=n;i++){
			cnt[dist[i]%2]++;
		}
		vi ans;
		for(i=0;i<2;i++){
			if(cnt[i] <= n/2){
				for(j=1;j<=n;j++){
					if(dist[j]%2 == i){
						ans.pb(j);
					}
				}
				break;
			}
		}
		printf("%d\n",(int)ans.size());
		for(i=0;i<ans.size();i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
};