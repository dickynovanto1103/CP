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

struct barang{
	int waktu, nilai;
};

bool cmp(barang a, barang b){
	if(a.waktu == b.waktu){
		return a.nilai > b.nilai;
	}
	return a.waktu < b.waktu;
	if(a.nilai == b.nilai){
		return a.waktu < b.waktu;
	}
	return a.nilai > b.nilai;
}

const int maxn = 2010;
ll suffWaktu[maxn];
ll prefNilai[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	barang pas[maxn];
	
	ll sum = 0;
	for(i=0;i<n;i++){
		scanf("%d %d",&pas[i].waktu, &pas[i].nilai);
		sum += (ll)pas[i].nilai;

	}
	sort(pas,pas+n,cmp);
	for(i=0;i<n;i++){
		printf("%d %d\n",pas[i].waktu, pas[i].nilai);
	}
	prefNilai[0] = pas[0].nilai;
	for(i=1;i<n;i++){
		prefNilai[i] = prefNilai[i-1] + pas[i].nilai;
	}
	suffWaktu[n-1] = pas[n-1].waktu;
	for(i=n-2;i>=0;i--){
		suffWaktu[i] = suffWaktu[i+1] + pas[i].waktu;
	}
	ll ans = sum;
	for(i=1;i<n;i++){
		ll minus = prefNilai[i-1];
		ll butuhWaktu = i;
		if(butuhWaktu <= suffWaktu[i]){
			ans = min(ans, sum - minus);
		}
	}
	printf("%lld\n",ans);
	return 0;
};