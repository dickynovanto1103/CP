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

char mat[400][400];
bool isVisited[400][400];
int a[5],b[5];

bool can(int pjg){
	int i,j;
	for(i=0;i<pjg;i++){
		for(j=0;j<pjg;j++){
			isVisited[i][j] = false;
		}
	}
	int listBil[] = {0,1,2};
	do{
		for(i=0;i<3;i++){
			int idx = listBil[i];
			
			printf("%d ",listBil[i]);
		}
		printf("\n");
	}while(next_permutation(listBil,listBil+3));


	for(i=0;i<pjg;i++){
		for(j=0;j<pjg;j++){
			if(!isVisited[i][j]){return false;}
		}
	}
	return true;
}

int main(){
	
	int i,j;
	int maks = 0;

	for(i=0;i<3;i++){scanf("%d %d",&a[i],&b[i]); maks = max(maks, a[i]); maks = max(maks, b[i]);}
	int pjg = maks;
	for(pjg = maks;pjg<=300;i++){
		printf("pjg: %d\n",pjg);
		if(can(pjg)){
			printf("%d\n",pjg);
			for(i=0;i<pjg;i++){
				for(j=0;j<pjg;j++){
					printf("%c",mat[i][j]);
				}
				printf("\n");
			}
			break;
		}else{
			break;
		}
	}
	return 0;
};