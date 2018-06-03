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

const int maxn = 50;
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

int total = 0;

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
	string kata;
	int i;
	s = 0; t = 37;
	f = 0; mf = 0;
	total = 0;
	int cnt = 0;
	while(true) {
		if(!getline(cin,kata)) {
			maxflow();
			// printf("mf: %d total: %d\n",mf,total);
			if(mf==total){
				for(i=27;i<37;i++){
					bool isAllocated = false;
					for(int j=1;j<=26;j++){
						if(res[i][j]){
							printf("%c",j-1+'A');
							isAllocated = true;
							break;
						}
					}
					if(!isAllocated){
						printf("_");
					}
				}
				printf("\n");
			}else{
				printf("!\n");
			}

			p.clear(); AdjList.clear();
			cnt = 0;
			break;
		}
		if(kata == "") {
			maxflow();
			// printf("mf: %d total: %d\n",mf,total);
			if(mf==total){
				for(i=27;i<37;i++){
					bool isAllocated = false;
					for(int j=1;j<=26;j++){
						if(res[i][j]){
							printf("%c",j-1+'A');
							isAllocated = true;
							break;
						}
					}
					if(!isAllocated){
						printf("_");
					}
				}
				printf("\n");
			}else{
				printf("!\n");
			}

			p.clear(); AdjList.clear();
			cnt = 0;
		}else{
			if(cnt==0){
				total = 0;
				AdjList.assign(maxn, vi());
				memset(res,0,sizeof res);
				s = 0; t = 37;
				for(i=27;i<=36;i++){
					AdjList[i].pb(t); res[i][t] = 1; AdjList[t].pb(i);
				}
				cnt++;
			}
			stringstream ss(kata);
			string kata1, kata2;
			ss>>kata1>>kata2;
			
			char app = kata1[0];
			int idxApp = app-'A' + 1;
			int banyakPengguna = kata1[1] - '0';
			total+=banyakPengguna;
			
			AdjList[s].pb(idxApp); res[s][idxApp] = banyakPengguna;
			AdjList[idxApp].pb(s);
			
			
			for(i=0;i<(kata2.length()-1);i++) {
				int idxKomputer = kata2[i] - '0' + 27;
				AdjList[idxApp].pb(idxKomputer); res[idxApp][idxKomputer] = 1;
				AdjList[idxKomputer].pb(idxApp);
			}
			
		}
	}
	return 0;
};