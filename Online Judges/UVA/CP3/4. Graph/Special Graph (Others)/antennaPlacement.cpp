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

const int maxn = 45;

vector<vi> AdjList;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n,m;
int idx[maxn][maxn];
vi match, vis;

int Aug(int node) {
	if(vis[node]) {return 0;}//sudah dikunjungi sebelumnya
	vis[node] = 1;
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(match[v] == -1 || Aug(match[v])) {
			match[v] = node; return 1;
		}
	}
	return 0; //no matching
}

int augmentedAlgo(int banyakNodeKiri) {
	match.assign(410, -1);
	int mcbm = 0;
	for(int i=0;i<banyakNodeKiri;i++) {
		vis.assign(banyakNodeKiri, 0);
		mcbm += Aug(i);
	}
	return mcbm;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);

	while(tc--){
		string kata[maxn];
		scanf("%d %d",&n,&m);
		AdjList.assign(410, vi());
		for(i=0;i<n;i++){
			cin>>kata[i];
		}
		int banyakNode = 0;
		int nodeGenap = 0, nodeGanjil = 205;
		memset(idx,-1,sizeof(idx));
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++){
				if(kata[i][j] == '*') {
					banyakNode++;
					if((i+j)%2==0) {
						idx[i][j] = nodeGenap;
						nodeGenap++;
					}else{
						idx[i][j] = nodeGanjil;
						nodeGanjil++;
					}	
				}
			}
		}
		set<ii> s;

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(kata[i][j] == '*'){
					
					int x = i, y = j;

					for(int k=0;k<4;k++){
						int xbaru = x+dx[k], ybaru = y+dy[k];
						if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<m) {
							if(kata[xbaru][ybaru]=='*') {
								int idxAwal, idxAkhir;
								if(idx[x][y] < 200) {
									idxAwal = idx[x][y], idxAkhir = idx[xbaru][ybaru];
								}else{
									idxAkhir = idx[x][y], idxAwal = idx[xbaru][ybaru];
								}
								if(s.find(ii(idxAwal, idxAkhir)) == s.end()) {
									AdjList[idxAwal].pb(idxAkhir);	
								}
								
							}
						}
					}
				}
			}
		}

		int ans = augmentedAlgo(nodeGenap);
		printf("%d\n",banyakNode - ans);
	}
	return 0;
};