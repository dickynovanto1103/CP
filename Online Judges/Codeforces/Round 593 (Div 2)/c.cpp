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

int main(){
	int n,i,j;
	scanf("%d",&n);
	int mat[302][302];
	int kuadrat = n*n;
	int off = 0;
	bool toggle = false;
	for(j=1;j<=n;j++){
		if(toggle){
			for(i=1;i<=n;i++){
				mat[i][j] = off+i;
			}
		}else{
			for(i=1;i<=n;i++){
				mat[n-i+1][j] = off+i;
			}
		}
		toggle = !toggle;

		off += n;
		// printf("off: %d\n",off);
	}
	for(j=1;j<=n;j++){
	
		for(i=1;i<=n;i++){
			if(i>1){printf(" ");}
			printf("%d",mat[j][i]);
		}
		printf("\n");
	}
	// int minim = inf;
	// for(i=1;i<=n;i++){
	// 	for(j=1;j<=n;j++){
	// 		int cnt = 0;
	// 		if(i == j){continue;}
	// 		for(int k=1;k<=n;k++){
	// 			for(int l=1;l<=n;l++){
	// 				if(mat[i][k] > mat[j][l]){
	// 					cnt++;
	// 				}
	// 			}
	// 		}
	// 		// printf("cnt: %d\n",cnt);
	// 		minim = min(minim, cnt);
	// 	}
	// }
	// printf("%d\n",minim);
	return 0;
};