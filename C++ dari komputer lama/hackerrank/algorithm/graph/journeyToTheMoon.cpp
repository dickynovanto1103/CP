#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef long long ll;
typedef pair <int,int> ii;
typedef vector <int> vi;

vi dfs_num;
vector <vi> AdjList;
int cnt;

void dfs(int a){
	int i;
	dfs_num[a]=visited;
	for(i=0;i<AdjList[a].size();i++){
		int v = AdjList[a][i];
		if(dfs_num[v]==unvisited){cnt++; dfs(v);}
	}
}

int main(){
	ll tot, kurang;
	int n,p,i,a,b;
	scanf("%d %d",&n,&p);
	AdjList.assign(n,vi());
	for(i=0;i<p;i++){
		scanf("%d %d",&a,&b);
		AdjList[a].push_back(b); AdjList[b].push_back(a);
	}
	dfs_num.assign(n,unvisited);
	tot = ((ll)n*((ll)n-1))/2;
	//printf("tot: %lld\n",tot);
	//mulai dfs
	for(i=0;i<n;i++){
		if(dfs_num[i]==unvisited){
			cnt = 1; dfs(i);
			//printf("cnt: %d\n",cnt);
			kurang = (ll)(cnt*(cnt-1))/2;
			tot-=kurang;
		}

		
		//printf("tot sekarang: %lld\n",tot);
	}
	printf("%lld\n",tot);
	return 0;
}