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
typedef pair<ll,int> ii;
typedef vector<ii> vii;

ll a[11];

int n;
int ans[101];

int getMax(ll uang, int angkaNow) {
	ll harga = a[angkaNow];
	int maks = angkaNow;
	for(int i=angkaNow+1;i<=n;i++){
		ll hargaSekarang = a[i];
		uang += harga;
		uang -= hargaSekarang;
		if(uang >= 0){
			maks = i;
		}
		uang += hargaSekarang;
		uang -= harga;
	}
	return maks;
}

ii findMinim() {
	ll minim = a[0];
	int idx = 0;
	for(int i=1;i<=n;i++){
		if(minim >= a[i]){
			minim = a[i];
			idx = i;
		}
	}
	return ii(minim, idx);
}

//write from awal to akhir - 1
void write(ll awal, ll akhir, ll banyakPlat, int angka) {
	ll i;
	if(awal < 50LL) {
		for(i=awal;i<min(akhir, 50LL);i++){
			ans[i] = angka;
		}
	}

	int minAwalDiAkhir = banyakPlat - 50LL;
	ll pengurang = banyakPlat - 100LL;

	if(akhir > minAwalDiAkhir && akhir <= banyakPlat) {
		ll idxAwal = awal - pengurang;
		for(i=max(50LL, idxAwal);i<min(akhir - pengurang,100LL);i++){
			ans[i] = angka;
		}
	}
}

ll getTermurahKedua() {
	if(n == 0){return -1;}
	ll minim = a[1];
	for(int i=1;i<=n;i++){
		minim = min(minim, a[i]);
	}
	return minim;
}

int main(){
	int i,j;
	scanf("%d",&n);
	
	for(i=0;i<=n;i++){
		scanf("%lld",&a[i]);
	}

	ll uang;
	scanf("%lld",&uang);
	ii minim = findMinim();

	ll banyakPlat = uang / minim.first;
	int angkaPertama = minim.second;

	if(banyakPlat == 0){printf("0\n"); return 0;}

	uang %= minim.first;

	bool semuaNol = (angkaPertama == 0 ? true : false);

	if(banyakPlat > 100){
		for(i=0;i<100;i++){
			ans[i] = angkaPertama;
		}
		//handle first 50..then the middles, then the last 50
		ll idx = 0;
		while(true) {
			int angkaGanti = getMax(uang, angkaPertama);
			if(angkaPertama == angkaGanti){
				if(semuaNol){
					ll termurahKedua = getTermurahKedua();
					if(termurahKedua == -1){printf("1\n0\n0\n"); return 0;}
					ll tambahan = ((termurahKedua + a[0] - 1) / a[0]) - 1;
					banyakPlat -= tambahan;
					uang += tambahan*a[0];
					
					if(banyakPlat <= 100) {
						goto here;
					}
					continue;
				} else {
					break;	
				}
				
			}
			if(angkaGanti != 0) {
				semuaNol = false;
			}

			ll selisih = a[angkaGanti] - a[angkaPertama];
			ll banyakGanti = uang / selisih;
			ll sisaUang = uang % selisih;

			ll awal = idx;
			ll akhir = idx + banyakGanti;

			write(awal, akhir, banyakPlat, angkaGanti);

			idx = akhir;
			uang = sisaUang;

			if(idx >= banyakPlat){break;}
		}

		if(semuaNol) {
			printf("1\n0\n0\n");
			return 0;
		}

		printf("%lld\n",banyakPlat);
		for(i=0;i<50;i++){printf("%d",ans[i]);}
		printf("\n");
		for(i=50;i<100;i++){printf("%d",ans[i]);}
		printf("\n");
	}else{
		here:;

		for(i=0;i<banyakPlat;i++){
			ans[i] = angkaPertama;
		}
		for(i=0;i<banyakPlat;i++){
			int angkaGanti = getMax(uang, ans[i]);
			if(angkaGanti == ans[i]){
				if(semuaNol){
					ll termurahKedua = getTermurahKedua();
					if(termurahKedua == -1){printf("1\n0\n0\n"); return 0;}
					ll tambahan = ((termurahKedua + a[0] - 1) / a[0]) - 1;
					banyakPlat -= tambahan;
					uang += tambahan*a[0];
					if(banyakPlat <= 100) {
						goto here;
					}
					continue;
				} else {
					break;	
				}
			}

			if(angkaGanti != 0) {
				semuaNol = false;
			}

			uang += a[ans[i]];

			ans[i] = angkaGanti;
			uang -= a[ans[i]];
		}

		if(semuaNol) {
			printf("1\n0\n0\n");
			return 0;
		}

		printf("%lld\n",banyakPlat);
		if(banyakPlat <= 50) {
			for(i=0;i<banyakPlat;i++){printf("%d",ans[i]);}
			printf("\n");
			for(i=0;i<banyakPlat;i++){printf("%d",ans[i]);}
			printf("\n");	
		}else{
			for(i=0;i<50;i++){printf("%d",ans[i]);}
			printf("\n");
			for(i=banyakPlat - 50;i<banyakPlat;i++){printf("%d",ans[i]);}
			printf("\n");
		}
		
	}

	


	return 0;
};