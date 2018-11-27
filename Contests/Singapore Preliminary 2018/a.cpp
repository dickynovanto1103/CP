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

int dx[] = {-1,-1,1,1,-2,-2,2,2};
int dy[] = {-2,2,-2,2,-1,1,-1,1};

string tujuan = "ICPCASIASG";
char listKata[101][101];

bool isValid;
int pjg;

void dfs(int x, int y, int next){
	int i,j;

	if(isValid){return;}
	// printf("x: %d y: %d kar: %c\n",x,y,listKata[x][y]);
	if(next == pjg){isValid = true;}

	for(i=0;i<8;i++){
		int xbaru = x + dx[i], ybaru = y+dy[i];
		if(tujuan[next] == listKata[xbaru][ybaru]){
			dfs(xbaru, ybaru, next+1);
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	string kata;
	cin>>kata;
	isValid = false;
	int idx = 0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			listKata[i][j] = kata[idx];
			idx++;
		}
	}
	vii listI;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			char kar = listKata[i][j];
			if(kar == 'I'){
				listI.pb(ii(i,j));
			}
		}
	}
	
	pjg = tujuan.length();
	int ukuran = listI.size();
	for(i=0;i<ukuran;i++){
		ii koor = listI[i];
		int x = koor.first, y = koor.second;
		idx = 0;
		dfs(x,y,1);
	}
	if(isValid){printf("YES\n");}
	else{printf("NO\n");}
	return 0;
};