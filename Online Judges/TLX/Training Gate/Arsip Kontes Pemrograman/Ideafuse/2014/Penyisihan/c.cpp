#include <bits/stdc++.h>

using namespace std;

int n,i,j,t,k;
int m;
bool vis[203][203];
string s[203];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int hitung = 0;

void dfs(int x, int y){
	vis[x][y] = true;
	hitung +=4;
	for(int i=0;i<4;i++){
		int xx = x+dx[i];
		int yy = y+dy[i];
		if(xx>=0&&xx<n&&yy>=0&&yy<m){
			if(s[xx][yy]=='1'){
				if(vis[xx][yy]){
					hitung--;
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		int xx = x+dx[i];
		int yy = y+dy[i];
		if(xx>=0&&xx<n&&yy>=0&&yy<m){
			if(s[xx][yy]=='1'){
				if(!vis[xx][yy]){
					dfs(xx, yy);
				} 
			}
		}
	}
}

int main() {
	memset(vis, false, sizeof vis);
	scanf("%d %d", &n, &m);
	for(i=0;i<n;i++)
		cin>>s[i];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(vis[i][j])
				continue;
			if(s[i][j]=='0')
				continue;
			dfs(i,j);
		}
	}

	printf("%d\n", hitung);
}