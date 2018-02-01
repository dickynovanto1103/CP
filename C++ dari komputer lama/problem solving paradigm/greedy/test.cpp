#include <cstdio>

using namespace std;

int main(){
	int i,j;
	for(i=0,j=0;i<5;i++){
		printf("i: %d j: %d\n",i,j);
		while(j<5){
			printf("i: %d j: %d\n",i,j);
			j++;
		}
	}
	return 0;
}