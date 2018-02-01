#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2;

struct Matrix{
	int mat[maxn][maxn];
};

Matrix MatMul(Matrix a, Matrix b){
	int i,j,k;
	Matrix ans;
	for(i=0;i<maxn;i++){
		for(j=0;j<maxn;j++){
			ans.mat[i][j] = 0;
			for(k=0;k<maxn;k++){
				ans.mat[i][j]+=a.mat[i][k] * b.mat[k][j];
			}
		}
	}
	return ans;
}

int main() {
	Matrix a;
	int i,j,k;
	//inisialisasi
	int bil1,bil2;
	scanf("%d %d",&bil1,&bil2);
	a.mat[0][0] = bil1+bil2; a.mat[0][1] = bil2;
	a.mat[1][0] = bil2; a.mat[1][1] = bil1;
	int n;
	scanf("%d",&n);
	Matrix tetap = a;
	tetap.mat[0][0] = 1; tetap.mat[0][1] = 1;
	tetap.mat[1][0] = 1; tetap.mat[1][1] = 0;
	for(i=0;i<n;i++){
		a = MatMul(a,tetap);
		printf("matrix a:\n");
		for(j=0;j<maxn;j++){
			for(k=0;k<maxn;k++){
				if(k){printf(" ");}
				printf("%d",a.mat[j][k]);
			}
			printf("\n");
		}
	}
	return 0;
}