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

vector<vi> AdjList;

int main(){
	AdjList.assign(2,vi());
	string kata, dum;
	ll k,q,i,j;
	cin>>dum;
	cin>>kata;
	ll pjg = kata.length();
	char lastChar = kata[pjg-1];
	for(i=0;i<pjg;i++){
		if(kata[i]=='A'){
			AdjList[0].pb(i);
		}else{
			AdjList[1].pb(i);
		}
	}


	scanf("%lld %lld",&k,&q);

	ll n = k*pjg + 1LL;
	ll x = (n-1LL)/(pjg);


	ll titikTemu = 1LL+((ll)AdjList[1].size()*x);

	// printf("n: %lld x: %lld titikTemu: %lld\n",n,x,titikTemu);

	while(q--){
		ll l,r;
		scanf("%lld %lld",&l,&r);
		if(titikTemu>=l && titikTemu<=r){
			printf("%lld\n",n);
		}else{
			ll banyakKeKiri = AdjList[0].size(), banyakKeKanan = AdjList[1].size();
			ll kiri = 1, kanan = n;
			ll banyakTumpuk = 1;
			if(r < titikTemu){
				ll loop = (r - kiri) / banyakKeKanan;
				kiri += (loop*banyakKeKanan);
				banyakTumpuk += (loop*pjg);
				ll selisihBaru = (r+1) - kiri;
				//cari di selisih
				ll idxB = AdjList[1][selisihBaru-1];
				ll langkah = idxB;
				// printf("banyakTumpuk: %lld selisihBaru: %lld idxB: %lld langkah: %lld\n",banyakTumpuk, selisihBaru, idxB, langkah);
				banyakTumpuk += langkah;
				printf("%lld\n",banyakTumpuk);
			}
			if(l > titikTemu){
				ll loop = (kanan - l) / banyakKeKiri;
				kanan -= (loop*banyakKeKiri);
				banyakTumpuk += (loop*pjg);
				ll selisihBaru = (kanan) - (l-1);
				ll idxA = AdjList[0][selisihBaru-1];
				ll langkah = idxA;
				banyakTumpuk += langkah;
				printf("%lld\n",banyakTumpuk);
			}
			//coba dulu yang dikurang sebanyak k-1
			// ll kiri = titikTemu, kanan = titikTemu;
			// if(lastChar == 'A'){
			// 	banyakKeKanan
			// }

			// //bagi 2 kasus
			// ll banyakKeKiri = AdjList[1].size();
			// ll banyakKeKanan = AdjList[0].size();
			// ll kiri = titikTemu, kanan = titikTemu;
			// ll banyakTumpuk = n;
			// if(r<titikTemu){
			// 	ll selisih = titikTemu - (r+1);
			// 	ll loop = selisih / banyakKeKiri;
			// 	kiri -= (loop*banyakKeKiri);
			// 	banyakTumpuk -= (loop*pjg);
			// 	ll selisihBaru = kiri - (r);
			// 	printf("loop: %lld kiri jd: %lld\n",loop,kiri);
			// 	if(selisihBaru==0){
			// 		printf("%lld\n",banyakTumpuk);
			// 	}else{
			// 		ll idxTerakhirB;
			// 		if(lastChar=='B'){
			// 			idxTerakhirB = AdjList[1][AdjList[1].size()-selisihBaru-1];
			// 		}else{
			// 			idxTerakhirB = AdjList[1][AdjList[1].size()-selisihBaru];
			// 		}
			// 		selisih = (pjg-1) - idxTerakhirB;

			// 		banyakTumpuk -= selisih;
			// 		printf("selisihBaru: %lld\n",selisihBaru);
			// 		printf("banyakKeKiri: %lld idxTerakhirB: %lld selisih: %lld\n",banyakKeKiri,idxTerakhirB,selisih);
			// 		printf("%lld\n",banyakTumpuk);
			// 	}
			// }
			// if(l>titikTemu){
			// 	ll selisih = (l-1) - (titikTemu);
			// 	ll loop = selisih / banyakKeKanan;
			// 	kanan += (loop*banyakKeKanan);
			// 	banyakTumpuk -= (loop*pjg);
			// 	ll selisihBaru = (l) - (kanan);
			// 	printf("loop: %lld kiri jd: %lld selisihBaru: %lld\n",loop,kiri, selisihBaru);
			// 	if(selisihBaru==0){
			// 		printf("%lld\n", banyakTumpuk);
			// 	}else{
			// 		ll idxTerakhirA;
			// 		if(lastChar == 'A'){
			// 			idxTerakhirA = AdjList[0][AdjList[0].size() - selisihBaru - 1];
			// 			selisih = 
			// 		}else{
			// 			idxTerakhirA = AdjList[0][AdjList[0].size() - selisihBaru];
			// 		}
			// 		selisih = (pjg-1) - idxTerakhirA;
			// 		printf("idxTerakhirA: %lld banyakKeKanan: %lld selisih: %lld\n",idxTerakhirA, banyakKeKanan, selisih);
			// 		banyakTumpuk -= selisih;
			// 		printf("%lld\n", banyakTumpuk);
			// 	}
			// }
		}

	}
	return 0;
};