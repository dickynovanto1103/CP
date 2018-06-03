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

const int maxn = 405;
int n,m,s,t,mf,f;
int res[maxn][maxn];
vector<vi> AdjList;
vi p;

void augment(int node, int minEdge) {
	if(node == s){f = minEdge; return;}
	else if(p[node] != -1){
		augment(p[node], min(minEdge, res[p[node]][node]));
		res[p[node]][node] -= f; res[node][p[node]] += f;
	}
}

void maxflow() {
	mf = 0;
	int i,j;
	while(true) {
		f = 0;
		p.assign(maxn, -1);
		queue<int> q; q.push(s); 
		bitset<maxn> isVisited; isVisited[s] = true; p[s] = -1;
		while(!q.empty()) {
			int front = q.front(); q.pop();
			if(front==t){break;}
			for(i=0;i<AdjList[front].size();i++) {
				int v = AdjList[front][i];
				if(res[front][v] > 0 && !isVisited[v]) {
					q.push(v); isVisited[v] = true; p[v] = front;
				}
			}
		}
		augment(t, inf);
		// printf("f: %d\n",f);
		if(f == 0){break;}
		mf+=f;
	}
}

int toBil(int row, int col) {
	return row*m + col+1;
}

bool isValid(int row, int col) {
	return row>=0 && row<n && col>=0 && col < m;
}

int main(){
	s = 0; t = 401;
	int i,j;
	scanf("%d %d\n",&n,&m);
	char mat[21][21];
	AdjList.assign(maxn, vi());
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++){
			scanf("%c ",&mat[i][j]);
		}
	}
	// n = 20, m = 20;
	// printf("toBil: %d\n",toBil(18,19));
	
	int dx[] = {-1,0,1,0};
	int dy[] = {0,1,0,-1};
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++){
			char kar = mat[i][j];

			for(int k=0;k<4;k++){
				int xbaru = i + dx[k], ybaru = j + dy[k];
				if(isValid(xbaru,ybaru)) {
					char karBaru = mat[xbaru][ybaru];
					int idxLama = toBil(i,j);
					int idxBaru = toBil(xbaru,ybaru);
					// printf("i: %d j: %d xbaru: %d ybaru: %d idxLama: %d idxBaru: %d\n", i,j,xbaru,ybaru,idxLama, idxBaru);
					if(kar=='a'){
						if(karBaru=='b'){
							AdjList[idxLama].pb(idxBaru); 
							AdjList[idxBaru].pb(idxLama);
							res[idxLama][idxBaru] = 1;
						}
						AdjList[s].pb(idxLama);
						AdjList[idxLama].pb(s);
						res[s][idxLama] = 1;
					}else if(kar=='b') {
						if(karBaru == 'c') {
							AdjList[idxLama].pb(idxBaru); 
							AdjList[idxBaru].pb(idxLama);
							res[idxLama][idxBaru] = 1;
						}
					}else if(kar=='c') {
						if(karBaru == 'd') {
							AdjList[idxLama].pb(idxBaru); 
							AdjList[idxBaru].pb(idxLama);
							res[idxLama][idxBaru] = 1;
						}
					}else{
						AdjList[idxLama].pb(t);
						AdjList[t].pb(idxLama);
						res[idxLama][t] = 1;
					}
				}
			}

		}
		
	}
	// for(i=0;i<=401;i++){
	// 	for(j=0;j<=401;j++){
	// 		// if(j){printf(" ");}
	// 		if(res[i][j]){
	// 			printf("res[%d][%d]: %d\n",i,j,res[i][j]);
	// 		}
	// 		// printf("%d",res[i][j]);
	// 	}
	// 	// printf("\n");
	// }

	maxflow();
	printf("%d\n",mf);
	return 0;
}; 