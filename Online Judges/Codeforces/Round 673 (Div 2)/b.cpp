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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n,x;
	scanf("%d",&tc);
	int a[100001];
	int color[100001];
	while(tc--){
		scanf("%d %d",&n,&x);
		map<int,int> mapper, mapperIdx;
		map<int, bool> vis;
		set<int> s;
		vector<vi> adj;
		int idx = 0;
		adj.assign(n+1, vi());
		for(i=0;i<n;i++){
			color[i] = -1;
			scanf("%d",&a[i]);
			s.insert(a[i]);
			if(mapperIdx.find(a[i]) == mapperIdx.end()) {
				mapperIdx[a[i]] = idx;

			}
			int index = mapperIdx[a[i]];
			adj[index].pb(i);
			idx++;
		}

		for(i=0;i<n;i++){
			int pasangan = x - a[i];
			// printf("i: %d color: %d\n",i, color[i]);
			if(color[i] != -1){continue;}
			// printf("a[%d]: %d pasangan: %d\n",i, a[i], pasangan);
			if(s.find(pasangan) != s.end()){
				if(pasangan == a[i]){
					//bagi 2
					int turn = 0;
					int index = mapperIdx[a[i]];
					for(j=0;j<adj[index].size();j++){
						int idx = adj[index][j];
						// printf("idx: %d\n",idx);
						color[idx] = turn;
						turn = 1 - turn;
					}
				}else{
					mapper[a[i]] = 0;
					mapper[pasangan] = 1;	
				}
				
			}else{
				// printf("ga ketemu\n");
				mapper[a[i]] = 0;
			}
		}
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			if(color[i] == -1){
				printf("%d",mapper[a[i]]);
			}else{
				printf("%d",color[i]);	
			}
			
		}
		printf("\n");

	}
	
	return 0;
};