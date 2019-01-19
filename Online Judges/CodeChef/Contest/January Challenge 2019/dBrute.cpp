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

vi listBil;

void generate(int a, int b, int c){
	int i;
	for(i=0;i<a;i++){listBil.pb(1);}
	for(i=0;i<b;i++){listBil.pb(2);}
	for(i=0;i<c;i++){listBil.pb(3);}
}

int mat[50][50];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

bool isExistDouble(int n, int m) {
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			set<int> s;
			for(int k=0;k<4;k++){
				int xbaru = i + dx[k], ybaru = j + dy[k];
				if(xbaru >= 0 && xbaru<n && ybaru >= 0 && ybaru<m){
					if(s.count(mat[xbaru][ybaru])){return true;}
					s.insert(mat[xbaru][ybaru]);
				}
			}
			
		}
	}
	return false;
}

void permute(int n, int m) {
	int i,j;
	do{
		// printf("listBil:\n");
		// for(i=0;i<listBil.size();i++){
		// 	printf("%d ",listBil[i]);
		// }
		// printf("\n");
		int idx = 0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				mat[i][j] = listBil[idx++];
			}
		}
		// for(i=0;i<n;i++){
		// 	for(j=0;j<m;j++){
		// 		printf("%d ",mat[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");

		if(!isExistDouble(n,m)){
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					printf("%d ",mat[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}while(next_permutation(listBil.begin(), listBil.end()));
}

int main(){
	int i,j,k;
	int n,m;
	scanf("%d %d",&n,&m);
	int kali = n*m;
	// printf("kali %d\n",kali);
	for(i=1;i<=kali;i++){
		for(j=1;j<=kali;j++){
			for(k=1;k<=kali;k++){
				if(i + j + k  == kali){
					// printf("i: %d j: %d k: %d\n",i,j,k);
					listBil.clear();
					generate(i,j,k);
					permute(n,m);
				}	
			}
		}
	}



	return 0;
};