#include <cstdio>

using namespace std;

int main(){
	int n = 10000;
	printf("%d 1000000000\n",n);
	for(int i=0;i<n;i++){
		if(i){printf(" ");}
		printf("100000");
	}
	printf("\n");

	return 0;
}