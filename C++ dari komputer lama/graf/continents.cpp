#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
string kata[25];
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
int n,m,cnt;
char darat;

int flood(int x,int y){
	int x_new,y_new,i,j,ans;
	kata[x][y]=(darat+1)%256;
	ans=1;
	/*printf("ke: %d\n",++cnt);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%c",kata[i][j]);
		}
		printf("\n");
	}*/
	for(i=0;i<4;i++){
		x_new = x+dr[i]; y_new = y+dc[i];
		
		if(y_new==m){y_new=0;}
		else if(y_new==-1){y_new=m-1;}
		if(y_new>=0 && y_new <m && x_new>=0 && x_new <n){
			if(kata[x_new][y_new]==darat){ans+=flood(x_new,y_new);}
		}
	}
	return ans;
}

int main(){
	int x,y,i,j;
	int ans;
	
	while(scanf("%d %d",&n,&m)!=EOF){
		for(i=0;i<n;i++){cin>>kata[i];}
		cnt=0;
		scanf("%d %d",&x,&y);
		darat = kata[x][y];
		flood(x,y);
		
		ans=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(kata[i][j]==darat){ans=max(ans,flood(i,j));}
			}
		}
		/*for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				printf("%c",kata[i][j]);
			}
			printf("\n");
		}*/
		printf("%d\n",ans);
	}
	return 0;
}