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

vector<vi> AdjList;
vector<set<int> > adj;
const int maxn = 2001;

vi match, vis;

int Aug(int node) {
	if(vis[node]){return 0;}
	vis[node] = 1;
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(match[v] == -1 || Aug(match[v])) {
			match[v] = node; return 1; // found 1 matching
		}
	}
	return 0; //no matching
}

map<string,int> mapper;
int cnt = 0;
bool isSame(int idx, const string& a, const string& b){
	int idx1 = a.length() - idx;
	string satu = a.substr(idx1, idx);
	int idx2 = b.length() - idx;
	string dua = b.substr(idx2, idx);
	
	return satu == dua;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	string kata[maxn];
	for(int tt=1;tt<=tc;tt++){
		cnt = 0;
		// AdjList.assign(maxn, vi());
		// adj.assign(maxn, set<int>());
		// set<int>::iterator it;
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(i=0;i<n;i++){cin>>kata[i];}
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				int minim = min(kata[i].length(), kata[j].length());
				for(int k=minim;k>=1;k--){
					// printf("i: %d j: %d k: %d\n",i,j,k);
					if(isSame(k, kata[i], kata[j])){
						int idx1 = kata[i].length() - k;
						string satu = kata[i].substr(idx1, k);
						if(mapper.find(satu) == mapper.end()){
							mapper[satu] = cnt++;
						}
						break;
						// if(adj[i].find(j) == adj[i].end()){
						// 	AdjList[i].pb(j+n);
						// 	adj[i].insert(j+n);
						// 	// printf("sambung %d dan %d saat k: %d\n",i,j,k);
							
						// }
				}
			}
		}
		// printf("cnt: %d\n",cnt);
		printf("%d\n",(int)mapper.size()*2);
		// for(i=0;i<n;i++){
		// 	printf("i: %d=>",i);
		// 	for(j=0;j<AdjList[i].size();j++){
		// 		printf("%d ",AdjList[i][j]);
		// 	}
		// 	printf("\n");
		// }


		// int mcbm = 0;
		// match.assign(maxn, -1);
		// for(i=0;i<n;i++){
		// 	vis.assign(n, 0);
		// 	int nilai = Aug(i);
		// 	if(nilai){
		// 		printf("ketambah nilai: %d saat i: %d\n",nilai, i);
		// 		mcbm += nilai;	
		// 	}
			

		// }
		// for(i=n;i<n+n;i++){
		// 	printf("match[%d]: %d\n",i,match[i]);	
		// }
		// printf("%d\n",mcbm*2);
		mapper.clear();
	}


	return 0;
};