#include <cstdio>

using namespace std;

//menulis semua kemungkinan permutasi n digit..angka bs berulang
int catat[10];
void solve(int kedalaman, int n){
	int i;
	if(kedalaman > n) {
		for(i=1;i<=n;i++){printf("%d",catat[i]);}
		printf("\n");
	}else {
		for(i=1;i<=n;i++){
			catat[kedalaman] = i;
			solve(kedalaman+1, n);
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	solve(1, n);
	return 0;
}