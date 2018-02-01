#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
int dist[10010][10010];


void bfs(int awal){
	dist[awal][awal] = 0;
	queue<int> q;
	q.push(awal);
	while(!q.empty()){
		int front = q.front(); q.pop();
		for(int i=0;i<AdjList[front].size();i++){
			int v = AdjList[front][i];
			if(dist[awal][v]==0 && v!=awal){
				dist[awal][v] = 1+dist[awal][front]; q.push(v);
			}
		}
	}
}

int main() {
	int n,m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	AdjList.assign(n+1,vi());
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b); AdjList[a].pb(b); AdjList[b].pb(a);
	}
	/*for(i=0;i<10010;i++){
		for(j=0;j<10010;j++){
			dist[i][j] = inf;
		}
	}*/
	vi perumahan;
	int a;
	bfs(1);
	for(i=0;i<k;i++){scanf("%d",&a); perumahan.pb(a); bfs(a);}
	/*for(j=1;j<=n;j++){	
		printf("dist[%d][%d] = %d\n",1,j,dist[1][j]);
	}
	for(i=0;i<k;i++){
		int rumah = perumahan[i];
		for(j=1;j<=n;j++){
			
			printf("dist[%d][%d] = %d\n",rumah,j,dist[rumah][j]);
		}
	}*/
	sort(perumahan.begin(), perumahan.end());
	int ans = inf;
	do{
		int jarak = 0;
		jarak+=dist[1][perumahan[0]];
		for(i=1;i<perumahan.size();i++){
			int rumah = perumahan[i];
			//printf("rumah: %d\n",rumah);
			/*if(i==0){
				jarak+=dist[1][rumah];// printf("jarak jd: %d pertambahan dari dist[%d][%d] = %d\n",jarak,1,rumah,dist[1][rumah]);
			}else{*/
			int rumahSebelum = perumahan[i-1];
			jarak+=dist[rumahSebelum][rumah];
				//printf("jarak jd: %d pertambahan dari dist[%d][%d] = %d\n",jarak,rumahSebelum,rumah,dist[rumahSebelum][rumah]);
			//}
		}
		int rumahSebelum = perumahan[perumahan.size()-1];
		jarak+=dist[rumahSebelum][1];
		/*printf("jarak jd: %d pertambahan dari dist[%d][%d] = %d\n",jarak,rumahSebelum,1,dist[rumahSebelum][1]);
		printf("jarak: %d\n",jarak);*/
		ans = min(ans,jarak);
	}while(next_permutation(perumahan.begin(), perumahan.end()));
	printf("%d\n",ans);
	return 0;
}