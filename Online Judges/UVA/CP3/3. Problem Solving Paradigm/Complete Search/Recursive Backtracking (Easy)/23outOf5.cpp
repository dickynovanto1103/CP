#include <bits/stdc++.h>

using namespace std;
int n,bil[5],op[3] = {1,2,3};
int catat[5];
bool found;

void solve(int kedalaman){
	if(found){return;}
	int i;
	if(kedalaman==4){
		int total = bil[0];
		for(i=0;i<4;i++){
			/*if(i>0){printf(" ");}
			printf("%d",catat[i]);*/
			if(catat[i]==1){//perkalian
				total+=bil[i+1];
			}else if(catat[i]==2){
				total-=bil[i+1];
			}else{
				total*=bil[i+1];
			}
			//printf("operasi: %d total: %d\n",catat[i],total);
		}
		//printf("\n");
		//printf("end\n");
		if(total==23){found=true; return;}
	}else{
		for(i=0;i<3;i++){
			catat[kedalaman] = op[i];
			solve(kedalaman+1);
		}
	}
	
}

int main(){
	int i;
	while(scanf("%d %d %d %d %d",&bil[0],&bil[1],&bil[2],&bil[3],&bil[4]), (bil[0]||bil[1]||bil[2]||bil[3]||bil[4])){
		found = false;
		sort(bil,bil+5);
		do{
			/*printf("permutasi:");
			for(i=0;i<5;i++){printf(" %d",bil[i]);}
			printf("\n");*/
			solve(0);
			if(found){break;}
		}while(next_permutation(bil,bil+5));
		if(found){printf("Possible\n");}
		else{printf("Impossible\n");}
	}
	return 0;
}