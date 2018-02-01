#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;

int main(){
	int n,m,i,j;
	while(scanf("%d %d",&n,&m)!=EOF){
		AdjList.assign(m+1,vii());
		int counter;
		for(i=1;i<=n;i++){
			scanf("%d",&counter);
			int listidx[10010];
			for(j=1;j<=counter;j++){scanf("%d",&listidx[j]);}
			int bil;
			for(j=1;j<=counter;j++){scanf("%d",&bil); AdjList[listidx[j]].push_back(ii(i,bil));}
		}
		printf("%d %d\n",m,n);
		for(i=1;i<=m;i++){
			int ukuran = AdjList[i].size();
			printf("%d",ukuran);
			for(j=0;j<ukuran;j++){
				ii pair = AdjList[i][j];
				printf(" %d",pair.first);
			}
			printf("\n");
			for(j=0;j<ukuran;j++){
				ii pair = AdjList[i][j];
				if(j>0){printf(" ");}
				printf("%d",pair.second);
			}
			printf("\n");
		}
		AdjList.clear();
	}
	return 0;
}