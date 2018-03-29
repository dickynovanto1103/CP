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

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

string tujuan = "ALLIZZWELL";
int n,m;
string kata[110];
bool found;
bool isVisited[101][101];
void dfs(int x, int y, int idx){
	int i,j;
	if(found){return;}
	// printf("karakter sekarang: %c di idx: %d %d\n",tujuan[idx], x,y);	
	
	if(idx==(tujuan.length()-1)){found = true; return;}
	for(i=0;i<8;i++){
		int xbaru = x+dx[i], ybaru = y+dy[i];
		if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<m){
			if(kata[xbaru][ybaru]==tujuan[idx+1] && !isVisited[xbaru][ybaru]){
				// printf("ke %d %d ngejar karakter: %c\n",xbaru,ybaru,tujuan[idx+1]);
				isVisited[xbaru][ybaru] = true;
				dfs(xbaru,ybaru,idx+1);
				if(found){return;}
				isVisited[xbaru][ybaru] = false;
			}
		}
	}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){
			cin>>kata[i];
		}
		vii listKoorA;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(kata[i][j]=='A'){listKoorA.pb(ii(i,j));}
			}
		}
		for(int indeks = 0;indeks<listKoorA.size();indeks++){
			ii koor = listKoorA[indeks];
			int x = koor.first, y = koor.second;
			found = false;
			memset(isVisited,false,sizeof isVisited);
			isVisited[x][y] = true;
			dfs(x,y,0);
			if(found){break;}
		}
		if(found){printf("YES\n");}
		else{printf("NO\n");}
		listKoorA.clear();
	}
	return 0;
};