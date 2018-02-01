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

int r,c,path[101],parent[11][101];
ll a[11][101], dist[11][101];

ll solve(int row, int col){
	if(row<0){row = r-1;}
	else if(row==r){row = 0;}
	if(col==c-1){return a[row][col];}

	if(dist[row][col]!=inf){return dist[row][col];}
	ll a1 = a[row][col]+solve(row+1,col+1);
	ll b = a[row][col]+solve(row,col+1);
	ll c = a[row][col]+solve(row-1,col+1);
	ll minim = min(a1,min(b,c));
	//printf("minim: %lld\n",minim);
	int next;
	if(a1==minim){
		if(row+1==r){next = 0;}
		else{next = row+1;}
		parent[row][col] = min(parent[row][col],next);
	}
	if(b==minim){
		next = row;
		parent[row][col] = min(parent[row][col],next);
	}
	if(c==minim){
		if(row-1<0){next = r-1;}
		else{next = row-1;}
		parent[row][col] = min(parent[row][col],next);
	}
	return dist[row][col] = min(dist[row][col],minim);
}
vi ans;

void PrintPath(int idx, int col){
	/*while(parent[idx][col]!=inf){
		if(cnt>0){printf(" ");}
		printf("%d",parent[idx][col]);
		cnt++;
	}*/
	if(parent[idx][col]==inf){return;}
	ans.pb(parent[idx][col]+1);
	PrintPath(parent[idx][col],col+1);
}

int main() {
	int i,j;
	while(scanf("%d %d",&r,&c)!=EOF){
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				scanf("%lld",&a[i][j]);
				dist[i][j] = inf;
				parent[i][j] = inf;
			}
		}
		ll minim = inf, minidx = -1;
		for(i=0;i<r;i++){
			ll ans = solve(i,0);
			if(minim>ans){
				minim = ans;
				//catat pathnya juga
				minidx = i;
			}
		}
		
		PrintPath(minidx,0);
		int ukuran = ans.size();
		printf("%d",minidx+1);
		for(i=0;i<ukuran;i++){
			printf(" %d",ans[i]);
		}
		printf("\n");
		printf("%lld\n",minim);
		ans.clear();
	}
	return 0;
}