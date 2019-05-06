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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int cnt[1010];

int bilGanjil;

bool isValidGenap() {
	for(int i=1;i<=1000;i++){
		if(cnt[i]%4 != 0){return false;}
	}
	return true;
}

bool isValidGanjil() {
	int ganjil = 0;
	for(int i=1;i<=1000;i++){
		if(cnt[i] & 1){ganjil++; bilGanjil = i;}
	}
	return ganjil == 1;
}

int mat[24][24];

int mirror(int n, int bil) {
	return n - bil - 1;
}

void place(int r, int c, int r1, int c1, int bil) {
	mat[r][c] = bil;
	mat[r][c1] = bil;
	mat[r1][c] = bil;
	mat[r1][c1] = bil;
	cnt[bil] -= 4;
}

bool isValid;

void construct(int n) {
	int i,j;
	vi list4;
	for(i=1;i<=1000;i++){
		if(cnt[i] > 2 && cnt[i] % 2 == 0){
			list4.pb(i);
		}
	}
	for(i=0;i<n/2;i++){
		for(j=0;j<n/2;j++) {
			int row = mirror(n, i), col = mirror(n, j);

			if(list4.empty()){
				isValid = false; return;
			}
			else{
				int bil = list4.back();
				place(i,j,row, col, bil);
				if(cnt[bil] < 4) {list4.pop_back();}
			}
		}
	}
}

int main(){
	int n,i,j;
	isValid = true;
	scanf("%d",&n);
	for(i=0;i<n*n;i++){
		int bil;
		scanf("%d",&bil);
		cnt[bil]++;
	}

	if(n % 2 == 0){
		if(isValidGenap()){
			
			//construct
			construct(n);
			if(!isValid){printf("NO\n"); return 0;}
			printf("YES\n");
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(j){printf(" ");}
					printf("%d",mat[i][j]);
				}
				printf("\n");
			}
		}else{
			printf("NO\n");
		}
	}else{
		if(isValidGanjil()) {
			//cek lagi
			mat[n/2][n/2] = bilGanjil;
			cnt[bilGanjil]--;
			construct(n);
			if(!isValid){
				printf("NO\n"); return 0;
			}
			vi list2;
			for(i=1;i<=1000;i++){
				if(cnt[i] > 0 && cnt[i]%2 == 0){list2.pb(i);}
			}
			for(i=0;i<n/2;i++){
				int row = mirror(n, i);
				if(list2.empty()){printf("NO\n"); return 0;}
				else{
					int bil = list2.back();
					// printf("itung row i: %d mirror %d bil: %d\n",i,row, bil);
					mat[i][n/2] = mat[row][n/2] = bil;
					cnt[bil] -= 2;
					if(!cnt[bil]){list2.pop_back();}
				}
			}
			for(j=0;j<n/2;j++){
				int col = mirror(n, j);
				if(list2.empty()){printf("NO\n"); return 0;}
				else{
					int bil = list2.back();
					// printf("itung col j: %d mirror %d bil: %d\n",j,col, bil);
					mat[n/2][j] = mat[n/2][col] = bil;
					cnt[bil] -= 2;
					if(!cnt[bil]){list2.pop_back();}
				}	
			}
			printf("YES\n");
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(j){printf(" ");}
					printf("%d",mat[i][j]);
				}
				printf("\n");
			}
		}else{
			printf("NO\n");
		}
	}

	return 0;
};