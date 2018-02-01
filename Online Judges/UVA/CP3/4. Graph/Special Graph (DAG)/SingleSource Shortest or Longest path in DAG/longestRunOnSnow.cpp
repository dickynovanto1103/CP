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

int memo[101][101];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int r,c,a[101][101];

int solve(int x, int y){
	if(memo[x][y]!=-1){return memo[x][y];}
	bool found = false;
	vii listIdx;
	for(int i=0;i<4;i++){
		int xbaru = x+dx[i], ybaru = y+dy[i];
		if(xbaru>=0 && xbaru<r && ybaru>=0 && ybaru<c){
			if(a[x][y] > a[xbaru][ybaru]){
				listIdx.pb(ii(xbaru,ybaru));
			}
		}
	}
	int ukuran = listIdx.size();
	if(ukuran==0){return 0;}//sudah ga bs slide lg
	else{
		int ans = -inf;

		for(int i=0;i<ukuran;i++){
			int xbaru = listIdx[i].first, ybaru = listIdx[i].second;
			ans = max(ans,1+solve(xbaru,ybaru));
		}
		return memo[x][y] = ans;
	}
}

int main() {
	int tc,i,j,k;
	string kata;
	scanf("%d",&tc);
	while(tc--){
		cin>>kata>>r>>c;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				scanf("%d",&a[i][j]);
			}
		}
		vii listNode;
		
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				for(k=0;k<4;k++){
					int x = i+dx[k], y = j+dy[k];
					if(x>=0 && x<r && y>=0 && y<c){
						if(a[i][j] < a[x][y]){
							break;
						}
					}
				}
				if(k==4){listNode.pb(ii(i,j));}
			}
		}
		//printf("list node tertinggi\n");
		int ans = -inf;
		memset(memo,-1,sizeof memo);
		for(i=0;i<listNode.size();i++){
			int x = listNode[i].first, y = listNode[i].second;
			ans = max(ans, solve(x,y));
		}
		cout<<kata;
		printf(": %d\n",ans+1);
		/*cout<<"kata: "<<kata<<" r: "<<r<<" c: "<<c<<endl;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(j){printf(" ");}
				printf("%d",a[i][j]);
			}
			printf("\n");
		}*/

	}
	
	return 0;
}