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
vector<vi> AdjList;

const int maxn = 102;

int res[maxn][maxn];
unordered_map<string,int> mapper;

void augment(int v, int minEdge){
	if(v==s){f = minEdge; return;}
	else if(p[v]!=-1){
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v]-=f; res[v][p[v]]+=f;
	}
}

int main(){
	int n,m,i,j,tc;
	s=0;
	mapper["XXL"] = 1;
	mapper["XL"] = 2;
	mapper["L"] = 3;
	mapper["M"] = 4;
	mapper["S"] = 5;
	mapper["XS"] = 6;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);

		memset(res,0,sizeof res);
		AdjList.assign(maxn,vi());
		//source dengan awal
		for(i=1;i<=6;i++){
			AdjList[0].pb(i); AdjList[i].pb(0);
			res[0][i]+=(n/6); res[i][0]+=(n/6);
		}
		int node = i;
		int awalPenerima = i;
		//bikin edge antara
		for(i=0;i<m;i++){
			string kata1,kata2;
			cin>>kata1>>kata2;
			// printf("kata1: "); cout<<kata1<<" "; printf("kata2: "); cout<<kata2<<endl;
			// printf("node: %d\n",node);
			int a = mapper[kata1];
			int b = mapper[kata2];
			AdjList[a].pb(node); AdjList[node].pb(a);
			res[a][node] = 1; res[node][a] = 1;
			AdjList[b].pb(node); AdjList[node].pb(b);
			res[b][node] = 1; res[node][b] = 1;
			node++;
		}
		t = node;
		//bikin connection to sink
		for(i=awalPenerima;i<(awalPenerima+m);i++){
			//printf("i: %d\n",i);
			AdjList[i].pb(t); AdjList[t].pb(i);
			res[i][t]+=1; res[t][i]+=1;
		}
		// printf("AdjList:\n");
		// for(i=0;i<=node;i++){
		// 	printf("node %d:",i);
		// 	for(j=0;j<AdjList[i].size();j++){
		// 		printf(" %d",AdjList[i][j]);
		// 	}
		// 	printf("\n");
		// }
		//hitung flow
		mf = 0;
		while(1){
			f=0;
			bitset<maxn> vis; vis[s] = true;
			queue<int> q; q.push(s);
			p.assign(maxn,-1);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u==t){break;}
				for(j=0;j<AdjList[u].size();j++){
					int v = AdjList[u][j];
					if(res[u][v]>0 && !vis[v]){
						vis[v] = true; p[v] = u; q.push(v);
					}
				}
			}
			augment(t,inf);
			if(f==0){break;}
			mf+=f;
		}
		//printf("mf: %d\n",mf);
		//cek apakah dari masing-masing pasangan..yg ke sink..ada ga yang 0 nilainya
		
		if(mf==m){printf("YES\n");}
		else{printf("NO\n");}
		//mapper.clear();
		AdjList.clear();
	}
	
	return 0;
};