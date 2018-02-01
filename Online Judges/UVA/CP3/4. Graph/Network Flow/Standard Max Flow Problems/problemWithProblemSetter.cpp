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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;


int s,t,f,mf;
vi p;
const int maxn = 1023;
int res[maxn][maxn];
vector<vi> AdjList;

void augment(int v, int minEdge){
	if(v==s){f = minEdge; return;}
	else if(p[v]!=-1){
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v]-=f; res[v][p[v]]+=f;
	}
}

int main(){
	int nCategory, nProblem, i,j;
	while(scanf("%d %d",&nCategory,&nProblem),(nCategory | nProblem)){
		AdjList.assign(maxn,vi());
		int banyak = nCategory+nProblem+2;
		//inisialisasi versi irit
		for(i=0;i<=banyak;i++){
			for(j=0;j<=banyak;j++){
				res[i][j] = 0;
			}
		}
		
		s = 0; t = nCategory+nProblem+1;
		//edge dari source ke nProblem
		for(i=1;i<=nProblem;i++){
			AdjList[s].pb(i); AdjList[i].pb(s);
			res[s][i]=1;
			//res[i][s]=1;
		}
		//edge ke sink
		int total = 0;
		for(i=1;i<=nCategory;i++){
			int bil;
			scanf("%d",&bil);
			total+=bil;
			AdjList[nProblem+i].pb(t); AdjList[t].pb(nProblem+i);
			res[nProblem+i][t]= bil;
			//res[t][nProblem+i]= bil;
		}
		//tengah-tengah
		for(i=1;i<=nProblem;i++){
			scanf("%d",&banyak);
			for(j=0;j<banyak;j++){
				int v;
				scanf("%d",&v);//nomor kategori
				v+=nProblem;
				AdjList[i].pb(v); AdjList[v].pb(i);
				res[i][v] = 1;
				//res[v][i] = 1;
			}
		}
		// for(i=0;i<=nProblem+nCategory+1;i++){
		// 	printf("node %d:",i);
		// 	for(j=0;j<AdjList[i].size();j++){
		// 		printf(" %d",AdjList[i][j]);
		// 	}
		// 	printf("\n");
		// }
		//compute maxflow
		mf = 0;
		while(1){
			f = 0;
			bitset<maxn> vis; vis[s] = true;
			queue<int> q; q.push(s);
			p.assign(maxn,-1);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u==t){break;}
				for(j=0;j<AdjList[u].size();j++){
					int v = AdjList[u][j];
					if(res[u][v]>0 && !vis[v]){
						vis[v] = true; q.push(v); p[v] = u;
					}
				}
			}
			augment(t,inf);
			if(f==0){break;}
			mf+=f;
		}
		//printf("mf: %d\n",mf);
		if(mf==total){
			printf("1\n");
			//traversal graph
			for(i=1;i<=nCategory;i++){
				int cnt = 0;
				int node = nProblem+i;
				
				for(j=0;j<AdjList[node].size();j++){
					int v = AdjList[node][j];
					if(res[v][node]==0){
						if(cnt){printf(" ");}
						printf("%d",v);
						cnt++;
					}
				}
				printf("\n");
				
			}
		}else{
			printf("0\n");
		}
		AdjList.clear();
	}

	return 0;
};