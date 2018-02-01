#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll a[11][1001], ukuran;
ll dist[11][1001];

ll solve(int r, int c){
	if(c==ukuran){
		if(r==9){return 0;}//landing di tempat yang benar;
		else{return inf;}
	}
	if(r<0 || r>9){return inf;}//out of bound
	if(dist[r][c]!=inf){return dist[r][c];}
	ll ans;
	ans=min(20-a[r][c]+solve(r+1,c+1), min(30-a[r][c]+solve(r,c+1),60-a[r][c]+solve(r-1,c+1)));
	//printf("di r: %d c: %d ans: %lld\n",r,c,ans);
	return dist[r][c] = min(dist[r][c], ans);
}

int main() {
	int tc,n,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		ukuran = (ll)n/100;
		for(i=0;i<10;i++){
			for(j=0;j<ukuran;j++){
				scanf("%lld",&a[i][j]);
				dist[i][j] = inf;//inisialisasi
			}
		}
		ll ans = solve(9,0);//row column
		printf("%lld\n\n",ans);
	}
	return 0;
}