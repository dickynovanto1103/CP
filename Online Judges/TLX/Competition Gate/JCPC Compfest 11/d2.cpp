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

int main(){
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	int mat[21][21];
	memset(mat, 0, sizeof mat);
	for(i=0;i<q;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a--; b--;
		if(a > b){swap(a,b);}
		if(a == b){continue;}
		mat[a][b] ^= c;
	}
	// for(i=0;i<n;i++){
	// 	for(j=0;j<n;j++){
	// 		printf("%d ",mat[i][j]);
	// 	}
	// 	printf("\n");
	// }
	int k;
	bool change = false;
	do{
		change = false;

		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				int el = mat[i][j];
				if(el == 0){continue;}
				for(k=0;k<n;k++){
					if(el == mat[i][k] && k != j){
						if(j < k){
							mat[j][k] = el;
						}else{
							mat[k][j] = el;
						}
						change = true;
						mat[i][j] = 0; mat[i][k] = 0;
						goto here;
					}
					if(el == mat[k][j] && k != i) {
						if(i < k) {
							mat[i][k] = el;
						}else{
							mat[k][i] = el;
						}
						change = true;
						mat[i][j] = 0; mat[k][j] = 0;
						goto here;
					}
					if(el == mat[j][k] && k != i) {
						if(i < k) {
							mat[i][k] = el;
						}else{
							mat[k][i] = el;
						}
						change = true;
						mat[i][j] = 0; mat[j][k] = 0;
						goto here;
					}
					if(el == mat[k][i] && k != j){
						if(j < k){
							mat[j][k] = el;
						}else{
							mat[k][j] = el;
						}
						change = true;
						mat[i][j] = 0; mat[k][i] = 0;
						goto here;
					}
				}
			}
		}
		here:;
	}while(change);
	int ans = 0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(mat[i][j]){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
};