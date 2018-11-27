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

const int maxn = 31;

bool on[maxn][maxn];
int res[70][70];

vector<vi> AdjList;
int s,t,f,mf;
int n;
vi p;

void augment(int node, int minEdge){
	if(node == s){f = minEdge; return;}
	else{
		if(p[node]!=-1){augment(p[node], min(minEdge, res[p[node]][node]));}
		res[p[node]][node] -= f; res[node][p[node]] += f;
	}
}

bool valid(int mid){
	int i,j;
	//run maxflow
	mf = 0;
	while(1){
		f = 0;
		bitset<70> vis; vis[s] = true;
		p.assign(70, -1);
		queue<int> q; q.push(s);

		while(!q.empty()){
			int front = q.front(); q.pop();
			if(front == t){break;}
			for(i=0;i<AdjList[front].size();i++){
				int v = AdjList[front][i];
				if(!vis[v] && res[front][v] > 0){
					q.push(v);
					vis[v] = true;
					p[v] = front;
				}
			}
		}
		augment(t,inf);
		if(f == 0){break;}
		mf += f;
		p.clear();
	}
	if(mf == n){return true;}
	else{return false;}
}

int main(){
	int i,j;
	scanf("%d",&n);
	int a[maxn][maxn];

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int kiri = 1, kanan = 1000000, mid, ans;
	s = 0; t = 65;
	
	while(kiri <= kanan){
		mid = (kiri+kanan)/2;
		memset(res, 0, sizeof res);
		AdjList.assign(70, vi());
		for(i=1;i<=n;i++){
			AdjList[s].pb(i);
			res[s][i] = 1;
		}

		for(i=n+1;i<=(2*n);i++){
			AdjList[i].pb(t);
			res[i][t] = 1;
		}

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				int indeksBaris = i+1;
				int indeksKolom = n + j + 1;
				if(a[i][j] >= mid){
					AdjList[indeksBaris].pb(indeksKolom);
					AdjList[indeksKolom].pb(indeksBaris);
					res[indeksBaris][indeksKolom] = 1; 
					// printf("dipush i: %d j: %d -> %d ke %d\n",i,j, indeksBaris, indeksKolom); 
				}
			}
		}

		if(valid(mid)){
			ans = mid;
			kiri = mid+1;
		}else{
			kanan = mid-1;
		}
		AdjList.clear();
	}
	printf("%d\n",ans);
	return 0;
};