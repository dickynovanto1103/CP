#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	printf("10\n");
	srand((unsigned)time(0));
	for(int i=0;i<10;i++){
		for(int j=0;j<8;j++){
			if(j){printf(" ");}
			int bil = (rand()%1000);
			printf("%d",bil);
		}
		printf("\n");
	}
	return 0;
}