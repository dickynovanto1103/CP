#include <cstdio>
#include <iostream>
using namespace std;
string kata[104];
int n;
int dr[]={-1,-1,0,1,1,1,0,-1};
int dc[]={0,1,1,1,0,-1,-1,-1};



void flood(int x,int y){
	int x_new,y_new,i,j;
	kata[x][y]='*';
	for(i=0;i<8;i++){
		x_new = x+dr[i]; y_new=y+dc[i];
		if(x_new >=0 && x_new <n && y_new >=0 && y_new <n){
			if(kata[x_new][y_new]=='x' || kata[x_new][y_new]=='@'){flood(x_new,y_new);}
		}
	}
}

int main(){
	int tc,test=1,i,j,cnt;
	scanf("%d",&tc);
	while(tc--){
		printf("Case %d: ",test++);
		scanf("%d",&n);
		for(i=0;i<n;i++){cin>>kata[i];}
		cnt=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(kata[i][j]=='x'){cnt++; flood(i,j);}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}