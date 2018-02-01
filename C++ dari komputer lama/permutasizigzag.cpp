#include <cstdio>
#include <cstring>
using namespace std;

int N,catat[15];
bool pernah[15];

void permutasi(int kedalaman){
	int i;
	if(kedalaman>N){
		for(i=1;i<=N;i++){
			printf("%d",catat[i]);
		}
		printf("\n");
	}else{
		for(i=1;i<=N;i++){
			if(!pernah[i]){
				pernah[i]=true;
				if(i-1>0){
					if((catat[i-1]>i)&&(!pernah[i])){
						catat[kedalaman]=i;
					}else if(catat[i-1]<i && )
				}else{
					catat[kedalaman]=i;
				}
			}
		}
	}
}

int main(){
	memset(pernah,false,15);
	scanf("%d",&N);
	permutasi(1);
	return 0;
}