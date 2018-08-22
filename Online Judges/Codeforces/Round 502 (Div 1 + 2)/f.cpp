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

const int maxn = 17330;
const ll mod = 1LL<<32LL;
bool isPrime[maxn + 2];
int prime[1995];
bool apakahPrima[1000001];
ll n,a,b,c,d;

void sieve(int n){
	int i,j;
	isPrime[0] = isPrime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isPrime[i]){
			for(j=i*i;j<=n;j+=i){
				isPrime[j] = false;
			}
		}
	}
}

int main(){
	ll i,j;
	memset(isPrime, true, sizeof isPrime);
	sieve(maxn);
	int cnt = 0;
	scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);

	for(i=2;i<=maxn;i++){
		if(isPrime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}
	ll ans = 0;
	//sieve sebanyak 300 kali
	int panjang = 1e6;

	for(i=0;i<300;i++){
		int bawah = (i*panjang)+1, atas = (i+1)*panjang;
		if(bawah > n){break;}
		// printf("bawah: %d atas: %d\n",bawah,atas);
		int offset = bawah;
		memset(apakahPrima, true, sizeof apakahPrima);
		if(i == 0){
			apakahPrima[0] = false;
		}
		for(j=0;j<cnt;j++){
			int prima = prime[j];
			// printf("prima: %d\n",prima);
			if(prima*prima > atas){break;}
			int batasBawah = (bawah/prima)*prima;
			if(batasBawah < bawah){batasBawah+=prima;}
			if(i == 0){
				batasBawah += prima;
			}
			for(int k=batasBawah;k<=atas;k+=prima){
				apakahPrima[k - offset] = false;
				// printf("k - offset: %lld\n",k-offset);
			}
		}
		//udah dapet primanya semua
		for(j=bawah;j<=atas;j++){
			// printf("j: %lld\n",j);
			if(apakahPrima[j - offset]){
				//cek dari j^1..j^2..dst..hitung koefisien
				//tentukan nilai f
				// printf("j: %d\n",j);
				ll bil1 = ((((a%mod*j%mod)%mod)*(j%mod))%mod*(j%mod))%mod;
				ll bil2 = (((b%mod)*(j%mod))%mod*(j%mod))%mod;
				ll bil3 = ((c%mod)*(j%mod))%mod;
				ll f = bil1 + bil2 + bil3 + d;
				f %= mod;
				ll nilaiPrimaSekarang = j;
				ll totalKoef = 0;
				for(int k=0;;k++){
					//hitung banyak nilaiPrimaSekarang
					// printf("nilaiPrimaSekarang: %lld\n",nilaiPrimaSekarang);
					totalKoef += (n/nilaiPrimaSekarang);
					totalKoef %= mod;
					nilaiPrimaSekarang*=j;
					if(nilaiPrimaSekarang > n){
						break;
					}
				}
				ans += ((f%mod)*(totalKoef%mod))%mod;
				ans %= mod;
			}
		}
	}

	printf("%lld\n",ans);
	return 0;
};