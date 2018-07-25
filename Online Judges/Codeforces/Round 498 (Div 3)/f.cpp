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

const int maxn = 25;

ll a[maxn][maxn];
map<ll, ll> cnt[maxn][maxn];
ll batasTengah;

int n,m;
ll k;

void dfsKiriAtas(int x, int y, ll sor){
	int jumlah = x+y;
	if(jumlah>batasTengah){return;}
	if(x>n || y>m){return;}

	sor^=a[x][y];
	if(jumlah==batasTengah){
		cnt[x][y][sor]++;	
	}

	dfsKiriAtas(x,y+1,sor);
	dfsKiriAtas(x+1,y,sor);
}

ll total;

void dfsKananBawah(int x, int y, ll sor){
	int jumlah = x+y;

	if(x<0 || y<0){return;}

	if(jumlah==batasTengah){
		ll diharapkan = sor^k;
		total+=cnt[x][y][diharapkan];
		return;
	}

	sor^=a[x][y];
	dfsKananBawah(x-1, y, sor);
	dfsKananBawah(x,y-1,sor);
}

int main(){
	
	int i,j;
	scanf("%d %d %lld",&n,&m,&k);
	batasTengah = (n+m)/2 - 1;
	// printf("n: %d m: %d k: %lld\n",n,m,k);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%lld",&a[i][j]);
		}
	}

	dfsKiriAtas(0,0,0);
	dfsKananBawah(n-1,m-1,0);
	printf("%lld\n",total);
	return 0;
};