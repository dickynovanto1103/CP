#include <bits/stdc++.h>

using namespace std;
int n;
string kata[25];

int dr[]={-1,-1,0,1,1,1,0,-1};
int dc[]={0,1,1,1,0,-1,-1,-1};

void flood(int x,int y){
	int x_new,y_new,i,j;
	kata[x][y] = '0';
	for(i=0;i<8;i++){
		x_new = x+dr[i]; y_new = y+dc[i];
		if(x_new >=0 && x_new<n && y_new >=0 && y_new<n){
			if(kata[x_new][y_new]=='1'){flood(x_new,y_new);}	
		}
	}
}

int main(){
	int i,j,cnt,tc=1;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){cin>>kata[i];}
		cnt=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(kata[i][j]=='1'){flood(i,j); cnt++;}
			}
		}
		printf("Image number %d contains %d war eagles.\n",tc++,cnt);
	}
	return 0;
}