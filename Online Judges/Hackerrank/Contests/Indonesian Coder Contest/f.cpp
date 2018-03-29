#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	int mat[101][101];
	scanf("%d",&n);
	int bil = 1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			mat[j][i] = bil++;
		}
	}
	if(n>3){
		//ambil tengah
		int matBaru[101][101];

		for(i=1;i<(n-1);i++){
			for(j=1;j<(n-1);j++){
				matBaru[i][j] = mat[j][i];

			}
		}
		for(i=1;i<(n-1);i++){
			for(j=1;j<(n-1);j++){
				mat[i][j] = matBaru[i][j];
			}
			
		}

	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j){printf(" ");}
			printf("%d",mat[i][j]);
		}
		printf("\n");
	}

	return 0;
};