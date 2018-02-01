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

int banyakDigit(ll n){
	int cnt = 0;
	while(n>0){
		n/=10;
		cnt++;
	}
	return cnt;
}

int main(){
	ll n,i,j;
	scanf("%lld",&n);
	int digit = banyakDigit(n);
	ll angka = 0;
	for(i=0;i<digit;i++){
		angka*=10;
		angka+=9;
	}

	while((n+n-1)<angka){
		angka/=10;
	}
	//printf("angka: %lld\n",angka);
	int jumlahDigitAngka = banyakDigit(angka);
	ll penambahan = 1LL*(ll)pow(10,jumlahDigitAngka);
	//printf("penambahan: %lld\n",penambahan);
	ll angkaAwal = angka;
	ll ans = 0;
	for(i=0;i<10;i++){
		angka=angkaAwal + (i*penambahan);
		if((n+n-1)<angka){break;}
		ll start, akhir;
		if(angka>n){
			start = angka-n;
			akhir = angka-start;
		}else{
			start = 1;
			akhir = angka-start;
		}
		//printf("angka: %lld start: %lld akhir: %lld\n",angka, start,akhir);
		ans+=((akhir-start+1)/2);
		

	}
	printf("%lld\n",ans);


	return 0;
};