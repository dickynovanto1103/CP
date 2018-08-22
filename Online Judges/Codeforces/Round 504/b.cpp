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
	ll n,k;
	scanf("%lld %lld",&n,&k);

	ll a = 1, b = k-1;
	ll kiri = 1, kanan = k/2LL, mid;
	ll batasKiri = 0, batasKanan = -1;
	// printf("kiri: %lld kanan: %lld\n",kiri, kanan);
	while(kiri <= kanan){
		mid = (kiri + kanan)/2LL;
		a = mid, b = k-mid;
		if(a >= k){
			kanan = mid-1;
		}
		if(a >= b){
			kanan = mid-1;
		}else{
			if(b > n){
				kiri = mid+1;
			}else{
				batasKiri = mid;
				kanan = mid-1;
			}
		}
	}
	kiri = 1, kanan = k/2LL;

	while(kiri <= kanan){
		mid = (kiri + kanan)/2LL;
		a = mid, b = k-mid;
		if(a >= k){
			kanan = mid-1;
		}
		if(a >= b){
			kanan = mid-1;
		}else{
			if(b > n){
				kiri = mid+1;
			}else{
				batasKanan = mid;
				kiri = mid+1;
			}
		}
	}
	// printf("batasKiri: %lld batasKanan: %lld\n",batasKiri, batasKanan);

	printf("%lld\n",batasKanan - batasKiri + 1LL);
	return 0;
};