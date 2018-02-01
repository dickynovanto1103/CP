#include <bits/stdc++.h>

using namespace std;
#define maxn 10000
int main(){
	char kata1[maxn],kata2[maxn];
	int i,bil1,bil2;


	while(scanf("%s",kata1)!=EOF){
		for(i=0;i<strlen(kata1);i++){
			bil1=kata1[i];
			bil1-=7;
			printf("%c",bil1);
		}
		printf("\n");
	}
	return 0;
}