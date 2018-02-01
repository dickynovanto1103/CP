#include <cstdio>

using namespace std;

int main(){
	printf("5000\n");
	for(int i=0;i<5000;i++){
		printf("1");
		for(int j=0;j<1000;j++){
			printf("0");
		}
		printf("\n");
	}
	return 0;
}