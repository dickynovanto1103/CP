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
vector<ii> listAns;

bool cek(int nodeAwal, int node, int parent) {
	int banyakTetangga = 0, nodeTujuan;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v!=parent) {
			banyakTetangga++;
			nodeTujuan = v;
			if(banyakTetangga>1){return false;}
		}
	}
	if(banyakTetangga==1){
		return cek(nodeAwal, nodeTujuan, node);
	}else if(banyakTetangga==0){//catet jawaban klo udah diujung
		if(nodeAwal!=node) {
			listAns.pb(ii(nodeAwal, node));	
		}
		
		return true;
	}
}

void dfs(int nodeAwal, int node, int parent) {
	int ukuranValid = 0, nodeTujuan;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v!=parent) {
			ukuranValid++;
			nodeTujuan = v;
			if(ukuranValid>1){
				//harus mulai cek
				break;
			}
		}

	}
	if(ukuranValid==1){
		dfs(nodeAwal, nodeTujuan, node);
	}else{
		if(node!=nodeAwal){
			listAns.pb(ii(nodeAwal, node));	
		}
		
		bool valid = true;
		for(int i=0;i<AdjList[node].size();i++) {
			int v = AdjList[node][i];
			if(v!=parent) {
				if(!cek(node, v, node)){
					valid = false;
					break;
				}
			}
		}
		if(!valid){printf("No\n");}
		else{
			printf("Yes\n");
			printf("%d\n",(int)listAns.size());
			for(int i=0;i<listAns.size();i++){
				ii ans = listAns[i];
				printf("%d %d\n",ans.first, ans.second);
			}
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	AdjList.assign(n+1,vi());
	for(i=0;i<(n-1);i++){
		int a,b;
		scanf("%d %d",&a,&b);
		AdjList[a].pb(b); AdjList[b].pb(a);
	}
	int node, maks = -inf;
	for(i=1;i<=n;i++){
		int ukuran = AdjList[i].size();
		if(ukuran > maks) {
			maks = ukuran;
			node = i;
		}
	}

	dfs(node,node,-1);
	return 0;
};