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

const int maxn = 1e3 + 3;

int a[maxn][maxn];
int p[maxn][maxn];
int r,c;
bool can(int mid) {
	int i,j;
	for(i=mid;i<=r;i++){
		for(j=mid;j<=c;j++){
			int sum = p[i][j] - p[i][j-mid] - p[i-mid][j] + p[i-mid][j-mid];
			if(sum <= 1){return true;}
		}
	}
	return false;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&r,&c);
		memset(p, 0, sizeof p);
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				register char c;
				while(c = getchar(), c!= '0' && c!='1');
				a[i][j] = c - '0';
				// printf("a[%d][%d]: %d\n",i,j);
				// scanf("%d",&a[i][j]);
				p[i][j] = a[i][j];
				p[i][j] += p[i-1][j];
				p[i][j] += p[i][j-1];
				p[i][j] -= p[i-1][j-1];
			}
		}
		// for(i=1;i<=r;i++){
		// 	for(j=1;j<=c;j++){
		// 		printf("%3d",p[i][j]);
		// 	}
		// 	printf("\n");
		// }

		int kiri = 1, kanan = min(r,c), mid, ans = -1;
		while(kiri <= kanan){
			mid = (kiri + kanan)/2;
			if(can(mid)){
				ans = mid;
				kiri = mid+1;
			}else{
				kanan = mid-1;
			}
		}
		assert(ans != -1);
		printf("%d\n",ans);

	}
	return 0;
};