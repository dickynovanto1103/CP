#include <cstdio>
#include <cstring>
using namespace std;

int catat[15];
bool pernah[15];

void tulis(int N, int K){
	int i;
	if(K==0){
		for(i=1;i<=N;i++){
			printf("%d ",catat[i]);
		}
		printf("\n");
	}else{
		for(i=1;i<=N;i++){
			catat[i]=i;
			tulis(N,K-1);
		}
	}
}

int main(){
	int N,K,i;
	memset(pernah,false,sizeof pernah);
	scanf("%d %d",&N,&K);
	tulis(N,K);
	return 0;
}