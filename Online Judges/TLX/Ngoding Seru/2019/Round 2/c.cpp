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

vector<vi> AdjList;

const int maxn = 5e4 + 5;

int dist[2002][2002];

void hitungJarak(int n) {
	queue<int> q;
	int i,j;
	for(i=1;i<=n;i++){
		dist[i][i] = 0;
		q.push(i);
		while(!q.empty()){
			int front = q.front(); q.pop();
			for(j=0;j<AdjList[front].size();j++){
				int v = AdjList[front][j];
				if(dist[i][v] == inf){
					dist[i][v] = dist[i][front] + 1;
					q.push(v);
				}
			}
		}
	}
}

int main(){
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	AdjList.assign(maxn, vi());
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			dist[i][j] = inf;
		}
	}
	for(i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b);
		AdjList[b].pb(a);
	}

	hitungJarak(n);

	int status[maxn];

	for(i=1;i<=n;i++){
		scanf("%d",&status[i]);
	}

	int ans = 0;

	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(status[i] && status[j]){
				ans += dist[i][j];
				// printf("ans ditambah dist[%d][%d]: %d jd: %d\n",i,j,dist[i][j], ans);
			}
		}
	}

	

	while(q--){
		int com;
		scanf("%d",&com);
		if(com == 1){
			printf("%d\n",ans);
		}else{
			int idx;
			scanf("%d",&idx);
			status[idx] = 1 - status[idx];

			if(status[idx]){
				for(i=1;i<=n;i++){
					if(i == idx){continue;}
					if(status[i]){
						ans += dist[idx][i];
					}
				}
			}else{
				for(i=1;i<=n;i++){
					if(i == idx){continue;}
					if(status[i]){
						ans -= dist[idx][i];
					}
				}
			}
		}
	}
	return 0;
};