#include <cstdio>

using namespace std;

void gambar(int N){
	if(N==1){
		printf("*\n");
	}else{
		gambar(N-1);
		for(int i=1;i<=N;i++){printf("*");}
		printf("\n");
		gambar(N-1);
	}
}

int main(){
	int N;
	scanf("%d",&N);
	gambar(N);
	return 0;
}