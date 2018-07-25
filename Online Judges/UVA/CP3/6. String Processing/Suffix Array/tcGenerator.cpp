#include <bits/stdc++.h>

using namespace std;

int main() {
	srand(time(NULL));
	printf("%d\n",100);
	int i,j;
	for(i=0;i<100;i++){
		for(j=0;j<10000;j++){
			int bil = rand() % 26;
			char kar = bil+'a';
			printf("%c",kar);
		}
		printf("\n");
	}
	return 0;
}