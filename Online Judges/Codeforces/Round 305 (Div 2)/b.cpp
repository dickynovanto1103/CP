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

const int maxn = 501;

int main(){
	int n,m,i,j,q;
	scanf("%d %d %d",&n,&m,&q);
	int a[maxn][maxn];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int cnt[maxn];
	memset(cnt, 0, sizeof cnt);
	for(i=0;i<n;i++){
		int ans = 0;
		for(j=0;j<m;j++){
			if(a[i][j] == 0){
				cnt[i] = max(cnt[i], ans);
				ans = 0;
			}else{
				ans++;
			}
		}
		cnt[i] = max(cnt[i], ans);
	}

	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		x--; y--;
		a[x][y] = 1 - a[x][y];
		int ans = 0, banyak1Berurut = 0;
		for(j=0;j<m;j++){
			if(a[x][j] == 0){
				banyak1Berurut = max(banyak1Berurut, ans);
				ans = 0;
			}else{
				ans++;
			}
		}
		banyak1Berurut = max(banyak1Berurut, ans);
		cnt[x] = banyak1Berurut;
		ans = 0;
		for(i=0;i<n;i++){
			ans = max(ans, cnt[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
};