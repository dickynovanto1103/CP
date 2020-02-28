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

const int maxn = 302;

int a[maxn][maxn];

int maks[maxn][maxn][maxn];
int minim[maxn][maxn][maxn];

ii query(int node, int l, int r, int i, int j, int row) {
	return ii(maks[row][i][j], minim[row][i][j]);
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int r,c,k;
		scanf("%d %d %d",&r,&c,&k);
		// printf("print mat\n");
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				scanf("%d",&a[i][j]);
				// printf("%d ",a[i][j]);
			}
			for(j=1;j<=c;j++){
				maks[i][j][j] = a[i][j]; minim[i][j][j] = a[i][j];

				for(int l=j+1;l<=c;l++){
					maks[i][j][l] = max(maks[i][j][l-1], a[i][l]);
					minim[i][j][l] = min(minim[i][j][l-1], a[i][l]);
					// printf("i: %d j: %d l: %d maks: %d minim : %d\n",i,j,l,maks[i][j][l],minim[i][j][l]);
				}
			}
		}
		int ans = 0;
		for(i=1;i<=c;i++){
			for(j=i;j<=c;j++){
				int temp = 0;
				for(int l=1;l<=r;l++){
					ii hasil = query(1,1,c,i,j,l);
					// printf("kol awal; %d akhir: %d row: %d\n",i,j,l);
					// printf("hasil: %d %d\n",hasil.first, hasil.second);
					if((hasil.first - hasil.second) <= k){
						temp += (j-i+1);
					}else{
						ans = max(ans, temp);
						temp = 0;
						// break;
					}
				}
				ans = max(ans, temp);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
};