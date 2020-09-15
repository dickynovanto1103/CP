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
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5;
bool isprime[maxn + 3];
ll prime[maxn];

void sieve(int n) {
	isprime[0] = isprime[1] = false;
	for(int i=2;i*i<=n;i++){
		if(isprime[i]){
			for(int j=i*i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

int main(){
	ll n;
	int i,j;
	memset(isprime, true, sizeof isprime);
	scanf("%lld",&n);
	sieve(n);
	int cnt = 0;
	for(i=1;i<=n;i++){
		if(isprime[i]){
			prime[++cnt] = i;
		}
	}
	
	ll ans = 1;
	//divide the prime into several blocks of sqrt...the reason for doing this is that we can periodically check if some number has been deleted / indeed the number is the prime factor
	// we cannot differentiate them if the result of A p is 1

	//also, we don't need to do B operation twice for number  <= sqrt(N), we can save that operation by checking directly to the real number of expected deleted number by doing simulation
	int root = (int)sqrt(cnt);
	// printf("root: %d\n",root);
	bool vis[100001];
	memset(vis, false, sizeof vis);
	int curCnt = n;
	bool foundSmallest = false;
	for(i=1;i<=cnt;i++){
		if(i >= root && ans * prime[i - root + 1] > n){break;} //using this approach, we can be sure that the smallest prime will need to be checked first
		// if(ans * prime[i] > n) {break;} //don't need to further check, this check is wrong since we will potentially skip checking the smallest possible prime factor that cannot be get
		printf("B %lld\n",prime[i]);
		fflush(stdout);
		int numMul;
		scanf("%d",&numMul);

		int banyakMulTanpaX = 0;
		for(j=prime[i];j<=n;j+=prime[i]){
			if(!vis[j]){
				banyakMulTanpaX++;
				vis[j] = true;
				curCnt--;
			}
		}

		if(banyakMulTanpaX != numMul){
			//berarti prime ini adalah faktor prima, cari pangkat berapa langsung dengan tanya A p^k
			ll kali = prime[i];
			for(ll j = prime[i]*prime[i]; j <= n; j *= prime[i]) {
				printf("A %lld\n",j);
				fflush(stdout);
				int ada;
				scanf("%d",&ada);
				if(ada){
					kali = j;
				}else{
					break;
				}
			}
			ans *= kali;
		}

		if((i % root == 0 || i == cnt) && !foundSmallest) {
			//do check with A 1
			printf("A 1\n");
			fflush(stdout);
			int sisaNum;
			scanf("%d",&sisaNum);
			if(sisaNum != curCnt) { //berarti ada faktor prima yang merupakan faktor prima tapi ga kecatch di iterasi sebelumnya
				for(j=i-root+1;j<=i;j++){
					// printf("j: %d\n",j);
					printf("A %lld\n",prime[j]);
					fflush(stdout);
					int adaX;
					scanf("%d",&adaX);
 
					if(adaX){
						ll kali = prime[j];
						for(ll k=prime[j]*prime[j];k <= n; k*=prime[j]){
							printf("A %lld\n",k);
							fflush(stdout);
							int ada;
							scanf("%d",&ada);
							if(ada){
								kali = k;
							}else{
								break;
							}
						}
						ans *= kali;
						foundSmallest = true;
						break; //kenapa dibreak, karena bisa jadi abis cek 2 ^ x ketemu, masih cari 3 kali padahal sudah bs didapet di iterasi sebelumnya
					}
				}
			}
		}
	}

	assert(ans <= n);
	printf("C %lld\n",ans);
	fflush(stdout);
	
	return 0;
};