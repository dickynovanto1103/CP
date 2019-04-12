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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int mat[11][8];

	int tc,i,j;
	for(i=0;i<10;i++){
		for(j=0;j<7;j++){
			int &a = mat[i][j];
			if(i == 0){
				if(j == 0 || j == 1 || j == 2 || j == 4 || j == 5 || j == 6){a = 1;}
				else{a = 0;}
			}
			else if(i == 1){
				if(j == 2 || j == 6){mat[i][j] = 1;}
				else{mat[i][j] = 0;}
			}else if(i == 2){
				if(j >=1 && j<=5){a = 1;}
				else{a = 0;}
			}else if(i == 3){
				if(j == 1 || j == 2 || j == 3 || j == 5 || j == 6){a = 1;}
				else{a = 0;}
			}else if(i == 4){
				if(j == 0 || j == 2 || j == 3 || j == 6){a = 1;}
				else{a = 0;}
			}else if(i == 5){
				if(j == 0 || j == 1 || j == 3 || j == 5 || j == 6){a = 1;}
				else{a = 0;}
			}else if(i == 6){
				if(j == 0 || j == 1 || (j >= 3 && j<=6)){a = 1;}
				else{a = 0;}
			}else if(i == 7){
				if(j == 1 || j == 2 || j == 6){a = 1;}
				else{a = 0;}
			}else if(i == 8){
				a = 1;
			}else if(i == 9){
				if(j!=4){a = 1;}
				else{a = 0;}
			}
			// printf("%d ",mat[i][j]);
		}
		// printf("\n");
	}
	
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		int a[110], x[110];
		for(i=0;i<n;i++){scanf("%d %d",&x[i],&a[i]);}
		// printf("%d %d\n",cnt[0], a[0]);
		int minim = 9, maks = 0;
		for(i=0;i<(1<<7);i++){
			vi listBil;
			int cntMati = 0;
			for(j=0;j<7;j++){
				if((1<<j) & i){listBil.pb(1);}
				else{listBil.pb(0); cntMati++;}
			}
			bool valid = true;
			for(j=0;j<n;j++){
				//cek kebenaran
				int bil = x[j];
				//hitung jumlah nyala
				int cnt = 0;
				for(int k=0;k<7;k++){
					// if(mat[bil][k] == 1 && listBil[k] == 0){valid = false; goto here;}
					if(mat[bil][k] == 1 && listBil[k] == 1){cnt++;}
				}
				if(cnt != a[j]){valid = false; break;}
				// else{printf("valid untuk bil: %d a[%d]: %d\n",bil, j, a[j]);}
			}
			here:;
			if(valid){
				// printf("i: %d cntMati: %d\n",i,cntMati);
				minim = min(minim, cntMati);
				maks = max(maks, cntMati);
			}
		}
		if(minim == 9 && maks == 0){printf("invalid\n");}
		else{printf("%d %d\n",minim, maks);}
		

	}
	return 0;
};