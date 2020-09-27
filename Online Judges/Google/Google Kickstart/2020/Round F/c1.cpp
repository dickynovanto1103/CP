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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,s,x1,y1,x2,y2,c,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d %d %d %d %d",&s,&x1,&y1,&x2,&y2,&c);
		bool isRusak[10][10];
		memset(isRusak, false, sizeof isRusak);
		bool isPainted[10][10];
		memset(isPainted, false, sizeof isPainted);
		map<ii, int> mapper;
		ii a[10];
		mapper[ii(1,1)] = 1; a[1] = ii(1,1);
		mapper[ii(2,1)] = 2; a[2] = ii(2,1);
		mapper[ii(2,2)] = 3; a[3] = ii(2,2);
		mapper[ii(2,3)] = 4; a[4] = ii(2,3);
		for(i=0;i<c;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			isRusak[x][y] = true;
		}
		vector<vi> adj;
		adj.assign(10, vi());
		adj[1].pb(3); adj[3].pb(1);
		adj[2].pb(3); adj[3].pb(2);
		adj[3].pb(4); adj[4].pb(3);
		int satu = 1, dua = 1;
		isPainted[x1][y1] = true; isPainted[x2][y2] = true;
		bool turn = 0;
		int selesai = 0;
		while(selesai < 3){
			int idx;
			if(!turn){
				idx = mapper[ii(x1,y1)];
			}else{
				idx = mapper[ii(x2,y2)];
			}
			ii next = ii(-1,-1);
			for(i=0;i<adj[idx].size();i++){
				int v = adj[idx][i];
				ii koor = a[v];
				if(isPainted[koor.first][koor.second] || isRusak[koor.first][koor.second]) {continue;}
				else{
					next = koor;
				}
			}
			ii koor = next;
			// printf("turn; %d koor: %d %d\n"÷,turn, koor.first, koor.second);
			if(koor == ii(-1,-1)){
				if(turn == 0){selesai |= 1;}
				else{selesai |= 2;}
			}else{
				isPainted[koor.first][koor.second] = true;
				if(!turn){
					x1 = koor.first, y1 = koor.second;
					satu++;
				}else{
					x2 = koor.second, y2 = koor.second;
					dua++;
				}
			}
			turn = 1 - turn;
		}
		printf("%d\n",satu - dua);
	}

	
	return 0;
};