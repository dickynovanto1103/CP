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

const int maxn = 65;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int a[maxn][maxn];
int cnt,n;
bool foundSolution;
bool isMelawan(int xawal, int yawal, int xakhir, int yakhir, char dir){
	if(dir=='n'){
		if((xakhir-xawal)==1){return true;}
	}else if(dir=='s'){
		if((xakhir-xawal)==-1){return true;}
	}else if(dir=='e'){
		if((yakhir-yawal)==-1){return true;}
	}else if(dir=='w'){
		if((yakhir-yawal)==1){return true;}
	}
	return false;
}
void dfs(int x, int y, char dir){
	if(foundSolution){return;}
	a[x][y] = cnt++;
	int i,j;
	if(dir=='n'){
		if((x-1)>=0 && a[x-1][y]==0){dfs(x-1,y,dir);}
	}else if(dir=='e'){
		if((y+1)<n && a[x][y+1]==0){dfs(x,y+1,dir);}
	}else if(dir=='w'){
		if((y-1)>=0 && a[x][y-1]==0){dfs(x,y-1,dir);}
	}else{
		if((x+1)<n && a[x+1][y]==0){dfs(x+1,y,dir);}
	}
	queue<ii> q;
	for(i=0;i<4;i++){
		int xbaru = x+dx[i], ybaru = y+dy[i];
		if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<n){
			if(a[xbaru][ybaru]==0){q.push(ii(xbaru,ybaru));}
		}
	}
	if(q.size()==1){
		ii front = q.front(); q.pop();
		int xbaru = front.first, ybaru = front.second;
		dfs(xbaru,ybaru,dir);
	}else{
		while(!q.empty()){
			ii front = q.front(); q.pop();
			int xbaru = front.first, ybaru = front.second;
			if(isMelawan(x,y,xbaru,ybaru,dir)){continue;}
			dfs(xbaru,ybaru,dir);
		}
	}
}

int main(){
	int i,j;
	
	char kar;
	int x,y;
	scanf("%d",&n);
	scanf(" %c",&kar);
	//printf("kar: %c\n",kar);
	scanf("%d %d",&x,&y);
	
	
	cnt = 1;
	foundSolution = false;
	dfs(x,y,kar);
	//output
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j){printf(" ");}
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
};