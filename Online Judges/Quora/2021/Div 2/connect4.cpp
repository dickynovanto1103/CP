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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int a[6][7];

bool checkHorizontal(){
	int i,j;
	// printf("hori\n");
	for(i=0;i<6;i++){
		for(j=0;j<7;j++){
			int col = a[i][j];
			if(col == -1){continue;}
			int cnt = 0;
			for(int k=j;k<j+4;k++){
				if(k >= 7){
					break;
				}
				if(col == a[i][k]){
					cnt++;
				}
			}
			if(cnt == 4){
				return true;
			}
		}
	}
	return false;
}

bool checkVertical(){
	int i,j;
	// printf("verti\n");
	for(i=0;i<6;i++){
		for(j=0;j<7;j++){
			int col = a[i][j];
			if(col == -1){continue;}
			int cnt = 0;
			for(int k=i;k<i+4;k++){
				if(k >= 6){
					break;
				}
				if(col == a[k][j]){
					cnt++;
				}
			}
			if(cnt == 4){
				return true;
			}
		}
	}
	return false;
}

bool checkDiagonalKananBawah() {
	int i,j;
	// printf("kanan bawah\n");
	for(i=0;i<6;i++){
		for(j=0;j<7;j++){
			int col = a[i][j];
			if(col == -1){continue;}
			int cnt = 0;
			for(int k=0;k<4;k++){
				int xbaru = i+k;
				int ybaru = j+k;
				if(xbaru >= 0 && xbaru < 6 && ybaru >= 0 && ybaru < 7) {
					if(col == a[xbaru][ybaru]) {
						cnt++;
					}
				}
			}
			if(cnt == 4){
				return true;
			}
		}
	}
	return false;
}

bool checkDiagonalKiriBawah() {
	int i,j;
	// printf("kiri bawah\n");
	for(i=0;i<6;i++){
		for(j=0;j<7;j++){
			int col = a[i][j];
			if(col == -1){continue;}
			int cnt = 0;
			for(int k=0;k<4;k++){
				int xbaru = i+k;
				int ybaru = j-k;
				if(xbaru >= 0 && xbaru < 6 && ybaru >= 0 && ybaru < 7) {
					if(col == a[xbaru][ybaru]) {
						cnt++;
					}
				}
			}
			if(cnt == 4){
				return true;
			}
		}
	}
	return false;
}

void putIntoCol(int col, int numToPut){
	int i,j;
	for(i=5;i>=0;i--){
		if(a[i][col] == -1){
			a[i][col] = numToPut;
			break;
		}
	}
}

void printMat() {
	int i,j;
	for(i=0;i<6;i++){
		for(j=0;j<7;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int n = 42,i,j;
	memset(a, -1, sizeof a);
	int num = 1;
	for(i=0;i<42;i++){
		int col;
		scanf("%d",&col);
		col--;
		putIntoCol(col, num);
		// printMat();
		if(checkHorizontal() || checkVertical() || checkDiagonalKananBawah() || checkDiagonalKiriBawah()) {
			if(num == 1){
				printf("RED %d\n", i+1);
				return 0;
			}else{
				printf("YELLOW %d\n",i+1);
				return 0;
			}
		}
		num = 1 - num;
	}
	printf("DRAW\n");
	
	return 0;
};