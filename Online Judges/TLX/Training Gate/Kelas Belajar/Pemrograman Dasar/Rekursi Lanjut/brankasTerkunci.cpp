#include <cstdio>

using namespace std;
int n, k;
int catat[10];
bool visited[10];
void solve(int kedalaman, int lastbil) {
	int i;
	if(kedalaman > n){
		//cetak
		for(i=1;i<=n;i++){
			if(i>1){printf(" ");}
			printf("%d",catat[i]);
		}
		printf("\n");
	}else {
		for(i=lastbil+1;i<=k;i++){
			if(!visited[i]){
				catat[kedalaman] = i;
				visited[i] = true;
				solve(kedalaman+1,i);	
				visited[i] = false;
			}
			
		}
	}
}

int main() {
	
	scanf("%d %d",&k, &n);
	solve(1,0);
	return 0;
}