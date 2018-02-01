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

vector<vi> AdjList;
int nilai1[1000001], nilai2[1000001];

void dfs(int desa, int val1, int val2){
	nilai1[desa]+=val1; nilai2[desa]+=val2;
	//printf("mati\n");
	for(int i=0;i<AdjList[desa].size();i++){
		int v = AdjList[desa][i];
		dfs(v,val1,val2);
	}
}

int main(){
	int n,i,j,q;
	int id,banyak,nilai;
	scanf("%d",&n);
	AdjList.assign(1000001,vi());
	while(n--){
		scanf("%d %d",&id,&banyak);
		for(i=0;i<banyak;i++){scanf("%d",&nilai); AdjList[nilai].pb(id);}

	}
	scanf("%d",&q);
	//printf("q awal: %d\n",q);
	while(q--){
		//printf("q: %d\n",q);
		int com, r1,r2;
		scanf("%d",&com);
		if(com==-1){
			int vil;
			scanf("%d",&vil);
			printf("%d %d\n",nilai1[vil],nilai2[vil]);
		}else{
			scanf("%d %d",&r1,&r2);
			dfs(com,r1,r2);
		}
	}
	return 0;
};