#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef vector <int> vi;

vector <vi> AdjList;
vi dist;
int main(){
	int tc,n,i,j,cnt,bil,a,awal,akhir;
	queue <int> q;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		AdjList.assign(n,vi());
		for(i=0;i<n;i++){
			scanf("%d %d",&bil,&cnt);
			for(j=0;j<cnt;j++){
				scanf("%d",&a); AdjList[bil].push_back(a); AdjList[a].push_back(bil);
			}
		}
		scanf("%d %d",&awal,&akhir);
		dist.assign(n,inf);
		dist[awal] = 0; q.push(awal);
		while(!q.empty()){
			int front = q.front(); q.pop();
			for(i=0;i<AdjList[front].size();i++){
				int node  = AdjList[front][i];
				if(dist[node]==inf){
					dist[node]=dist[front] + 1;
					q.push(node);
				}
			}
		}
		printf("%d %d %d\n",awal,akhir,dist[akhir]-1);
		AdjList.clear();
		if(tc){printf("\n");}
	}
	return 0;
}