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

ll kapasitas[]={0,100,10000,1000000, inf};
ll harga[]={2,3,5,7};


ll priceToWatt(ll a){
	ll sum = 0;
	int i;
	for(i=0;i<3;i++){
		ll biaya = (harga[i]*(kapasitas[i+1]-kapasitas[i]));
		a-=biaya;
		if(a<0){a+=biaya; sum+=(a/harga[i]); a = 0; break;}
		else{sum+=(kapasitas[i+1]-kapasitas[i]);}
		//printf("sum\n");
	}
	if(a>0){
		sum+=(a/harga[i]);
	}
	return sum;
}

ll wattToPrice(ll a){
	ll sum = 0;
	int i;
	for(i=0;i<4;i++){
		if(!a){break;}
		ll banyakWatt = (kapasitas[i+1]-kapasitas[i]);
		if(a-banyakWatt>=0){a-=banyakWatt;}
		else{banyakWatt = a; a=0;}
		sum+=banyakWatt*harga[i];
	}
	return sum;
}

int main() {
	ll a,b;
	while(scanf("%lld %lld",&a,&b),(a||b)){
		ll watt = priceToWatt(a);
		//printf("watt: %lld\n",watt);
		ll kiri = 0, kanan = watt, mid;
		ll totalWatt = watt;
		//ll price = wattToPrice(10123);
		//printf("price: %lld\n",price);
		//printf("a: %lld\n",a);
		ll hargafix;
		while(kiri<=kanan){
			mid = (kiri+kanan)/2;
			ll price1 = wattToPrice(mid);
			hargafix = price1;
			ll tetangga = totalWatt - mid;
			ll price2 = wattToPrice(tetangga);
			ll selisih = price2-price1;
			//printf("mid: %lld\n",mid);
			//printf("price1: %lld price2: %lld selisih: %lld\n",price1,price2,selisih);
			if(selisih==b){hargafix = price1; break;}
			else if(selisih<b){kanan = mid-1;}
			else{kiri = mid+1;}
		}
		printf("%lld\n",hargafix);

		//binser di watt
	}
	return 0;
}