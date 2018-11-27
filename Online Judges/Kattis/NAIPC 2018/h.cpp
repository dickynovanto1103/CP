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

int mat[51][51];
int pjgRow, pjgCol;
bool isColSmaller(int col1, int col2){
	for(int i=0;i<pjgRow;i++){
		if(mat[i][col1] < mat[i][col2]){
			return true;
		}else if(mat[i][col1] > mat[i][col2]){
			return false;
		}
	}
	return false;
}

bool isRowBigger(int row1, int row2){
	for(int i=0;i<pjgCol;i++){
		if(mat[row1][i] > mat[row2][i]){
			return true;
		}else if(mat[row1][i] < mat[row2][i]){
			return false;
		}
	}
	return false;
}

int main(){
	string row, col;
	cin>>row>>col;
	pjgRow = row.length(), pjgCol = col.length();
	int parRow = pjgRow%2, parCol = pjgCol%2;
	int i,j;
	memset(mat, -1, sizeof mat);
	int cntRow[51], cntCol[51];
	memset(cntRow, 0, sizeof cntRow); memset(cntCol, 0, sizeof cntCol);
	for(i=0;i<pjgRow;i++){
		int bil = row[i] - '0';
		if(bil == parCol){
			for(j=0;j<pjgCol;j++){

				mat[i][j] = 1;
				cntRow[i] = 1 - cntRow[i];
				cntCol[j] = 1 - cntCol[j];
			}
		}
	}

	for(i=0;i<pjgCol;i++){
		int bil = col[i] - '0';
		if(bil == parRow){
			for(j=0;j<pjgRow;j++){
				if(mat[j][i] != -1){continue;}
				mat[j][i] = 1;
				cntCol[i] = 1 - cntCol[i];
				cntRow[j] = 1 - cntRow[j];
			}
		}
	}
	// printf("awal:\n");
	// for(i=0;i<pjgRow;i++){
	// 	for(j=0;j<pjgCol;j++){
	// 		printf("%d",mat[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// for(i=0;i<pjgRow;i++){
		
	// 	printf("%d ",cntRow[i]);
	// }
	// printf("\n");
	// for(j=0;j<pjgCol;j++){
	// 	printf("%d ",cntCol[j]);
	// }
	// printf("\n");

	for(i=0;i<pjgRow;i++){
		for(j=0;j<pjgCol;j++){
			if(mat[i][j] == -1){
				if(cntRow[i] != (row[i] - '0') && cntCol[j] != (col[j] - '0')){
					mat[i][j] = 1;
					cntRow[i] = 1 - cntRow[i];
					cntCol[j] = 1 - cntCol[j];
				}else{
					mat[i][j] = 0;
				}
			}
		}
	}

	// for(i=0;i<pjgRow;i++){
	// 	for(j=0;j<pjgCol;j++){
	// 		printf("%d",mat[i][j]);
	// 	}
	// 	printf("\n");
	// }

	for(i=0;i<pjgRow;i++){
		// printf("cntRow[%d]: %d\n",i,cntRow[i]);
		if(cntRow[i] != (row[i] - '0')){
			printf("-1\n");
			return 0;
		}
	}
	for(i=0;i<pjgCol;i++){
		// printf("cntCol[%d]: %d\n",i,cntCol[i]);
		if(cntCol[i] != (col[i] - '0')){
			printf("-1\n");
			return 0;
		}
	}
	//coba tukar"di sisi kolom dulu..cari parity kolom sama 
	int k;
	for(i=pjgCol-1;i>=0;i--){
		for(j=i-1;j>=0;j--){
			if(cntCol[i] == cntCol[j]){
				if(isColSmaller(i,j)){
					for(k=0;k<pjgRow;k++){
						swap(mat[k][i], mat[k][j]);
					}
				}
			}
		}
	}

	for(i=0;i<pjgRow;i++){
		for(j=i+1;j<pjgRow;j++){
			if(cntRow[i] == cntRow[j]){
				if(isRowBigger(i,j)){
					printf("i: %d j: %d\n",i,j);
					for(k=0;k<pjgCol;k++){
						swap(mat[i][k], mat[j][k]);
					}
				}
			}
		}
	}

	for(i=0;i<pjgRow;i++){
		for(j=0;j<pjgCol;j++){
			printf("%d",mat[i][j]);
		}
		printf("\n");
	}

	return 0;
};