#include <cstdio>
#include <iostream>
using namespace std;

int dr[]={-1,-1,0,1,1,1,0,-1};
int dc[]={0,1,1,1,0,-1,-1,-1};

int main(){
	int n,m,i,j,k,x,y,ans,tc=1;
	string kata [100];
	while(scanf("%d %d",&n,&m),(n||m)){
		if(tc>1){printf("\n");}
		printf("Field #%d:\n",tc++);
		for(i=0;i<n;i++){cin>>kata[i];}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(kata[i][j]=='.'){
					//cek jumlah mine disekitar
					ans = 0;
					for(k=0;k<8;k++){
						x = i+dr[k]; y = j+dc[k];
						if(x>=0 && x<n && y>=0 && y<m ){
							if(kata[x][y]=='*'){ans++;}
						}
					}
					//ketemu jawaban
					char karakter = ans+'0';
					kata[i][j] = karakter;
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				printf("%c",kata[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}