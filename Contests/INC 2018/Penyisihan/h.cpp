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
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
typedef vector<ii> vii;

int cntDigit(ll n){
	int cnt = 0;
	while(n>0){
		cnt++;
		n/=10;
	}
	return cnt;
}

int jumlahDigitGenap(ll n){
	int cnt = 0;
	while(n>0){
		int bil = n%10;
		if(bil!=0){
			if(bil%2 == 0){
				cnt++;
			}
		}
		n/=10;
	}
	return cnt;
}

map<ii,ll> mapper;
map<ii,ll>::iterator it;

ll hitung(ll n){
	ll ans = 0;
	for(it = mapper.begin();it!=mapper.end();it++){
		iii pas = *it;
		// printf("diconsider pas: %lld %lld --> %lld\n",pas.first.first, pas.first.second, pas.second);
		if(pas.first.second <= n){
			ans = pas.second;
		}else{
			break;
		}
	}
	return ans;
}

int main(){
	ll a,b;
	
	int i,j;
	
	
	ll selisih = 4;
	ll awal = 1, akhir = 9;
	ll jumlah = 4;
	mapper[ii(awal,akhir)] = jumlah;
	bool is4 = true;
	ll selisihRange = 9;
	for(i=1;i<=9;i++){
		awal = akhir + 1, akhir = awal + selisihRange;
		if(is4){
			jumlah += 4;
			is4 = false;
		}else{
			jumlah += 5;
			is4 = true;
		}
		mapper[ii(awal,akhir)] = jumlah;
		// printf("yang dimap: %lld %lld ke %lld\n",awal,akhir,jumlah);
	}
	for(i=1;i<=16;i++){
		selisihRange *= 10LL; selisihRange += 9LL;
		selisih *= 10LL; selisih += 4LL;
		jumlah += selisih;
		is4 = false;
		awal = akhir + 1LL; akhir = awal + selisihRange;
		// printf("yang dimap: %lld %lld ke %lld\n",awal,akhir,jumlah);
		mapper[ii(awal, akhir)] = jumlah;
		for(j=1;j<=8;j++){
			awal = akhir + 1, akhir = awal + selisihRange;
			if(is4){
				jumlah += selisih;
				is4 = false;
			}else{
				jumlah += (selisih + 1LL);
				is4 = true;
			}
			mapper[ii(awal,akhir)] = jumlah;
			// printf("yang dimap: %lld %lld ke %lld\n",awal,akhir,jumlah);
		}
	}
	// printf("%lld\n",mapper[ii(100000,199999)]);
	scanf("%lld %lld",&a,&b);
		ll banyak = b - a + 1LL;
		//hitung a;
		ll pengali = 10;
		ll ans = 0;
		int bilAkhirB = b%10;
		a--;
		int bilAkhirA = a%10;
		b/=10LL;
		// printf("b jadi: %lld\n",b);
		int jumlahGenapB = jumlahDigitGenap(b);
		a/=10LL;
		int jumlahGenapA = jumlahDigitGenap(a);
		// printf("b sekarang: %lld\n",b);
		while(b > 0){
			ll bil = b%10;
			bil*=pengali;
			b/=10;
			pengali*=10LL;
			// printf("bil; %lld\n",bil);
			ll hasilHitung = hitung(bil);
			// printf("hasilHitung: %lld\n",hasilHitung);
			ans += hasilHitung;
		}
		// printf("bilAkhirB: %d\n",bilAkhirB);
		for(i=1;i<=bilAkhirB;i++){
			if(i%2==0){ans++;}
		}
		ans += jumlahGenapB;
		// printf("jumlahGenapB: %d\n",jumlahGenapB);
		// printf("ans setelah hitung B: %lld\n",ans);

		pengali = 10;
		ll ans2 = 0;
		while(a > 0){
			ll bil = a%10;
			bil*=pengali;
			a/=10;
			pengali*=10LL;
			// printf("bil: %lld\n",bil);
			ll hasilHitung = hitung(bil);
			// printf("hasilHitung: %lld\n",hasilHitung);
			ans2 += hasilHitung;
			// ans -= hasilHitung;
		}
		// printf("ans2 awal: %lld\n",ans2);
		for(i=1;i<=bilAkhirA;i++){
			// printf("i: %d\n",i);
			if(i%2==0){ans2++;}
		}
		// printf("ans2 jadi: %lld\n",ans2);
		ans -= ans2;
		// printf("ans sekarang: %lld\n",ans);
		
		// printf("ans jadi: %lld\n", ans);
		ans -= jumlahGenapA;
		// printf("setelah dikurang ans jd: %lld\n",ans);

		
		

		printf("%lld %lld\n",banyak-ans,ans);	
	
	

	return 0;
};