#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

string kata[55];
int r,c;
int floodFill(int x, int y){
	kata[x][y] = '1';
	int ans = 1;
	int i,j;
	for(i=0;i<4;i++){
		int xbaru = x+dx[i], ybaru = y+dy[i];
		if(xbaru>=0 && xbaru<r && ybaru>=0 && ybaru<c){
			if(kata[xbaru][ybaru]=='*'){
				ans+=floodFill(xbaru,ybaru);
			}
		}
	}
	return ans;
}

int main(){
	int tc,tt,i,j;
	
	scanf("%d",&tc);
	for(tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&r,&c);
		for(i=0;i<r;i++){cin>>kata[i];}
		int maks = 0;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(kata[i][j]=='*'){
					int ans = floodFill(i,j);
					//printf("ans: %d\n",ans);
					maks = max(ans,maks);
				}
			}
		}
		printf("%d\n",maks);
	}
	return 0;
};