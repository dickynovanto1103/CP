#include <cstdio>

using namespace std;

int main(){
	printf("200\n");
	for(int i=0;i<200;i++){
		printf("100000 %lld\n",1<<31);
	}
}