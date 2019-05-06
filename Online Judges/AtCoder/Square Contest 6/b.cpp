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

const int maxn = 35;

void minim(ll &a, ll b){
	a = min(a, b);
}

void maks(ll &a, ll b){
	a = max(a, b);
}

ll a[maxn], b[maxn];
int n;

ll countMasuk(ll mid) {
	ll sum = 0;
	for(int i=0;i<n;i++){
		sum += abs(mid - a[i]);
	}
	return sum;
}

ll countKeluar(ll mid) {
	ll sum = 0;
	for(int i=0;i<n;i++){
		sum += abs(mid - b[i]);
	}
	return sum;
}

int main(){
	int i,j;
	
	scanf("%d",&n);
	ll sum = 0;
	ll minMasuk = inf, maksMasuk = 1;
	ll minKeluar = inf, maksKeluar = 1;
	for(i=0;i<n;i++){
		scanf("%lld %lld",&a[i],&b[i]); sum += (b[i] - a[i]);
		minim(minMasuk, a[i]); minim(minKeluar, b[i]);
		maks(maksMasuk, a[i]); maks(maksKeluar, b[i]);
	}

	//binser 2 kali..buat yg masuk dan yg keluar
	ll kiri = minMasuk, kanan = maksMasuk, mid, ans = -1;
	while(kiri <= kanan) {
		mid = (kiri + kanan)/2;
		ll ans1 = countMasuk(mid), ans2 = countMasuk(mid-1), ans3 = countMasuk(mid+1);
		if(ans1 > ans2) {
			ans = ans2;
			kanan = mid - 1;
		}else{
			ans = ans1;
			kiri = mid+1;
		}
	}

	kiri = minKeluar, kanan = maksKeluar;
	ll jawab = -1;
	while(kiri <= kanan) {
		mid = (kiri + kanan)/2;
		ll ans1 = countKeluar(mid), ans2 = countKeluar(mid-1), ans3 = countKeluar(mid+1);
		if(ans1 > ans2) {
			jawab = ans2;
			kanan = mid - 1;
		}else{
			jawab = ans1;
			kiri = mid+1;
		}
	}	
	// printf("sum: %lld \n", );
	sum += ans; sum += jawab;
	printf("%lld\n",sum);

	return 0;
};