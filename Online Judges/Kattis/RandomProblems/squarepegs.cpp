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

const int maxn = 1e2 + 2;

vector<vi> AdjList;

vi match, vis;

int Aug(int node) {
	// printf("node: %d\n",node);
	if(vis[node]){
		// printf("kena sini\n");
		return 0;
	}
	vis[node] = 1;
	// printf("node: %d\n",node);
	for(int i=0;i<AdjList[node].size();i++) {
		int v = AdjList[node][i];
		// printf("v: %d\n",v);
		if(match[v] == -1 || Aug(match[v])) {
			match[v] = node; return 1; // found 1 matching
		}
	}
	// printf("halo\n");
	return 0; //no matching
}



int main(){
	int n,m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	AdjList.assign(n+m+k+maxn, vi());
	int r1[maxn], r2[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&r1[i]);
	}
	int startKanan = m+k;
	for(i=0;i<m;i++){
		scanf("%d",&r2[i]);
		//cek mana aja yang cocok
		for(j=0;j<n;j++){
			if(r2[i] < r1[j]){
				AdjList[i].pb(startKanan+j);
				// printf("lingkaran connect: %d dan %d\n",i,startKanan+j);
			}
		}
	}
	for(i=0;i<k;i++){
		int sisi;
		scanf("%d",&sisi);
		for(j=0;j<n;j++){
			double maks = sqrt(2)*(double)r1[j];
			if((double)sisi < maks){
				AdjList[m+i].pb(startKanan+j);
				// printf("persegi connect: %d dan %d\n",m+i,startKanan+j);
			}
		}
	}

	int mcbm = 0;
	match.assign(n+m+k+maxn,-1);
	for(i=0;i<m+k;i++){
		vis.assign(n+m+k+maxn,0);
		mcbm+=Aug(i);
		// printf("mcbm jd: %d\n",mcbm);
	}

	printf("%d\n",mcbm);


	return 0;
};