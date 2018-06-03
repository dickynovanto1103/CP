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
typedef pair<char,int> ci;
typedef pair<ii,ii> iiii;
typedef vector<ii> vii;
typedef vector<ci> vci;

vector<vi> AdjList;
vi match, vis, match1,vis1;
int n;
int Aug(int node) {
	if(vis[node]) {return 0;}
	vis[node] = 1;
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(match[v] == -1 || Aug(match[v])) {
			match[v] = node; 
			// printf("lagi match[%d]: %d\n",v,match[v]);
			return 1;
		}
	}
	return 0;
}

int augmentedAlgo(int banyakNodeKiri, int banyakNodeTotal) {
	match.assign(banyakNodeTotal, -1);
	int mcbm = 0;
	for(int i=0;i<banyakNodeKiri;i++) {
		vis.assign(banyakNodeKiri,0);
		mcbm+=Aug(i);
	}
	
	return mcbm;
}

int Aug1(int node, int forbidden) {
	if(vis1[node]) {return 0;}
	vis1[node] = 1;
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		if(v == forbidden){continue;}
		if(match1[v] == -1 || Aug(match1[v])) {
			match1[v] = node;
			return 1;
		}
	}
	return 0;
}

int augmentedAlgo1(int banyakNodeKiri, int banyakNodeTotal, int node, int pasangan) {
	match1.assign(banyakNodeTotal, -1);
	int mcbm = 0;
	for(int i=0;i<banyakNodeKiri;i++) {
		vis1.assign(banyakNodeKiri,0);
		if(node==i){
			mcbm+=Aug1(i, pasangan);	
		}else{
			mcbm+=Aug1(i,-1);
		}
		
	}
	
	return mcbm;
}

int idx[256];
vci listAns;

void check(int banyakNodeKiri, int mcbmLama) {
	for(int i=n;i<2*n;i++) {
		int hasilMatch = match[i];
		int ans = augmentedAlgo1(n,2*n,match[i],i);
		if(ans!=mcbmLama){
			listAns.pb(ci(match[i]+'A', i-n+1));
		}
	}
}

bool cmp(ci a, ci b){
	return a.first < b.first;
}

int main(){
	int tc = 1;
	int i,j;
	
	while(scanf("%d",&n), n) {
		printf("Heap %d\n",tc++);
		vector<iiii> kertas;

		bool isValid = true;
		for(i=0;i<n;i++){
			iiii a;
			
			scanf("%d %d %d %d",&a.first.first,&a.first.second,&a.second.first,&a.second.second);

			kertas.pb(a);
		}

		vector<ii> koordinat;
		for(i=0;i<n;i++){
			// printf("i: %d isValid: %d\n",i,isValid);
			ii koor;
			scanf("%d %d",&koor.first,&koor.second);
			koordinat.pb(koor);
		}

		AdjList.assign(26*2,vi());
		// printf("halo\n");
		for(i=0;i<n;i++){
			ii koor = koordinat[i];
			int x = koor.first, y = koor.second;
			for(j=0;j<n;j++){
				iiii paper = kertas[j];
				int xmin = paper.first.first, xmax = paper.first.second, ymin = paper.second.first, ymax = paper.second.second;

				if(x>xmin && x < xmax && y>ymin && y<ymax) {
					AdjList[j].pb(i+n);
				}
			}
		}
		

		int ans = augmentedAlgo(n,2*n);
		
		memset(idx,-1,sizeof idx);
		for(i=n;i<2*n;i++){
			pair<char,int> jawab;
			jawab.second = i-n+1;
			jawab.first = match[i] +'A';
			idx[jawab.first] = jawab.second;

			// printf("match[%d]: %d\n",i,match[i]);
		}

		check(n, ans);
		if(listAns.size() == 0){
			printf("none\n\n");
		}else{
			sort(listAns.begin(), listAns.end(), cmp);
			for(i=0;i<listAns.size();i++){
				if(i){printf(" ");}
				ci jawab = listAns[i];
				printf("(%c,%d)",jawab.first, jawab.second);
			}
			printf("\n\n");
		}
		
		listAns.clear();
		
		// printf("%d\n\n",ans);
	}
	return 0;
};