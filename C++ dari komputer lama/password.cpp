#include <cstdio>
#include <cstring>

using namespace std;

int cnt,N,catat[20];
bool pernah[10];
void PrintPassword(int kedalaman){
	int i,j;
	if(kedalaman>N){
		for(i=1;i<=N;i++){printf("%d",catat[i]);}
		printf("\n");
	}else{
		for(i=1;i<=N;i++){
			catat[kedalaman]=i;
			PrintPassword(kedalaman+1);
		}
	}
}

void PrintPasswordUnique(int kedalaman){
	//utilizing array of bool
	int i,j;
	if(kedalaman>N){
		for(j=1;j<=N;j++){
			printf("%d",catat[j]);

		}

		printf("\n");
	}else{
		for(i=1;i<=N;i++){
			if(!pernah[i]){
				pernah[i]=true;
				catat[kedalaman]=i;
				PrintPasswordUnique(kedalaman+1);
				pernah[i]=false;
			}
		}
	}
}



int main(){
	int i;
	memset(pernah,false,10);
	
	scanf("%d",&N);
	printf("password boleh berulang\n");
	PrintPassword(1);
	printf("password tidak boleh berulang\n");
	PrintPasswordUnique(1);
	return 0;
}