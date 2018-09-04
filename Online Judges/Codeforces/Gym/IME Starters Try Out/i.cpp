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

int main(){
	int n,i,j,k,q;
	scanf("%d %d %d",&n,&k,&q);

	while(q--){
		int c,d;
		scanf("%d %d",&c,&d);
		int selisih = d;
		int bilPertama = k%n;
		if(c == 1 && d == 0){
			printf("1\n");
			continue;
		}

		int hasilMod = selisih%bilPertama;
		if(hasilMod == 0){
			//cari berapa iterasi ke bil itu
			ll tambahan = selisih/bilPertama;
			printf("tambahan: %lld\n",tambahan);
			int idxSekarang = 1 + tambahan;
			ll selisihIdx = idxSekarang - tambahan;
			printf("selisihIdx: %lld\n", selisihIdx);

			ll ans = selisihIdx / n;
			ans = 1;
			if(selisihIdx % n){
				ans++;
			}
			printf("%lld\n",ans);
			continue;
		}
		printf("bilPertama: %d hasilMod: %d\n",bilPertama, hasilMod);
		//harus siklus sebanyak hasilMod
		int iterasi = n/bilPertama;
		int palingAtas = bilPertama*iterasi;
		int selanjutnya = (palingAtas + k) %n;
		int selisihDenganSelanjutnya = selanjutnya;
		ll penambahan = (((ll)selisihDenganSelanjutnya%n)*(ll)(iterasi % n))%n;
		ll next = penambahan;
		ll ans = iterasi*hasilMod;
		ll harapan = d;
		if(harapan < next){
			harapan += n;
			ll beda = harapan - next;
			ll iterasiTambahan = beda / bilPertama;
			ans += iterasiTambahan;
		}
		printf("%lld\n",ans);
	}
	return 0;
};