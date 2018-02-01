#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
vi listImportant;
int dist[10010];
int counter[10010];

int bfs(int u){
	queue<int> q; q.push(u);
	dist[u] = 0;
	while(!q.empty()){
		int front = q.front(); q.pop();
		for(int i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			if(dist[v]==inf){
				dist[v] = dist[front] + 1;
				q.push(v);
			}
		}
	}
	int sum = 0;
	for(int i=0;i<listImportant.size();i++){
		int node = listImportant[i];
		//printf("jarak dari %d ke %d adalah: %d\n",u,node,dist[node]);
		sum+=dist[node];
	}
	return sum;
}

int main(){
	int n,line;
	int a[10010],i,j;
	int tc;
	scanf("%d",&tc);
	int test = 1;
	while(tc--){
		printf("Krochanska is in: ");
		//printf("test: %d\n",test++);
		scanf("%d %d",&n,&line);
		AdjList.assign(n+1,vi());
		memset(counter,0,sizeof counter);
		while(line--){
			int cnt = 0;
			while(scanf("%d",&a[cnt]),a[cnt]){
				counter[a[cnt]]++;
				cnt++;
			}
			for(i=0;i<cnt-1;i++){
				int bil1 = a[i], bil2 = a[i+1];
				AdjList[bil1].pb(bil2); AdjList[bil2].pb(bil1);
			}
			
		}
		for(i=1;i<=n;i++){
			if(counter[i]>1){listImportant.pb(i);}
		}
		
		int ans = inf, noKota;
		for(i=0;i<listImportant.size();i++){
			fill(dist,dist+n+1,inf);
			int jawab = bfs(listImportant[i]);
			//printf("stasiun penting: %d jawab: %d\n",listImportant[i],jawab);
			if(jawab<ans){
				ans = jawab; noKota = listImportant[i];
			}else if(jawab==ans){
				if(listImportant[i] < noKota){
					noKota = listImportant[i];
				}
			}
			//printf("no kota jadi: %d\n\n",noKota);
		}
		printf("%d\n",noKota);
		listImportant.clear();

		AdjList.clear();
	}
	return 0;
};