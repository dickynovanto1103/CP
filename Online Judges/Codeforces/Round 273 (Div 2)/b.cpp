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
	ll n,m,i,j;
	scanf("%lld %lld",&n,&m);
	ll banyakAnggotaMaks = n-(m-1);
	ll maks = (banyakAnggotaMaks*(banyakAnggotaMaks-1))/2LL;
	ll minim;
	ll banyakKelompokRata = m-(n%m);
	ll banyakKelompokTidakRata = n%m;
	ll anggotaKelompokRata = n/m;
	ll anggotaKelompokTidakRata = anggotaKelompokRata+1;
	minim = 0;
	// printf("banyakKelompokRata: %lld banyakKelompokTidakRata: %lld\n",banyakKelompokRata,banyakKelompokTidakRata);
	// printf("anggotaKelompokRata: %lld\n", anggotaKelompokRata);
	ll banyak1 = (anggotaKelompokRata*(anggotaKelompokRata-1))/2LL;
	banyak1*=banyakKelompokRata;

	ll banyak2 = (anggotaKelompokTidakRata*(anggotaKelompokTidakRata-1))/2LL;
	banyak2*=(banyakKelompokTidakRata);
	minim=banyak1+banyak2;

	printf("%lld %lld\n",minim,maks);
	return 0;
};