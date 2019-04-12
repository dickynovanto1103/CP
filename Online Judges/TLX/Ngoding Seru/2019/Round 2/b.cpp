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

const int maxn = 1511;
int res[maxn][maxn], f,mf, s,t;
vi p;
 
vector<vi> AdjList;

void augment(int node, int minEdge) {
	if(node == s){f = minEdge; return;}
	else if(p[node] != -1){
		augment(p[node], min(minEdge, res[p[node]][node]));
		res[p[node]][node] -= f; res[node][p[node]] += f;
	}
}

void maxflow() {
	mf = 0;
	while(true) {
		f = 0;
		p.assign(maxn,-1);
		int i;
		
		bitset<maxn> isVisited; isVisited[s] = true; p[s] = -1;
		queue<int> q; q.push(s);
		while(!q.empty()) {
			int front = q.front(); q.pop();
			if(front == t){break;}
			for(i=0;i<AdjList[front].size();i++){
				int v = AdjList[front][i];
				if(res[front][v] > 0 && !isVisited[v]) {
					isVisited[v] = true; q.push(v); p[v] = front;
				}
			}
		}
		augment(t, inf);
		p.clear();
		if(f==0){break;}
		mf+=f;
	}
}

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	AdjList.assign(maxn, vi());

	s = 0; t = maxn-1;
	for(i=1;i<=n;i++){
		AdjList[s].pb(i);
		res[s][i] = 1;
	}	
	int nomorTim = n+1;
	int nomorLomba = 1002;
	for(i=1;i<=k;i++){
		int tim;
		scanf("%d",&tim);
		for(j=1;j<=tim;j++){
			for(int m=0;m<3;m++){
				int peserta;
				scanf("%d",&peserta);
				
				AdjList[peserta].pb(nomorTim);
				AdjList[nomorTim].pb(peserta);

				res[peserta][nomorTim]++;

				AdjList[nomorTim].pb(nomorLomba);
				AdjList[nomorLomba].pb(nomorTim);

				// printf("peserta: %d nomorTim: %d nomorLomba: %d\n",peserta, nomorTim, nomorLomba);
			}
			res[nomorTim][nomorLomba]++;
			nomorTim++;
		}
		
		AdjList[nomorLomba].pb(t);
		res[nomorLomba][t] = tim;
		nomorLomba++;
	}

	maxflow();
	printf("%d\n",mf);



	return 0;
};