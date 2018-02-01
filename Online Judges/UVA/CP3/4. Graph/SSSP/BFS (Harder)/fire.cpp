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

const int maxn = 1001;
string kata[maxn];
vii listFire;
int dist[maxn][maxn];
queue<ii> q,qFire;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
	int tc,i,j,k;
	int r,c;
	scanf("%d",&tc);
	//int test = 1;
	while(tc--){
		//printf("test: %d\n",test++);
		scanf("%d %d",&r,&c);
		for(i=0;i<r;i++){
			cin>>kata[i];
		}
		int x,y; //koordinat J
		vii listPinggir;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				dist[i][j] = inf;
				if(kata[i][j]=='J'){x = i; y = j;}
				else if(kata[i][j]=='F'){listFire.pb(ii(i,j));}

				if(i==0 || i==r-1 || j==0 || j==c-1){
					if(kata[i][j]=='.' || kata[i][j]=='J'){listPinggir.pb(ii(i,j));}
				}
			}
		}
		

		int ukuran = listFire.size();
		dist[x][y] = 0; q.push(ii(x,y));
		//listFire masukin ke queue

		for(i=0;i<ukuran;i++){
			int absis = listFire[i].first, ordinat = listFire[i].second;
			qFire.push(ii(absis,ordinat));
		}

		while(true){
			if(qFire.empty() && q.empty()){break;}
			int ukuran1 = qFire.size(), ukuran2 = q.size();
			int tt;
			for(tt=0;tt<ukuran1;tt++){
				ii front1 = qFire.front(); qFire.pop();
				x = front1.first, y = front1.second;
				for(i=0;i<4;i++){
					int xbaru = x+dx[i], ybaru = y+dy[i];
					if(xbaru>=0 && xbaru<r && ybaru>=0 && ybaru<c){
						if(kata[xbaru][ybaru]=='.'){
							kata[xbaru][ybaru] = 'F';
							qFire.push(ii(xbaru,ybaru));
						}
					}
				}
			}
			for(tt=0;tt<ukuran2;tt++){
				ii front1 = q.front(); q.pop();
				x = front1.first, y = front1.second;
				for(i=0;i<4;i++){
					int xbaru = x+dx[i], ybaru = y+dy[i];
					if(xbaru>=0 && xbaru<r && ybaru>=0 && ybaru<c){
						if(kata[xbaru][ybaru]=='.' && dist[xbaru][ybaru]==inf){
							dist[xbaru][ybaru] = dist[x][y] + 1;
							q.push(ii(xbaru,ybaru));
						}
					}
				}
			}
		}
		
		ukuran = listPinggir.size();
		int ans = inf;
		for(i=0;i<ukuran;i++){
			x = listPinggir[i].first; y = listPinggir[i].second;
			ans = min(ans,dist[x][y]);
		}
		if(ans>=inf){printf("IMPOSSIBLE\n");}
		else{printf("%d\n",ans+1);}

		while(!q.empty()){q.pop();}
		while(!qFire.empty()){qFire.pop();}
		listFire.clear();
	}
	return 0;
};