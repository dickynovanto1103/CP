#include <bits/stdc++.h>

using namespace std;
int a[12][12],n,m;
int dr[8]={-1,-1,-1,0,0,1,1,1};
int dc[8]={-1,0,1,-1,1,-1,0,1};
int floodfill(int x, int y){
	a[x][y] = 2;
	int ans=1;
	int i,j;
	for(i=0;i<8;i++){
		int xbaru = x+dr[i], ybaru = y+dc[i];
		if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<m){
			if(a[xbaru][ybaru]==1){
				ans+=floodfill(xbaru,ybaru);
			}	
		}
		
	}
	return ans;
}

int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int maks = -1;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i][j]==1){
				maks = max(maks,floodfill(i,j));
			}
		}
	}
	printf("%d\n",maks);
	return 0;
}