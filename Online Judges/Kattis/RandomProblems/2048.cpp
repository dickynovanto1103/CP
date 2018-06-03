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

int main(){
	int a[5][5];
	int com;
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d",&com);
	if(com==0) {
		for(i=0;i<4;i++){
			//ke kiri semua
			for(j=0;j<4;j++){
				for(int k=j+1;k<4;k++){
					if(a[i][j] == 0 && a[i][k]!=0){
						swap(a[i][j], a[i][k]);
						break;
					}
				}
			}
			for(j=0;j<3;j++){
				if(a[i][j]==0){
					for(int k=j;k<4;k++){
						for(int l=k+1;l<4;l++){
							if(a[i][k] == 0 && a[i][l]!=0){
								swap(a[i][k], a[i][l]);
								break;
							}	
						}
					}
					
					if(a[i][j]!=0){j--;}		
				}else if(a[i][j] == a[i][j+1]){
					a[i][j]*=2; a[i][j+1] = 0;
				}

			}
			
		}
	}else if(com==2) { //right
		for(i=0;i<4;i++){
			//ke kanan semua
			for(j=3;j>=0;j--){
				for(int k=j-1;k>=0;k--){
					if(a[i][j] == 0 && a[i][k]!=0){
						swap(a[i][j], a[i][k]);
						break;
					}
				}
			}
			for(j=3;j>0;j--){
				if(a[i][j]==0){
					for(int k=j;k>=0;k--){
						for(int l=k-1;l>=0;l--){
							if(a[i][k] == 0 && a[i][l]!=0){
								swap(a[i][k], a[i][l]);
								break;
							}	
						}
					}	
					if(a[i][j]!=0){j++;}	
				}else if(a[i][j] == a[i][j-1]){
					a[i][j]*=2; a[i][j-1] = 0;
				}
			}
		}
	}else if(com==1) {
		for(j=0;j<4;j++){
			//ke atas semua
			for(i=0;i<4;i++){
				for(int k=i+1;k<4;k++){
					if(a[i][j] == 0 && a[k][j]!=0){
						swap(a[i][j], a[k][j]);
						break;
					}
				}
			}
			for(i=0;i<3;i++){
				if(a[i][j]==0){
					for(int k=i;k<4;k++){
						for(int l=k+1;l<4;l++){
							if(a[k][j] == 0 && a[l][j]!=0){
								swap(a[k][j], a[l][j]);
								break;
							}	
						}
					}
				}else if(a[i][j] == a[i+1][j]){
					a[i][j]*=2; a[i+1][j] = 0;
				}
			}
		}
	}else{
		// printf("test\n");
		// for(i=0;i<4;i++){
		// 	for(j=0;j<4;j++){
		// 		if(j){printf(" ");}
		// 		printf("%d",a[i][j]);
		// 	}
		// 	printf("\n");
		// }
		for(j=0;j<4;j++){
			//ke bawah semua
			for(i=3;i>=0;i--){
				for(int k=i-1;k>=0;k--){


					if(a[i][j] == 0 && a[k][j]!=0){
						// printf("i: %d j: %d k: %d\n",i,j,k);
						swap(a[i][j], a[k][j]);
						break;
					}
				}
			}

			for(i=3;i>0;i--){
				// printf("observe a[%d][%d]: %d\n", i,j,a[i][j]);
				if(a[i][j]==0){
					for(int k=i;k>=0;k--){
						for(int l=k-1;l>=0;l--){
							if(a[k][j] == 0 && a[l][j]!=0){
								// printf("yang dituker: a[%d][%d]:%d dan a[%d][%d]: %d\n",k,j,a[k][j], l,j,a[l][j]);
								swap(a[k][j], a[l][j]);
								break;
							}	
						}
					}
				}else if(a[i][j] == a[i-1][j]){
					// printf("i: %d j: %d\n",i,j);
					a[i][j]*=2; a[i-1][j] = 0;
				}
			}
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(j){printf(" ");}
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
};