#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int M,C;
bool reachable[30][210];
int price[30][30];


int main(){
	int TC,i,j;
	scanf("%d",&TC);
	while(TC--){
		scanf("%d %d",&M,&C);
		for(i=1;i<=C;i++){
			scanf("%d",&price[i][0]);
			for(j=1;j<=price[i][0];j++){
				scanf("%d",&price[i][j]);
			}
		}
	}
	//karena tabel DP akan berbentuk 2D...maka 1 line pertama adalah basis
	for(i=1;i<=price[1][0];i++){
		
	}
	return 0;
}