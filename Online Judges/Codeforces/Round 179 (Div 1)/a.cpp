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

const int maxn = 1e5 + 5;

struct query{
	int l, r, d;
};

int main(){
	int n,m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	ll a[maxn];
	ll tambah[maxn];
	memset(tambah, 0, sizeof tambah);

	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	int cnt[maxn];
	query q[maxn];
	memset(cnt, 0, sizeof cnt);
	for(i=0;i<m;i++){
		scanf("%d %d %d",&q[i].l, &q[i].r, &q[i].d);
		q[i].l--; q[i].r--;
	}
	for(i=0;i<k;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		x--; y--;
		cnt[x]++; cnt[y+1]--;
	}
	for(i=0;i<m;i++){
		if(i){
			cnt[i] += cnt[i-1];
		}
		int kiri = q[i].l, kanan = q[i].r, banyak = q[i].d;
		tambah[kiri] += (ll)banyak*cnt[i];
		tambah[kanan+1] -= (ll)banyak*cnt[i];
	}
	for(i=0;i<n;i++){
		if(i){
			tambah[i] += tambah[i-1];
		}
		a[i] += tambah[i];
		if(i){printf(" ");}
		printf("%lld",a[i]);
	}
	printf("\n");

	return 0;
};