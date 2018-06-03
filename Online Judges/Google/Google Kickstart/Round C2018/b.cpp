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
int a[7][7];
int cnt = 0;

int dfs(int node, int parent, int counter, vi listBil, int isGanjil) {
	bool isEnd = true;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(v==parent){continue;}
		isEnd = false;
		if(isGanjil) {
			if(counter%2==1){
				listBil.pb(a[node][v]);
				dfs(v,node,counter+1,listBil, isGanjil);
				listBil.pop_back();
			}
		}else{
			if(counter%2==0) {
				listBil.pb(a[node][v]);
				dfs(v,node,counter+1,listBil, isGanjil);
				listBil.pop_back();
			}
		}
	}
	if(isEnd){
		sort(listBil.begin(), listBil.end());
		int bil1 = listBil[0], bil2 = listBil[1], bil3 = listBil[2];
		if((bil1+bil2) > bil3){
			cnt++;
		}
	}
	
}

int main(){
	int tc,i,j,n;
	
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		AdjList.assign(n+1,vi());
		cnt = 0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]){
					AdjList[i].pb(j);
				}
			}
		}
		for(i=0;i<n;i++){
			vi kos;
			dfs(i,-1,1,kos,1);
			dfs(i,-1,1,kos,0);
		}

		printf("%d\n",cnt);
	}
	return 0;
};