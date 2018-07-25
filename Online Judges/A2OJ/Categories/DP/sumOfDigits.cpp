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

ll dp[15];

ll power(ll a, ll b){
	if(b==0){return 1;}
	else{
		if(b%2==1){
			return a*power(a,b-1);
		}else{
			ll temp = power(a,b/2);
			return temp*temp;
		}
	}
}

vi hasilParse;

ll arrJumlah[15];

void parse(int bil){
	hasilParse.clear();
	ll total = 0;
	int idx = 0;
	while(bil>0){
		int angka = bil%10;

		hasilParse.pb(angka);
		bil/=10;
	}

	for(int i=hasilParse.size() - 1;i>=0;i--){
		total = 0;
		for(int j=i;j>=0;j--){
			int bil = hasilParse[j];
			total*=10; total+=bil;
		}
		arrJumlah[i] = total;
	}
}

ll hitung(){
	ll jumlah2 = 0;
	for(int i=0;i<hasilParse.size();i++){
		int angka = hasilParse[i];
		// printf("angka: %d\n",angka);
		ll total = ((angka*(angka+1))/2);
		ll penambahan;
		if(i==0){
			jumlah2+=total;
			penambahan = total;
		}else{
			total = ((angka-1)*(angka))/2;
			penambahan = (total*power(10,i) + dp[i-1]*(angka) + angka);
			penambahan+=(arrJumlah[i-1]*angka);
			jumlah2+=penambahan;
		}
		// printf("penambahan: %lld jumlah2 jd: %lld\n",penambahan, jumlah2);
	}
	return jumlah2;
}

int main(){
	int a,b;
	dp[0] = 45;
	for(int i=1;i<=10;i++){
		dp[i] = dp[i-1]*10LL + 45LL*power(10,i);
	}

	while(scanf("%d %d",&a,&b)){
		if(a==-1 && b==-1){break;}
		parse(b);
		// for(int i=0;i<hasilParse.size();i++){
		// 	printf("arrJumlah[%d]: %d\n",i,arrJumlah[i]);
		// }

		ll jumlah2 = hitung();
		
		ll sum = jumlah2;
		if(a!=0){
			parse(a-1);
			ll jumlah = hitung();
			sum-=jumlah;
		}
		printf("%lld\n",sum);
	}
	
	
	//jumlah b dulu
	

	return 0;
};