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
typedef pair<int,ii> iii;
typedef vector<ii> vii;

const int maxn = 301;
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
bool isvisited[maxn][maxn];
int main(){
	int n,m,x,y;
	int a[maxn][maxn];
	int i,j,w;
	scanf("%d",&n);
	memset(a,0,sizeof a);
	scanf("%d",&m);
	queue<iii> q;
	for(i=0;i<m;i++){
		scanf("%d %d %d",&x,&y,&w); a[x][y]+=w;
		q.push(mp(w,ii(x,y)));
		memset(isvisited,false,sizeof isvisited);
		while(!q.empty()){
			iii front = q.front(); q.pop();
			int sisaberat = front.first;
			x = front.second.first, y = front.second.second;
			int delivered = sisaberat-1;
			isvisited[x][y] = true;
			if(delivered==0){continue;}

			for(j=0;j<8;j++){
				int xbaru = x+dx[j], ybaru = y+dy[j];
				if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<n){
					if(!isvisited[xbaru][ybaru]){
						a[xbaru][ybaru]+=delivered; isvisited[xbaru][ybaru] = true;
						q.push(mp(delivered,ii(xbaru,ybaru)));
					}
				}
			}
		}

	}
	int maks = -inf;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			// if(j){printf(" ");}
			// printf("%d",a[i][j]);
			maks = max(maks,a[i][j]);
		}
		//printf("\n");
	}
	printf("%d\n",maks);
	return 0;
};