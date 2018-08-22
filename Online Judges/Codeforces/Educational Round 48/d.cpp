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

const int maxn = 1e2 + 2;

int main(){
	int n,m;
	int i,j;
	int a[maxn],b[maxn];
	scanf("%d %d",&n,&m);
	int sor = 0;
	for(i=0;i<n;i++){scanf("%d",&a[i]); sor^=a[i];}
	for(i=0;i<m;i++){scanf("%d",&b[i]); sor^=b[i];}
	if(sor!=0){
		printf("NO\n");
	}else{
		int ans[maxn][maxn];
		int row = 0, col = 0;
		int akhirRow = n-1, akhirCol = m-1;
		while(row < n || col < m){
			int nilaiXorKolom = b[col], nilaiXorBaris = a[row];
			for(i=0;i<row;i++){
				nilaiXorKolom^=ans[i][col];
			}
			for(i=0;i<col;i++){
				nilaiXorBaris^=ans[row][i];
			}

			if(row == akhirRow){
				for(i=col;i<m;i++){
					ans[row][i] = b[i];
					for(j=0;j<row;j++){
						ans[row][i] ^= ans[j][i];
					}
				}
				break;
			}

			if(col == akhirCol){
				for(i=row;i<n;i++){
					ans[i][col] = a[i];
					for(j=0;j<col;j++){
						ans[i][col] ^= ans[i][j];
					}
				}
				break;
			}

			for(i=row;i<n;i++){
				ans[i][col] = nilaiXorKolom;
				nilaiXorKolom = 0;
			}

			nilaiXorBaris ^= ans[row][col];
			for(i=col+1;i<m;i++){
				ans[row][i] = nilaiXorBaris;
				nilaiXorBaris = 0;
			}
			row++; col++;
		}
		printf("YES\n");	
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(j){printf(" ");}
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
};