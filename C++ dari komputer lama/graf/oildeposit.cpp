#include <bits/stdc++.h>

using namespace std;

int dr[]={-1,-1,0,1,1,1,0,-1};
int dc[]={0,1,1,1,0,-1,-1,-1};
int n,m;
string kata[100];

void floodfill(int x,int y){
	int i,x_new,y_new;
	kata[x][y]='*';
	for(i=0;i<8;i++){
		x_new = x+dr[i]; y_new = y+dc[i];
		if(x_new >= 0 && x_new <n && y_new >= 0 && y_new <m){
			if(kata[x_new][y_new]=='@'){floodfill(x_new,y_new);}
		}
	}
}

int main(){
	int i,j,ans;
	
	while(scanf("%d %d",&n,&m),(n||m)){
		for(i=0;i<n;i++){cin>>kata[i];}
		//proses floodfill
		ans=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(kata[i][j]=='@'){floodfill(i,j);ans++;}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}