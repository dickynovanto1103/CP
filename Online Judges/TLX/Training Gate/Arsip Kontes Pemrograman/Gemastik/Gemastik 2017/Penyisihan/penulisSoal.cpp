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

const int maxn = 200;
vector<vi> AdjList;

int s,t,f,mf;
vi p;
int res[2*maxn][2*maxn];

void augment(int v, int minEdge) {
	if(v==s){f = minEdge; return;}
	else if(p[v]!=-1) {
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v]-=f; res[v][p[v]]+=f;
	}
}

int main(){
	int n,i,j,tc;
	int banyakSoal[maxn];
	scanf("%d",&tc);
	s = 0; t = 150;
	while(tc--){
		AdjList.assign(2*maxn,vi());
		scanf("%d",&n);
		for(i=1;i<=n;i++){scanf("%d",&banyakSoal[i]); banyakSoal[i]--;}// sudah ditag 1 soal buat atas nama penulis

		for(i=1;i<=n;i++) {
			//connecting source to each pekerja
			AdjList[s].pb(i);
			AdjList[i].pb(s);
			res[s][i] = banyakSoal[i];
			//res[i][s] = banyakSoal[i];
			int banyak;
			int perusahaan[maxn];
			scanf("%d",&banyak);
			for(j=0;j<banyak;j++){
				scanf("%d",&perusahaan[j]);
				perusahaan[j]+=50;
				AdjList[i].pb(perusahaan[j]);// connecting pekerja to perusahaan
				AdjList[perusahaan[j]].pb(i);// connecting pekerja to perusahaan
				res[i][perusahaan[j]] = 1;
				//res[perusahaan[j]][i] = 1;
				AdjList[perusahaan[j]].pb(t); //connecting to sink
				AdjList[t].pb(perusahaan[j]); //connecting to sink
				res[perusahaan[j]][t] = 1;
				//res[t][perusahaan[j]] = 1;
			}
			
		}
		mf = 0;
		while(1) {
			f = 0;
			bitset<2*maxn> vis; vis[s] = true;
			queue<int> q; q.push(s);
			p.assign(2*maxn,-1);
			while(!q.empty()) {
				int u = q.front(); q.pop();
				if(u==t) break;
				for(j=0;j<AdjList[u].size();j++) {
					int v = AdjList[u][j];
					if(res[u][v]>0 && !vis[v]) {
						vis[v] = true; q.push(v); p[v] = u;
					}
				}
			}
			augment(t,inf);
			if(f==0){break;}//no more flow
			mf+=f;
		}
		printf("%d\n",mf + n);
		AdjList.clear();
	}
	
	return 0;
};