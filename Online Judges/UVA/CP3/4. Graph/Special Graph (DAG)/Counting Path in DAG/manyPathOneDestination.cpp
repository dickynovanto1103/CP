#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> AdjList;
vi dfs_num, ts;


void toposort(int awal){
	dfs_num[awal] = visited;
	int i;
	for(i=0;i<AdjList[awal].size();i++){
		int v = AdjList[awal][i];
		if(dfs_num[v]==unvisited){
			toposort(v);
		}
	}
	ts.pb(awal);
}

int main() {
	int n,i,j;
	int test =1;
	while(scanf("%d",&n)!=EOF){
		if(test==2){printf("\n");}
		vi listNol;
		AdjList.assign(1001,vi());
		dfs_num.assign(1001,unvisited);
		for(i=0;i<n;i++){
			int m;
			scanf("%d",&m);
			for(j=0;j<m;j++){
				int bil;
				scanf("%d",&bil);
				AdjList[i].pb(bil);
			}
			if(!m){listNol.pb(i);}
		}
		for(i=0;i<n;i++){
			//printf("i: %d\n",i);
			if(dfs_num[i]==unvisited){
				toposort(i);
			}
		}
		/*printf("listnol\n");
		for(i=0;i<listNol.size();i++){
			if(i){printf(" ");}
			printf("%d",listNol[i]);
		}
		printf("\n");*/
		reverse(ts.begin(),ts.end());
		/*printf("toposort\n");
		for(i=0;i<ts.size();i++){
			if(i){printf(" ");}
			printf("%d",ts[i]);
		}
		printf("\n");*/
		int a[1001];
		//printf("test: \n");
		for(i=0;i<=1000;i++){a[i] = 0;}
		a[0] = 1;
		//printf("%d\n",ts.size());
		for(i=0;i<ts.size();i++){
			//printf("i: %d\n",i);
			int node = ts[i];
			//printf("node: %d\n",node);
			for(j=0;j<AdjList[node].size();j++){
				int v = AdjList[node][j];
				a[v]+=a[node];
			}
		}
		int ans = 0;
		for(i=0;i<listNol.size();i++){
			int node = listNol[i];
			ans+=a[node];
			//printf("%d",listNol[i]);
		}
		printf("%d\n",ans);

		AdjList.clear();
		ts.clear();
		test = 2;
	}

	return 0;
}