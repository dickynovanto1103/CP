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
	ll n,q,i,j;
	scanf("%lld %lld",&n,&q);
	ll tengah = (n*n)/2LL;
	if(n*n % 2LL == 1){
		tengah++;
	}
	while(q--){
		ll x,y;
		scanf("%lld %lld",&x,&y);
		ll sum = x + y;
		ll awal;
		bool isGenap;
		if(sum % 2 == 0){
			isGenap = true;
			awal = 1;
		}else{
			isGenap = false;
			awal = tengah+1;
		}
		ll penambahanMaks = n/2LL;
		ll penambahanMinim = n/2LL;
		if(n%2 == 1){
			penambahanMaks++;
		}
		if(n%2 == 0){
			ll tambahDariAtas = (x-1LL)*penambahanMaks;
			ll tambahSampingKiri = (y)/2LL + (y%2==0 ? 0: 1);
			printf("%lld\n",awal+tambahDariAtas - 1LL + tambahSampingKiri);
		}else{
			ll jumlahGenap = (x-1LL)/2LL;
			ll jumlahGanjil = (x-1LL)/2LL + ((x-1LL)%2 == 1? 1 : 0);
			// printf("jumlahGenap: %lld jumlahGanjil: %lld\n",jumlahGenap, jumlahGanjil);
			ll tambahDariAtas;
			if(isGenap){
				tambahDariAtas = jumlahGenap * (n/2LL) + jumlahGanjil * ((n/2LL) + 1LL);	
			}else{
				tambahDariAtas = jumlahGenap * (n/2LL + 1LL) + jumlahGanjil * ((n/2LL));	
			}
			
			ll tambahSampingKiri = 0;
			if(isGenap){
				if(x%2LL == 1){
					tambahSampingKiri = y/2LL + 1;
				}else{
					tambahSampingKiri = y/2LL;
				}
			}else{
				if(x%2LL == 1){
					tambahSampingKiri = y/2LL;
				}else{
					tambahSampingKiri = y/2LL + 1;
				}
			}
			
			printf("%lld\n",awal + tambahDariAtas - 1LL + tambahSampingKiri);
		}
	}
	return 0;
};